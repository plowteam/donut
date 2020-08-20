// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <atomic>

namespace Donut
{

template <class T>
class Ref
{
	T* reference;
};





// todo: this is shit
class Reference
{
public:
	Reference() = default;
	virtual ~Reference() = default;

	Reference(const Reference& rhs) = delete;
	Reference& operator=(const Reference& rhs) = delete;

	inline uint32_t AddRef() { return _numRefs++; }

	inline uint32_t Release()
	{
		const uint32_t refs = _numRefs--;
		if (refs == 0)
			delete this;

		return refs;
	}

	uint32_t GetRefCount() const { return static_cast<uint32_t>(_numRefs); }

private:
	std::atomic<uint32_t> _numRefs = 0;
};

// References should be purely pointers: Ref<T>

} // namespace Donut
