// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include "Render/BillboardBatch.h"
#include "Render/Mesh.h"
#include "ResourceManager.h"

#include <string>

namespace Donut
{
class ICompositeModel
{
public:
	virtual const std::vector<std::unique_ptr<P3D::CompositeDrawable>>& GetDrawables() const = 0;
	virtual const std::vector<std::unique_ptr<P3D::Skeleton>>& GetSkeletons() const = 0;
	virtual const std::vector<std::unique_ptr<P3D::Geometry>>& GetMeshes() const = 0;
	virtual const std::vector<std::unique_ptr<P3D::Shader>>& GetShaders() const = 0;
	virtual const std::vector<std::unique_ptr<P3D::Texture>>& GetTextures() const = 0;
};

class CompositeModel_AnimObjectWrapper: public ICompositeModel
{
public:
	CompositeModel_AnimObjectWrapper(const P3D::AnimObjectWrapper& animObjectWrapper): _animObjectWrapper(animObjectWrapper) {}

	const std::vector<std::unique_ptr<P3D::CompositeDrawable>>& GetDrawables() const override
	{
		return _animObjectWrapper.GetCompositeDrawables();
	}
	const std::vector<std::unique_ptr<P3D::Skeleton>>& GetSkeletons() const override
	{
		return _animObjectWrapper.GetSkeletons();
	}
	const std::vector<std::unique_ptr<P3D::Geometry>>& GetMeshes() const override { return _animObjectWrapper.GetGeometries(); }
	const std::vector<std::unique_ptr<P3D::Shader>>& GetShaders() const override { return _shaders; }
	const std::vector<std::unique_ptr<P3D::Texture>>& GetTextures() const override { return _textures; }

private:
	const P3D::AnimObjectWrapper& _animObjectWrapper;
	std::vector<std::unique_ptr<P3D::Shader>> _shaders;
	std::vector<std::unique_ptr<P3D::Texture>> _textures;
};

class CompositeModel_Chunk: public ICompositeModel
{
public:
	CompositeModel_Chunk(const P3D::P3DChunk&);

	const std::vector<std::unique_ptr<P3D::CompositeDrawable>>& GetDrawables() const override { return _drawables; }
	const std::vector<std::unique_ptr<P3D::Skeleton>>& GetSkeletons() const override { return _skeletons; }
	const std::vector<std::unique_ptr<P3D::Geometry>>& GetMeshes() const override { return _meshes; }
	const std::vector<std::unique_ptr<P3D::Shader>>& GetShaders() const override { return _shaders; }
	const std::vector<std::unique_ptr<P3D::Texture>>& GetTextures() const override { return _textures; }

private:
	std::vector<std::unique_ptr<P3D::CompositeDrawable>> _drawables;
	std::vector<std::unique_ptr<P3D::Skeleton>> _skeletons;
	std::vector<std::unique_ptr<P3D::Geometry>> _meshes;
	std::vector<std::unique_ptr<P3D::BillboardQuadGroup>> _quadGroups;
	std::vector<std::unique_ptr<P3D::Shader>> _shaders;
	std::vector<std::unique_ptr<P3D::Texture>> _textures;
};

class CompositeModel
{
public:
	CompositeModel(const ICompositeModel&);

	static std::unique_ptr<CompositeModel> LoadP3D(const std::string&);

	void Draw(GL::ShaderProgram&, const Matrix4x4&, const Matrix4x4&, bool);

	void SetTransform(const Matrix4x4& transform) { _transform = transform; }
	const Matrix4x4& GetTransform() const { return _transform; }

private:
	struct DrawableProp
	{
		size_t meshIndex;
		Matrix4x4 transform;
	};

	Matrix4x4 _transform;
	std::vector<std::unique_ptr<Mesh>> _meshes;
	std::vector<std::unique_ptr<BillboardBatch>> _billboards;
	std::vector<DrawableProp> _props;
};

/*
CompositeDrawable represents a sorted list of skins, props and effects linked to a Skeleton.
Skins reference Skin,
Props are reference to Mesh or Billboard and have a skeleton joit indentifier, Effects?
*/
class CompositeDrawable
{
public:
	CompositeDrawable(const P3D::CompositeDrawable&);

private:
	// props:
	std::vector<std::shared_ptr<Mesh>> _meshes;
	std::vector<std::shared_ptr<BillboardBatch>> _billboards;
};
} // namespace Donut
