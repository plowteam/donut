#pragma once

#include <P3D/P3DChunk.h>
#include <P3D/Mesh.h>
#include <P3D/InstanceList.h>

namespace Donut::P3D
{
	class InstancedStaticPhys
	{
	public:

		InstancedStaticPhys(
			const std::string& name,
			std::vector<std::unique_ptr<Mesh>> meshes,
			std::unique_ptr<InstanceList> instanceList) :
			_name(name),
			_meshes(std::move(meshes)),
			_instanceList(std::move(instanceList))
		{
		}

		static std::unique_ptr<InstancedStaticPhys> Load(const P3DChunk&);

		void GetDrawables(std::vector<std::unique_ptr<SceneGraphDrawable>>& drawables)
		{
			_instanceList->GetDrawables(drawables);
		}

		Mesh* GetMesh(const std::string& name)
		{
			for (auto& mesh : _meshes)
			{
				if (mesh->GetName() != name) continue;
				return mesh.get();
			}

			return nullptr;
		}

		const std::string& GetName() const { return _name; }

	private:

		std::string _name;
		std::vector<std::unique_ptr<Mesh>> _meshes;
		std::unique_ptr<InstanceList> _instanceList;
	};
} // namespace Donut::P3D
