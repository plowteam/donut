#pragma once

#include <ResourceManager.h>
#include <SkinModel.h>
#include <Level.h>
#include <memory>

namespace Donut
{

class Window;

class Game
{
  public:
	Game(int argc, char** argv);
	~Game();

	Window& GetWindow() const
	{
		return *_window;
	}

	void Run();
	void LoadModel(const std::string&, const std::string&);

	ResourceManager& GetResourceManager() { return *_resourceManager; }

  private:
	void loadGlobal();
	void debugDrawP3D(const P3D::P3DFile&);

	std::unique_ptr<Window> _window;
	std::unique_ptr<ResourceManager> _resourceManager;
	std::unique_ptr<SkinModel> _skinModel;
	std::unique_ptr<Level> _level;
	std::unique_ptr<P3D::P3DFile> _animP3D;
	std::unique_ptr<P3D::P3DFile> _globalP3D;

	glm::vec3 _lookAt;
	glm::vec3 _camPos;
};

} // namespace Donut
