// Copyright 2019-2020 the donut authors. See AUTHORS.md

#pragma once

#include <memory>
#include <string>
#include <vector>

namespace Donut
{

class Window;
class AudioManager;
class ResourceManager;
class LineRenderer;
class FreeCamera;

namespace GL
{
class ShaderProgram;
}

class Game
{
public:
	Game(int argc, char** argv);
	~Game();

	Window& GetWindow() const { return *_window; }

	void Run();

	AudioManager& GetAudioManager() { return *_audioManager; }
	ResourceManager& GetResourceManager() { return *_resourceManager; }
	LineRenderer& GetLineRenderer() { return *_lineRenderer; }

	void InitializePure3D();

	void LoadP3D(const std::string& filename);

	void LockMouse(bool lockMouse);

	static Game& GetInstance() { return *instance; }

private:
	void imguiMenuBar();
	void OnInputTextEntry(const std::string& text);

	void debugAboutMenu();

	std::unique_ptr<Window> _window;
	std::unique_ptr<AudioManager> _audioManager;
	std::unique_ptr<ResourceManager> _resourceManager;
	std::unique_ptr<FreeCamera> _camera;
	std::unique_ptr<LineRenderer> _lineRenderer;

	std::unique_ptr<GL::ShaderProgram> _skinShaderProgram;

	bool _mouseLocked;
	int _lockedMousePosX;
	int _lockedMousePosY;

	bool _debugResourceManagerWindowOpen = false;
	bool _debugAudioWindowOpen = false;
	bool _debugAboutWindowOpen = false;

	static Game* instance;
};

} // namespace Donut
