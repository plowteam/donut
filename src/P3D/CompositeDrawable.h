#pragma once

#include <P3D/P3DChunk.h>

namespace Donut::P3D
{
	class CompositeDrawableProp
	{
	public:

		CompositeDrawableProp(const std::string& name, uint32_t skeletonJoint) :
			_name(name),
			_skeletonJoint(skeletonJoint)
		{
		}

		static std::unique_ptr<CompositeDrawableProp> Load(const P3DChunk&);

		const std::string& GetName() const { return _name; }
		uint32_t GetSkeletonJoint() const { return _skeletonJoint; }

	private:

		std::string _name;
		uint32_t _skeletonJoint;
	};

	class CompositeDrawablePropList
	{
	public:

		using Props = std::vector<std::unique_ptr<CompositeDrawableProp>>;

		CompositeDrawablePropList(Props props) :
			_props(std::move(props))
		{
		}

		static std::unique_ptr<CompositeDrawablePropList> Load(const P3DChunk&);

		const Props& GetProps() const { return _props; }

	private:

		Props _props;
	};

	class CompositeDrawable
	{
	public:

		CompositeDrawable(
			const std::string& name,
			const std::string& skeletonName,
			std::unique_ptr<CompositeDrawablePropList> propList) :
			_name(name),
			_skeletonName(skeletonName),
			_propList(std::move(propList))
		{
		}

		static std::unique_ptr<CompositeDrawable> Load(const P3DChunk&);

		const std::string& GetName() const { return _name; }
		const std::string& GetSkeletonName() const { return _skeletonName; }
		const CompositeDrawablePropList::Props& GetProps() const { return _propList->GetProps(); }

	private:

		std::string _name;
		std::string _skeletonName;
		std::unique_ptr<CompositeDrawablePropList> _propList;
	};
} // namespace Donut::P3D
