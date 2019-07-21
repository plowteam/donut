#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/SceneGraphTransform.h>

namespace Donut::P3D
{
	class SceneGraphBranch
	{
	public:

		SceneGraphBranch(
			const std::string& name,
			std::vector<std::unique_ptr<SceneGraphTransform>> children) :
			_name(name),
			_children(std::move(children))
		{
		}

		static std::unique_ptr<SceneGraphBranch> Load(const P3DChunk&);

	private:

		std::vector<std::unique_ptr<SceneGraphTransform>> _children;
		std::string _name;
	};

	class SceneGraphRoot
	{
	public:

		SceneGraphRoot(std::unique_ptr<SceneGraphBranch> branch) :
			_branch(std::move(branch))
		{
		}

		static std::unique_ptr<SceneGraphRoot> Load(const P3DChunk&);

	private:

		std::unique_ptr<SceneGraphBranch> _branch;
	};

	class SceneGraph
	{
	public:

		SceneGraph(std::unique_ptr<SceneGraphRoot> root) :
			_root(std::move(root))
		{
		}

		static std::unique_ptr<SceneGraph> Load(const P3DChunk&);

	private:

		std::unique_ptr<SceneGraphRoot> _root;
	};
} // namespace Donut::P3D
