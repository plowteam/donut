// Copyright 2019-2021 the donut authors. See COPYING.md for legal info.

#pragma once

#include <cstddef>
#include <memory>
#include <string>
#include <unordered_map>

namespace Donut
{

template<typename Resource>
struct ResourceStore {
	ResourceStore() = default;
	ResourceStore(ResourceStore&&) = default;
	ResourceStore & operator=(ResourceStore &&) = default;

	std::size_t size() const {
		return resources.size();
	}

	bool empty() const {
		return resources.empty();
	}

	void clear() {
		resources.clear();
	}




	bool contains(const std::string_view id) const {
		return (resources.find(id) != resources.cend());
	}

private:
	// possibly use std::size_t as key, but I think this hash maps?
	std::unordered_map<std::string, std::shared_ptr<Resource>> resources;
};

} // namespace Donut
