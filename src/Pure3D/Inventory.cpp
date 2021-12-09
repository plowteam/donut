// Copyright 2019-2021 the donut authors. See COPYING.md for legal info.

#include "Inventory.h"

#include <type_traits>

namespace donut::p3d
{

Inventory::Inventory()
{
	// AddSection("default");
	// _sections.at()
}

void Inventory::Store(std::shared_ptr<Entity> entity)
{
	// Check for a collision first
	std::shared_ptr<Entity> otherEntity = Get<Entity>(entity->GetName());
	if (otherEntity != nullptr)
	{
		// collision assert
		return;
	}

	// Store it (TODO: store in sections)
	_store[entity->GetName()] = entity;
}

template<typename T>
std::shared_ptr<T> Inventory::Get(const std::string& name) const
{
	static_assert(std::is_base_of<Entity, T>::value, "T must be a descendant of Entity");

	return _store[name];

	// return nullptr;
	// return std::shared_ptr<T>();
}

} // namespace Donut
