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
class Level;
class WorldPhysics;
class FreeCamera;
class Character;

namespace P3D
{
class P3DFile;
class TextureFont;
} // namespace P3D

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
	void LoadModel(const std::string&, const std::string&);

	AudioManager& GetAudioManager() { return *_audioManager; }
	ResourceManager& GetResourceManager() { return *_resourceManager; }
	WorldPhysics& GetWorldPhysics() { return *_worldPhysics; }
	LineRenderer& GetLineRenderer() { return *_lineRenderer; }

	void LockMouse(bool lockMouse);

	static Game& GetInstance() { return *instance; }

private:
	void imguiMenuBar();
	void guiModelMenu(Character&);
	void loadGlobal();
	void debugDrawP3D(const P3D::P3DFile&);
	void OnInputTextEntry(const std::string& text);

	void debugAboutMenu();

	std::unique_ptr<Window> _window;
	std::unique_ptr<AudioManager> _audioManager;
	std::unique_ptr<ResourceManager> _resourceManager;
	std::unique_ptr<FreeCamera> _camera;
	std::unique_ptr<Character> _character;
	std::unique_ptr<LineRenderer> _lineRenderer;
	std::unique_ptr<Level> _level;
	std::unique_ptr<WorldPhysics> _worldPhysics;
	std::unique_ptr<P3D::P3DFile> _animP3D;
	std::unique_ptr<P3D::P3DFile> _globalP3D;
	std::unique_ptr<P3D::TextureFont> _textureFontP3D;

	std::unique_ptr<Character> _npcCharacter;

	std::unique_ptr<GL::ShaderProgram> _skinShaderProgram;

	bool _mouseLocked;
	int _lockedMousePosX;
	int _lockedMousePosY;

	bool _debugResourceManagerWindowOpen = false;
	bool _debugLevelWindowOpen = false;
	bool _debugAudioWindowOpen = false;
	bool _debugAboutWindowOpen = false;
	
	static Game* instance;
};

} // namespace Donut
