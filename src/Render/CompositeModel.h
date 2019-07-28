#pragma once

#include <Render/Mesh.h>
#include <ResourceManager.h>
#include <string>
#include <glm/mat4x4.hpp>

namespace Donut
{
	class ICompositeModel
	{
	public:

		virtual const std::vector<std::unique_ptr<P3D::CompositeDrawable>>& GetDrawables() const = 0;
		virtual const std::vector<std::unique_ptr<P3D::Skeleton>>& GetSkeletons() const = 0;
		virtual const std::vector<std::unique_ptr<P3D::Mesh>>& GetMeshes() const = 0;
		virtual const std::vector<std::unique_ptr<P3D::Shader>>& GetShaders() const = 0;
		virtual const std::vector<std::unique_ptr<P3D::Texture>>& GetTextures() const = 0;
	};

	class CompositeModel_AnimObjectWrapper : public ICompositeModel
	{
	public:

		CompositeModel_AnimObjectWrapper(const P3D::AnimObjectWrapper& animObjectWrapper) : _animObjectWrapper(animObjectWrapper) {}

		virtual const std::vector<std::unique_ptr<P3D::CompositeDrawable>>& GetDrawables() const override { return _animObjectWrapper.GetCompositeDrawables(); }
		virtual const std::vector<std::unique_ptr<P3D::Skeleton>>& GetSkeletons() const override { return _animObjectWrapper.GetSkeletons(); }
		virtual const std::vector<std::unique_ptr<P3D::Mesh>>& GetMeshes() const override { return _animObjectWrapper.GetMeshes(); }
		virtual const std::vector<std::unique_ptr<P3D::Shader>>& GetShaders() const override { return _shaders; }
		virtual const std::vector<std::unique_ptr<P3D::Texture>>& GetTextures() const override { return _textures; }

	private:

		const P3D::AnimObjectWrapper& _animObjectWrapper;
		std::vector<std::unique_ptr<P3D::Shader>> _shaders;
		std::vector<std::unique_ptr<P3D::Texture>> _textures;
	};

	class CompositeModel_Chunk : public ICompositeModel
	{
	public:

		CompositeModel_Chunk(const P3D::P3DChunk&);

		virtual const std::vector<std::unique_ptr<P3D::CompositeDrawable>>& GetDrawables() const override { return _drawables; }
		virtual const std::vector<std::unique_ptr<P3D::Skeleton>>& GetSkeletons() const override { return _skeletons; }
		virtual const std::vector<std::unique_ptr<P3D::Mesh>>& GetMeshes() const override { return _meshes; }
		virtual const std::vector<std::unique_ptr<P3D::Shader>>& GetShaders() const override { return _shaders; }
		virtual const std::vector<std::unique_ptr<P3D::Texture>>& GetTextures() const override { return _textures; }

	private:

		std::vector<std::unique_ptr<P3D::CompositeDrawable>> _drawables;
		std::vector<std::unique_ptr<P3D::Skeleton>> _skeletons;
		std::vector<std::unique_ptr<P3D::Mesh>> _meshes;
		std::vector<std::unique_ptr<P3D::Shader>> _shaders;
		std::vector<std::unique_ptr<P3D::Texture>> _textures;
	};

	class CompositeModel
	{
	public:

		CompositeModel(const ICompositeModel&, const std::unique_ptr<ResourceManager>&);

		static std::unique_ptr<CompositeModel> LoadP3D(const std::string&, const std::unique_ptr<ResourceManager>&);

		void Draw(GL::ShaderProgram&, const glm::mat4&, const glm::mat4&);

		void SetTransform(const glm::mat4& transform) { _transform = transform; }
		const glm::mat4& GetTransform() const { return _transform; }

	private:

		struct DrawableProp
		{
			size_t meshIndex;
			glm::mat4 transform;
		};

		glm::mat4 _transform;
		std::vector<std::unique_ptr<Mesh>> _meshes;
		std::vector<DrawableProp> _props;
		const std::unique_ptr<ResourceManager>& _resourceManager;
	};
} // namespace Donut
