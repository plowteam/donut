#pragma once

#include <memory>
#include <string>

namespace Donut
{

class Window;
class ResourceManager;
class LineRenderer;
class SkinModel;
class Level;
class WorldPhysics;
class FreeCamera;

namespace P3D
{
class P3DFile;
class TextureFont;
}

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

	void LockMouse(bool lockMouse);

  private:
	void guiTeleportMenu();
	void guiModelMenu();
	void loadGlobal();
	void debugDrawP3D(const P3D::P3DFile&);

	std::unique_ptr<Window> _window;
	std::unique_ptr<ResourceManager> _resourceManager;
	std::unique_ptr<FreeCamera> _camera;
	std::unique_ptr<SkinModel> _skinModel;
	std::unique_ptr<LineRenderer> _lineRenderer;
	std::unique_ptr<Level> _level;
	std::unique_ptr<WorldPhysics> _worldPhysics;
	std::unique_ptr<P3D::P3DFile> _animP3D;
	std::unique_ptr<P3D::P3DFile> _globalP3D;
	std::unique_ptr<P3D::TextureFont> _textureFontP3D;

	bool _mouseLocked;
	int _lockedMousePosX;
	int _lockedMousePosY;
};

} // namespace Donut
