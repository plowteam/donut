// Copyright 2019 the donut authors. See AUTHORS.md

#include "BillboardBatch.h"
#include <Render/OpenGL/VertexBuffer.h>
#include <Render/OpenGL/IndexBuffer.h>
#include <Render/OpenGL/VertexBinding.h>
#include <Render/OpenGL/ShaderProgram.h>
#include <P3D/p3d.generated.h>
#include <Game.h>
#include <ResourceManager.h>
#include <glm/glm.hpp>

namespace Donut
{
	static glm::vec4 ConvertColor(uint32_t v)
	{
		return glm::vec4(((v >> 16) & 255) / 255.0f,
			((v >> 8) & 255) / 255.0f,
			((v & 255)) / 255.0f,
			((v >> 24) & 255) / 255.0f);
	}

	struct Vertex
	{
		glm::vec3 pos;
		glm::vec2 uv;
		glm::vec4 color;
	};

	BillboardBatch::BillboardBatch(const P3D::BillboardQuadGroup& billboardQuadGroup)
	{
		static const size_t vertStride = sizeof(Vertex);

		std::vector<Vertex> vertices;
		std::vector<uint32_t> indices;

		auto numQuads = billboardQuadGroup.GetQuadCount();
		_numIndices = numQuads * 6;

		vertices.reserve(numQuads * 4);
		indices.reserve(numQuads * 6);

		glm::vec3 quadVertices[4] =
		{
			glm::vec3(0.5, 0.5, 0),
			glm::vec3(-0.5, 0.5, 0),
			glm::vec3(-0.5, -0.5, 0),
			glm::vec3(0.5, -0.5, 0),
		};

		uint32_t indexOffset = 0;

		for (auto const& billboardQuad : billboardQuadGroup.GetQuads())
		{
			auto color = billboardQuad->GetColor();
			const auto& translation = billboardQuad->GetTranslation();
			const auto& rotation = billboardQuad->GetDisplayInfo()->GetRotation();
			auto width = billboardQuad->GetWidth();
			auto height = billboardQuad->GetHeight();
			
			glm::vec2 quadUVs[4] =
			{
				billboardQuad->GetUv0(),
				billboardQuad->GetUv1(),
				billboardQuad->GetUv2(),
				billboardQuad->GetUv3(),
			};

			for (size_t i = 0; i < 4; ++i)
			{
				vertices.push_back(Vertex
				{
					translation + (quadVertices[i] * glm::vec3(width, height, 1.0f)),
					quadUVs[i],
					ConvertColor(color),
				});
			}

			indices.push_back(indexOffset + 0);
			indices.push_back(indexOffset + 1);
			indices.push_back(indexOffset + 2);
			indices.push_back(indexOffset + 2);
			indices.push_back(indexOffset + 3);
			indices.push_back(indexOffset + 0);

			indexOffset += 4;
		}

		_vertexBuffer = std::make_shared<GL::VertexBuffer>(vertices.data(), vertices.size(), vertStride);
		_indexBuffer = std::make_shared<GL::IndexBuffer>(indices.data(), indices.size(), GL_UNSIGNED_INT);

		GL::ArrayElement vertexLayout[] =
		{
			GL::ArrayElement(_vertexBuffer.get(), 0, 3, GL::AE_FLOAT, vertStride, 0),
			GL::ArrayElement(_vertexBuffer.get(), 1, 2, GL::AE_FLOAT, vertStride, 3 * sizeof(float)),
			GL::ArrayElement(_vertexBuffer.get(), 2, 4, GL::AE_FLOAT, vertStride, 5 * sizeof(float)),
		};

		_vertexBinding = std::make_shared<GL::VertexBinding>();
		_vertexBinding->Create(vertexLayout, 3, *_indexBuffer, GL::ElementType::AE_UINT);

		_shader = Game::GetInstance().GetResourceManager().GetShader(billboardQuadGroup.GetShader());
		_zTest = billboardQuadGroup.GetZTest() == 1;
		_zWrite = billboardQuadGroup.GetZWrite() == 1;
	}

	void BillboardBatch::Draw(GL::ShaderProgram& shader, bool opaque)
	{
		bool trans = (!_shader->IsAlphaTested() && _shader->IsTranslucent());

		if (trans && opaque)
		{
			return;
		}

		if (!trans && !opaque)
		{
			return;
		}

		if (!opaque)
		{
			auto blendMode = _shader->GetBlendMode();

			if (blendMode == BlendMode::Alpha)
			{
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
			}
			else if (blendMode == BlendMode::Additive)
			{
				glBlendFunc(GL_ONE, GL_ONE);
			}
		}

		if (_zTest)
		{
			glEnable(GL_DEPTH_TEST);
		}
		else
		{
			glDisable(GL_DEPTH_TEST);
		}

		glDepthMask(_zWrite ? GL_TRUE : GL_FALSE);

		shader.SetUniformValue("alphaMask", _shader->IsAlphaTested() ? 0.5f : 0.0f);

		_vertexBinding->Bind();
		_shader->Bind(0);
		glDrawElements(GL_TRIANGLES, _numIndices, GL_UNSIGNED_INT, 0);
		_vertexBinding->Unbind();

		glEnable(GL_DEPTH_TEST);
		glDepthMask(GL_TRUE);
	}
}
