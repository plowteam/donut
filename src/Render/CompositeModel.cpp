#include <Render/CompositeModel.h>
#include <P3D/P3DFile.h>
#include <P3D/CompositeDrawable.h>
#include <P3D/Skeleton.h>
#include <P3D/Mesh.h>
#include <P3D/Texture.h>
#include <P3D/Shader.h>
#include <iostream>

namespace Donut
{
	CompositeModel::CompositeModel()
	{
		_resourceManager = std::make_unique<ResourceManager>();
	}

	void CompositeModel::LoadP3D(const std::string& filename)
	{
		if (!std::filesystem::exists(filename))
		{
			std::cout << "CompositeDrawable not found: " << filename << "\n";
			return;
		}

		std::cout << "Loading CompositeDrawable: " << filename << "\n";

		std::vector<std::shared_ptr<P3D::CompositeDrawable>> drawables;
		std::map<std::string, std::shared_ptr<P3D::Skeleton>> skeletons;
		std::map<std::string, std::shared_ptr<P3D::Mesh>> meshes;
		std::map<std::string, std::vector<glm::mat4>> jointTransforms;

		const auto p3d = P3D::P3DFile(filename);
		const auto& root = p3d.GetRoot();
		for (const auto& chunk : root.GetChildren())
		{
			switch (chunk->GetType())
			{
				case P3D::ChunkType::CompositeDrawable:
				{
					drawables.push_back(P3D::CompositeDrawable::Load(*chunk));
					break;
				}
				case P3D::ChunkType::Skeleton:
				{
					auto skeleton = P3D::Skeleton::Load(*chunk);
					const auto& skeletonJoints = skeleton->GetJoints();

					std::vector<glm::mat4> transforms;
					for (const auto& joint : skeletonJoints)
					{
						transforms.push_back(transforms.empty() ? glm::mat4(1.0f) : transforms[joint->GetParent()] * joint->GetRestPose());
					}

					const auto& skeletonName = skeleton->GetName();
					jointTransforms.insert({ skeletonName, std::move(transforms) });
					skeletons.insert({ skeletonName, std::move(skeleton) });

					break;
				}
				case P3D::ChunkType::Mesh:
				{
					auto mesh = P3D::Mesh::Load(*chunk);
					meshes.insert({ mesh->GetName(), std::move(mesh) });
					break;
				}
				case P3D::ChunkType::Shader:
				{
					auto shader = P3D::Shader::Load(*chunk);
					const std::string shader_name = shader->GetName();
					_resourceManager->AddShader(shader_name, std::move(shader));
					break;
				}
				case P3D::ChunkType::Texture:
				{
					auto texture = P3D::Texture::Load(*chunk);
					auto texdata = texture->GetData();

					std::unique_ptr<GL::Texture2D> tex;
					if (texdata.comp == 4)
						tex = std::make_unique<GL::Texture2D>(texdata.width, texdata.height, GL_RGBA, GL_RGBA, GL_UNSIGNED_BYTE, texdata.data.data());
					else
						tex = std::make_unique<GL::Texture2D>(texdata.width, texdata.height, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, texdata.data.data());

					_resourceManager->AddTexture(texture->GetName(), std::move(tex));

					break;
				}
				default: break;
			}
		}

		std::map<std::string, size_t> meshNames;

		for (const auto& mesh : meshes)
		{
			meshNames.insert({ mesh.first, _meshes.size() });
			_meshes.push_back(std::make_unique<Mesh>(*mesh.second));
		}

		for (const auto& drawable : drawables)
		{
			const auto& transforms = jointTransforms[drawable->GetSkeletonName()];
			const auto& props = drawable->GetProps();
			for (const auto& prop : props)
			{
				const auto& propName = prop->GetName();
				if (meshNames.find(propName) == meshNames.end()) continue;

				const auto& transform = transforms[prop->GetSkeletonJoint()];
				_props.push_back(DrawableProp { meshNames[prop->GetName()], transform });
			}
		}
	}

	void CompositeModel::Draw(GL::ShaderProgram& shader, const glm::mat4& viewProj, const glm::mat4& modelMatrix)
	{
		for (const auto& prop : _props)
		{
			shader.SetUniformValue("viewProj", viewProj *  prop.transform * modelMatrix);
			_meshes[prop.meshIndex]->Draw(*_resourceManager);
		}
	}
} // namespace Donut
