#pragma once

#include <P3D/AnimationGroup.h>
#include <P3D/P3DChunk.h>
#include <memory>

namespace Donut::P3D
{

class AnimationGroupList
{
  public:
	AnimationGroupList(std::vector<std::unique_ptr<AnimationGroup>> groups):
	    _groups(std::move(groups)) {}

	static std::unique_ptr<AnimationGroupList> Load(const P3DChunk&);

	const AnimationGroup* GetGroup(const std::string& name) const
	{
		for (const auto& group : _groups)
		{
			if (group->GetName() == name) return group.get();
		}
		return nullptr;
	}

  private:
	std::vector<std::unique_ptr<AnimationGroup>> _groups;
};

} // namespace Donut::P3D
