// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <P3D/P3D.generated.h>
#include <Render/BillboardBatch.h>
#include <Render/CompositeModel.h>
#include <Render/Mesh.h>
#include <ResourceManager.h>
#include <Skeleton.h>
#include <string>
#include <vector>

namespace Donut
{

// class Skeleton;

class WorldSphere
{
	struct Prop
	{
		int skeleton_joint;
		bool translucent;
		std::unique_ptr<Mesh> mesh;

		Prop(std::unique_ptr<Mesh> pMesh, int pJoint): mesh(std::move(pMesh)), skeleton_joint(pJoint) {}
	};

public:
	WorldSphere(const P3D::WorldSphere&);

	void Draw(GL::ShaderProgram&, const Matrix4x4& viewProj, bool opaque) const;
	void Update(double deltatime);

private:
	std::string _name;
	std::vector<std::unique_ptr<BillboardBatch>> _billboardBatches;
	std::vector<Prop> _props;
	std::unique_ptr<CompositeModel> _compositeModel;

	std::unique_ptr<Skeleton> _skeleton;
	std::unique_ptr<SkinAnimation> _animation;

	double _animTime;
};

} // namespace Donut
