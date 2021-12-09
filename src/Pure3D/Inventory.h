// Copyright 2019-2021 the donut authors. See COPYING.md for legal info.

#pragma once

#include <cstddef>
#include <memory>
#include <stack>
#include <string>
#include <unordered_map>

#include "Entity.h"

namespace donut::p3d
{

/*
 * Inventory is a hashmap store of Pure3D Resources split into sections.
 * It is responsible for managing the lifetime of resources. (?)
 * The lifetime of a Resource is determined by the section it's loaded in.
 *
 * There is a "Default" section which remains for the entire game lifecycle,
 * examples of resources loaded into Default include:
 * - mouse_cursor.p3d
 *
 * Other examples of sections
 * ScroobyBootup:
 * - licensePC.p3d
 * - bootup.p3d
 *
 * When loading characters, each character is loaded into a section.
 * When loading maps, each map is loaded into a section of that name and load-
 * zones use these names to load/unload dynamically.
 *
 * Design ideas:
 * - Vademecum: Inventory stores, views and groups to iterate.
 * - Pools: pools of entities are made available through a specialized version of a sparse set.
            each pool contains all the instances of a single entity type.
 *
 * auto view = inventory.view<Texture>();
 * Observers:
 * - inventory.on_construct<Texture>().connect<&my_class::member>(instance);
 *
 *
 * Inventory.Find<tDrawable>("id");
 * 
 */
class Inventory {
	using id_type = std::string;
	using val_type = std::shared_ptr<void*>;
	using section_type = std::unordered_map<id_type, val_type>;

public:
	Inventory();
	Inventory(Inventory&&) = default;
	Inventory& operator=(Inventory&&) = default;

	// Entity management
	void Store(std::shared_ptr<Entity> entity);

	template<typename T>
	std::shared_ptr<T> Get(const std::string& name) const;

	// Section Management
	void CreateSection(const std::string& name);
	void DeleteSection(const std::string& name);
	void SelectSection(const std::string& name);
	section_type GetCurrentSection();
	section_type GetSection(const std::string& name);

	// Push the current section onto the stack to pop later.
	void PushSection();
	// Pop the section from the stack and make it the current section.
	void PopSection();


	/*template<typename... Type>
	[[nodiscard]] view<void*, Type...> View() const {
		static_assert(sizeof...(Type) > 0, "View must use at least one component");
	};*/

protected:
	std::unordered_map<id_type, std::shared_ptr<Entity>> _store;

	// std::unordered_map<id_type, val_type> _defaultSection;
	// std::unordered_map<std::string, std::unordered_map<id_type, val_type>> _sections;
	// std::stack<std::string> _sectionStack;
	// std::string _activeSection; // std::size_t?
};

} // namespace Donut
