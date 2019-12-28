// Copyright 2019 the donut authors. See AUTHORS.md

#include <Game.h>
#include <P3D/P3D.generated.h>
#include <Render/Shader.h>
#include <Render/SkinModel.h>

namespace Donut
{

void SkinModel::LoadPolySkin(const P3D::PolySkin& polySkin)
{
	// todo: reset the _vertexBuffer & _indexBuffer

	std::vector<Vertex> vertices;
	std::vector<uint32_t> indices;
	std::size_t vertOffset = 0, idxOffset = 0;

	for (auto const& prim : polySkin.GetPrimitiveGroups())
	{
		const auto primVerts         = prim->GetVertices();
		const auto primUV            = prim->GetUvs(0);
		const auto primNormals       = prim->GetNormals();
		const auto primIndices       = prim->GetIndices();
		const auto primWeights       = prim->GetWeightList();
		const auto primMatrixList    = prim->GetMatrixList();
		const auto primMatrixPalette = prim->GetMatrixPalette();

		// todo: there are flags on P3D::PrimGroup to determine this:
		const bool primHasBoneIndices = !primMatrixList.empty() && !primMatrixPalette.empty();
		const bool primHasWeights     = !primWeights.empty();

		for (uint32_t i = 0; i < primVerts.size(); i++)
		{
			auto boneIndices = Vector3Int::Zero;

			if (primHasBoneIndices)
			{
				const auto m = primMatrixList[i];
				auto i0      = (m >> 24) & 0xFF;
				auto i1      = (m >> 16) & 0xFF;
				auto i2      = (m >> 8) & 0xFF;
				auto i3      = m & 0xFF;

				boneIndices = Vector3Int(
				    primMatrixPalette[i0],
				    primMatrixPalette[i1],
				    primMatrixPalette[i2]);
			}

			const auto weight = primHasWeights ? primWeights[i] : Vector3(1, 0, 0);
			const auto uv     = Vector2(primUV[i].X, 1.0f - primUV[i].Y); // turn that frown upside down :)

			vertices.emplace_back(primVerts[i], primNormals[i], uv, weight, boneIndices);
		}

		// copy over indices and offset by the prim groups vertices
		for (auto idx : primIndices)
			indices.emplace_back(idx + static_cast<uint32_t>(vertOffset));

		GLenum mode = GL_TRIANGLE_STRIP;
		switch ((P3D::PrimitiveType)prim->GetPrimType())
		{
		case P3D::PrimitiveType::TriangleStrip: mode = GL_TRIANGLE_STRIP; break;
		case P3D::PrimitiveType::TriangleList: mode = GL_TRIANGLES; break;
		case P3D::PrimitiveType::LineStrip: mode = GL_LINE_STRIP; break;
		case P3D::PrimitiveType::LineList: mode = GL_LINES; break;
		}
		_primGroups.emplace_back(mode, prim->GetShaderName(), idxOffset, primIndices.size());

		vertOffset += primVerts.size();
		idxOffset += primIndices.size();
	}

	_vertexBuffer = std::make_unique<GL::VertexBuffer>(vertices.data(), vertices.size(), sizeof(Vertex));
	_indexBuffer  = std::make_unique<GL::IndexBuffer>(indices.data(), indices.size(), GL_UNSIGNED_INT);

	GL::ArrayElement vertexLayout[] = {
		GL::ArrayElement(_vertexBuffer.get(), 0, 3, GL::AE_FLOAT, sizeof(Vertex), offsetof(Vertex, pos)),
		GL::ArrayElement(_vertexBuffer.get(), 1, 3, GL::AE_FLOAT, sizeof(Vertex), offsetof(Vertex, normal)),
		GL::ArrayElement(_vertexBuffer.get(), 2, 2, GL::AE_FLOAT, sizeof(Vertex), offsetof(Vertex, uv)),
		GL::ArrayElement(_vertexBuffer.get(), 3, 3, GL::AE_FLOAT, sizeof(Vertex), offsetof(Vertex, boneWeights)),
		GL::ArrayElement(_vertexBuffer.get(), 4, 3, GL::AE_INT, sizeof(Vertex), offsetof(Vertex, boneIndices)),
	};

	_vertexBinding = std::make_unique<GL::VertexBinding>();
	_vertexBinding->Create(vertexLayout, 5, *_indexBuffer, GL::AE_UINT);
}

void SkinModel::Draw()
{
	_vertexBinding->Bind();

	glActiveTexture(GL_TEXTURE0);
	for (auto const& primGroup : _primGroups)
	{
		auto const& shader = Game::GetInstance().GetResourceManager().GetShader(primGroup.shaderName);
		shader->Bind(0);

		glDrawElements(primGroup.mode, primGroup.indicesCount, _indexBuffer->GetType(), reinterpret_cast<const void*>(primGroup.indicesOffset * 4));
	}

	_vertexBinding->Unbind();
}

} // namespace Donut
