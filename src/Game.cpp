// Copyright 2019 the donut authors. See AUTHORS.md

#include "Game.h"

#include "AnimCamera.h"
#include "Character.h"
#include "Core/Math/Math.h"
#include "Core/FpsTimer.h"
#include "FreeCamera.h"
#include "FrontendProject.h"
#include "Input/Input.h"
#include "Level.h"
#include "P3D/P3D.generated.h"
#include "P3D/P3DFile.h"
#include "Physics/WorldPhysics.h"
#include "RCL/RCFFile.h"
#include "RCL/RSDFile.h"
#include "Render/imgui/imgui.h"
#include "Render/imgui/imgui_impl_opengl3.h"
#include "Render/imgui/imgui_impl_sdl.h"
#include "Render/OpenGL/FrameBuffer.h"
#include "Render/OpenGL/ShaderProgram.h"
#include "Render/OpenGL/glad/glad.h"
#include "Render/Font.h"
#include "Render/LineRenderer.h"
#include "Render/Shader.h"
#include "Render/SkinModel.h"
#include "Render/SpriteBatch.h"
#include "ResourceManager.h"
#include "Scripting/Commands.h"
#include "Window.h"

#include <AL/al.h>
#include <AL/alc.h>
#include <AL/alext.h>
#include <AL/efx.h>
#include <fmt/format.h>
#include <SDL.h>

#include <array>
#include <iostream>
#include <sstream>
#include <string>

namespace Donut
{

Game* Game::instance = nullptr;

#if _DEBUG
const std::string kBuildString = "DEBUG BUILD";
#else
const std::string kBuildString = "Release Build";
#endif

void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
                                GLsizei length, const GLchar* message, const void* userParam)
{
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
	        (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""), type, severity, message);
}

void Game::TestAudio()
{
	// THIS IS ALL SHIT, PROOF OF CONCEPT!!

	if (_filesRCF.empty()) return;

	ALCdevice* device;
	ALCcontext* context;

	device  = alcOpenDevice(NULL);
	context = alcCreateContext(device, NULL);
	alcMakeContextCurrent(context);

	alGenBuffers(1, &buffer);
	alGenSources(1, &source);
}

void Game::PlayAudio(RCL::RCFFile& file, const std::string& filename)
{
	alSourceStop(source);

	auto rsdStream = file.GetFileStream(filename);
	if (rsdStream == nullptr) return;
	RCL::RSDFile rsdFile(*rsdStream);

	if (buffer != 0)
	{
		alDeleteBuffers(1, &buffer);
	}

	alGenBuffers(1, &buffer);

	ALenum format = AL_FORMAT_STEREO16;
	if (rsdFile.GetNumChannels() == 1)
	{
		if (rsdFile.GetBitsPerChannel() == 8)
			format = AL_FORMAT_MONO8;
		else if (rsdFile.GetBitsPerChannel() == 16)
			format = AL_FORMAT_MONO16;
	}
	else if (rsdFile.GetNumChannels() == 2)
	{
		if (rsdFile.GetBitsPerChannel() == 8)
			format = AL_FORMAT_STEREO8;
		else if (rsdFile.GetBitsPerChannel() == 16)
			format = AL_FORMAT_STEREO16;
	}

	const auto& data = rsdFile.GetData();

	alBufferData(buffer, format, data.data(), (ALsizei)data.size(), rsdFile.GetSampleRate());
	alSourcei(source, AL_BUFFER, buffer);
	alSourcei(source, AL_LOOPING, AL_FALSE);
	alSourcePlay(source);
}

Game::Game(int argc, char** argv)
{
	instance = this; // global static :D

	Commands::RunLine("HelloWorld();");
	//for (const auto& entry : std::filesystem::recursive_directory_iterator("scripts"))
	//{
	//	const auto& path = entry.path();
	//	const auto& extension = path.extension().string();
	//	if (extension != ".con" && extension != ".mfk") continue;

	//	Commands::RunScript(path.string());
	//}

	const std::string windowTitle = fmt::format("donut [{0}]", kBuildString);

	const int windowWidth = 1280, windowHeight = 960;
	_window = std::make_unique<Window>(windowTitle, windowWidth, windowHeight);

	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(MessageCallback, 0);
	glDebugMessageControl(GL_DEBUG_SOURCE_API, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, 0,
	                      GL_FALSE);

	ImGui::CreateContext();
	ImGui_ImplSDL2_InitForOpenGL(static_cast<SDL_Window*>(*_window),
	                             static_cast<SDL_GLContext*>(*_window));
	ImGui_ImplOpenGL3_Init("#version 130");

	//const float dpi_scale = 2.0f;
	//ImGuiIO& io = ImGui::GetIO();
	//ImGui::GetStyle().ScaleAllSizes(dpi_scale);
	//io.FontGlobalScale = dpi_scale;

	_lineRenderer = std::make_unique<LineRenderer>(1000000);
	_worldPhysics = std::make_unique<WorldPhysics>(_lineRenderer.get());

	std::vector<std::string> rcfFiles {
		"music00.rcf",
		"music01.rcf",
		"music02.rcf",
		"music03.rcf",
		"ambience.rcf",
		"carsound.rcf",
		"dialog.rcf",
		"nis.rcf",
		"scripts.rcf",
		"soundfx.rcf",
	};

	for (const std::string& filename : rcfFiles)
	{
		if (!std::filesystem::exists(filename)) continue;
		_filesRCF.push_back(std::make_unique<RCL::RCFFile>(filename));
	}

	TestAudio();

	// init sub classes
	_resourceManager = std::make_unique<ResourceManager>();

	if (std::filesystem::exists("./art/frontend/scrooby2/resource/fonts/font0_16.p3d"))
	{
		const P3D::P3DFile p3dFont("./art/frontend/scrooby2/resource/fonts/font0_16.p3d");
		_textureFontP3D = P3D::TextureFont::Load(*p3dFont.GetRoot().GetChildren().at(0));

		auto font = std::make_unique<Font>(*_textureFontP3D);
		_resourceManager->AddFont(_textureFontP3D->GetName(), std::move(font));
	}

	_level = std::make_unique<Level>();

	//
	_level->LoadP3D("L1_TERRA.p3d");

	// simpsons house
	_level->LoadP3D("l1z1.p3d");
	_level->LoadP3D("l1r1.p3d");
	_level->LoadP3D("l1r7.p3d");

	_level->DynaLoadData("l1z1.p3d;l1r1.p3d;l1r7.p3d;");

	// rest of the shit, load the whole world why not!!
	// _level->LoadP3D("l1r2.p3d");
	// _level->LoadP3D("l1r3.p3d");
	// _level->LoadP3D("l1r4a.p3d");
	// _level->LoadP3D("l1r6.p3d");
	_level->LoadP3D("l1z2.p3d");
	// _level->LoadP3D("l1z3.p3d");
	// _level->LoadP3D("l1z4.p3d");
	// _level->LoadP3D("l1z6.p3d");
	// _level->LoadP3D("l1z7.p3d");

	const auto skinVertSrc = File::ReadAll("shaders/skin.vert");
	const auto skinFragSrc = File::ReadAll("shaders/skin.frag");
	_skinShaderProgram     = std::make_unique<GL::ShaderProgram>(skinVertSrc, skinFragSrc);

	loadGlobal();
	LoadModel("homer", "homer");

	_camera = std::make_unique<FreeCamera>();
	_camera->SetPosition(Vector3(228.0f, 5.0f, -174.0f));
	_camera->SetFOV(70.0f);
	_camera->SetZNear(1.0f);
	_camera->SetZFar(100000.0f);

	_mouseLocked = false;
}

Game::~Game()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();

	_window.reset();

	SDL_Quit();
}

void Game::loadGlobal()
{
	_globalP3D = std::make_unique<P3D::P3DFile>("art/chars/global.p3d");

	const auto& root = _globalP3D->GetRoot();
	for (const auto& chunk : root.GetChildren())
	{
		if (chunk->GetType() != P3D::ChunkType::Texture) continue;
		_resourceManager->LoadTexture(*P3D::Texture::Load(*chunk));
	}
}

void Game::LoadModel(const std::string& name, const std::string& anim)
{
	if (_character != nullptr) _character.reset();

	_character = std::make_unique<Character>("pc");
	_character->LoadModel(name);
	_character->LoadAnimations(anim);
	_character->SetPosition(Vector3(220, 4.5, -172));

	if (anim == "homer")
		_character->SetAnimation("hom_loco_walk");
}

void Game::LockMouse(bool lockMouse)
{
	if (_mouseLocked == lockMouse)
		return;

	_mouseLocked = lockMouse;

	SDL_SetRelativeMouseMode(lockMouse ? SDL_TRUE : SDL_FALSE);

	if (lockMouse)
	{
		SDL_GetMouseState(&_lockedMousePosX, &_lockedMousePosY);
	}

	int w, h;
	SDL_GetWindowSize(static_cast<SDL_Window*>(*_window), &w, &h);
	SDL_WarpMouseInWindow(static_cast<SDL_Window*>(*_window), w / 2, h / 2);

	Input::ResetMouseDelta();
}

std::vector<std::tuple<std::string, Vector3, std::string>> locations {
	{ "Simpsons' House", Vector3(220, 3.5, -172), "l1z1.p3d;l1r1.p3d;l1r7.p3d;" },
	{ "Kwik E Mart", Vector3(209, 3.6, -285), "l1z2.p3d;l1r1.p3d;l1r2.p3d;" },
	{ "Church", Vector3(193.8, -0.9, -570), "l1r2.p3d;l1z2.p3d;l1z3.p3d;" },
	{ "Springfield Elementary", Vector3(-11, 0.7, -586), "l1z3.p3d;l1r2.p3d;l1r3.p3d;" },
	{ "Burns' Mansion", Vector3(-186, 3.5, -96), "l1z4.p3d;l1r3.p3d;l1r4a.p3d;" },
	{ "Stonecutters Tunnel", Vector3(-405, 2, 60), "l1z4.p3d;l1r3.p3d;l1r4a.p3d;" },
	{ "Power Plant Interior", Vector3(-80, 0.8, 297), "l1r4a.p3d;l1z6.p3d;l1r6.p3d;" },
	{ "Power Plant Parking Lot", Vector3(40, 0, 296), "l1z6.p3d;l1r6.p3d;" },
	{ "Tomacco", Vector3(190, -0.7, 425), "l1r6.p3d;l1z6.p3d;l1z7.p3d;" },
	{ "Trailer Park", Vector3(391, -2.2, 494), "l1z7.p3d;l1r6.p3d;l1r7.p3d;" },
	{ "Cletus' House", Vector3(333.5, -1.8, 356), "l1z7.p3d;l1r6.p3d;l1r7.p3d;" },
	{ "Graveyard", Vector3(368, 5.1, 5.4), "l1z1.p3d;l1r1.p3d;l1r7.p3d;" }
};

std::vector<std::pair<std::string, std::string>> models {
	{ "homer", "homer" },
	{ "h_evil", "homer" },
	{ "h_fat", "homer" },
	{ "h_undr", "homer" },
	{ "marge", "marge" },
	{ "bart", "bart" },
	{ "apu", "apu" },
	{ "a_amer", "apu" },
};

void Game::OnInputTextEntry(const std::string& text)
{
}

void Game::Run()
{
	// measure our delta time
	uint64_t now     = SDL_GetPerformanceCounter();
	uint64_t last    = 0;
	double deltaTime = 0.0;

	FpsTimer timer;

	SpriteBatch sprites(1024);
	GL::ShaderProgram& spriteShader = sprites.GetShader();

	auto animCamera = AnimCamera::LoadP3D("art/missions/level01/mission0cam.p3d");

	auto frontend = std::make_unique<FrontendProject>();
	frontend->LoadP3D("art/frontend/scrooby/bootup.p3d");

	Input::CaptureTextEntry(this, &Game::OnInputTextEntry);

	SDL_Event event;
	bool running = true;
	while (running)
	{
		last = now;
		now  = SDL_GetPerformanceCounter();

		deltaTime = ((now - last) / (double)SDL_GetPerformanceFrequency());
		timer.Update(deltaTime);

		Input::PreEvent();

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) running = false;

			ImGui_ImplSDL2_ProcessEvent(&event);

			Input::HandleEvent(event);
		}

		LockMouse(Input::IsDown(Button::MouseRight));

		float mouseDeltaX = Input::GetMouseDeltaX();
		float mouseDeltaY = Input::GetMouseDeltaY();

		if (_mouseLocked)
		{
			_camera->LookDelta(mouseDeltaX * 0.25f, mouseDeltaY * 0.25f);
		}

		auto inputForce = Vector3(0.0f);
		if (Input::IsDown(Button::KeyW)) inputForce += Vector3::Forward;
		if (Input::IsDown(Button::KeyS)) inputForce += Vector3::Backward;
		if (Input::IsDown(Button::KeyA)) inputForce += Vector3::Left;
		if (Input::IsDown(Button::KeyD)) inputForce += Vector3::Right;
		if (Input::IsDown(Button::KeySPACE)) inputForce += Vector3::Up;
		if (Input::IsDown(Button::KeyLCONTROL)) inputForce += Vector3::Down;
		if (inputForce.LengthSquared() > 0.0f)
		{
			inputForce.Normalize();
			inputForce *= Input::IsDown(Button::KeyLSHIFT) ? 60.0f : 10.0f;
			_camera->Move(inputForce, static_cast<float>(deltaTime));
		}

		auto cameraTransform = animCamera->Update(deltaTime * 35.0);
		//_camera->MoveTo(cameraTransform[3]);

		_worldPhysics->Update(static_cast<float>(deltaTime));

		_lineRenderer->DrawSkeleton(_character->GetPosition(), _character->GetSkeleton());
		_level->Update(deltaTime);

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame(static_cast<SDL_Window*>(*_window));
		ImGui::NewFrame();

		ImGui::BeginMainMenuBar();

		guiTeleportMenu();
		if (_character != nullptr)
			guiModelMenu(*_character);
		guiDebugMenu();

		ImGui::EndMainMenuBar();

		if (_debugResourceManagerWindowOpen)
			_resourceManager->ImGuiDebugWindow(&_debugResourceManagerWindowOpen);

		bool open = true;
		_level->ImGuiDebugWindow(&open);

		// ImGui::ShowDemoWindow();

		debugDrawRCF();

		ImGuiIO& io = ImGui::GetIO();
		ImGui::SetNextWindowPos(ImVec2(io.DisplaySize.x - 8.0f, io.DisplaySize.y - 8.0f), ImGuiCond_Always, ImVec2(1.0f, 1.0f));
		ImGui::SetNextWindowBgAlpha(0.35f);
		if (ImGui::Begin("Camera position overlay", NULL, ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoDecoration | ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings | ImGuiWindowFlags_NoFocusOnAppearing | ImGuiWindowFlags_NoNav))
		{
			auto const& camPos = _camera->GetPosition();
			auto const& camRot = _camera->GetOrientation();
			ImGui::Text("Camera Position: %s", camPos.ToString().c_str());
			ImGui::Text("Camera Orientation: %s", camRot.ToString().c_str());

			float fov = _camera->GetFOV();
			if (ImGui::SliderFloat("FOV", &fov, 0.0f, 120.0f))
				_camera->SetFOV(fov);

		}
		ImGui::End();

		if (_character != nullptr)
			_character->Update(deltaTime);

		ImGui::Render();

		int viewportWidth  = 0;
		int viewportHeight = 0;

		viewportWidth  = (int)io.DisplaySize.x;
		viewportHeight = (int)io.DisplaySize.y;

		glViewport(0, 0, viewportWidth, viewportHeight);

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);

		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		_camera->SetAspectRatio(static_cast<float>(viewportWidth) / static_cast<float>(viewportHeight));
		
		Matrix4x4 viewMatrix     = _camera->GetViewMatrix();
		Matrix4x4 projMatrix     = _camera->GetProjectionMatrix();
		Matrix4x4 viewProjection = projMatrix * viewMatrix;

		if (_level != nullptr) _level->Draw(viewProjection);

		if (_character != nullptr)
			_character->Draw(viewProjection, *_skinShaderProgram, *_resourceManager);

		glDisable(GL_DEPTH_TEST);
		_lineRenderer->Flush(viewProjection);
		glEnable(GL_DEPTH_TEST);

		Matrix4x4 proj = Matrix4x4::MakeOrtho(0.0f, viewportWidth, viewportHeight, 0.0f);

		if (_textureFontP3D != nullptr)
		{
			std::string fps = fmt::format("{0} fps", timer.GetFps());
			auto font       = _resourceManager->GetFont("boulder_16");
			sprites.DrawText(font, fps, Vector2(32 + 3, 32 + 3), Vector4(0.0f, 0.0f, 0.0f, 1.0f));
			sprites.DrawText(font, fps, Vector2(32, 32), Vector4(1.0f, 1.0f, 0.0f, 1.0f));
		}

		 sprites.Flush(proj);
		//frontend->Draw(proj);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		_window->Swap();
	}
}

void Game::guiModelMenu(Character& character)
{
	ImGui::Begin(fmt::format("Character: {0}", character.GetName()).c_str());

	if (ImGui::BeginCombo("Model", character.GetModelName().c_str()))
	{
		for (auto const& model : models)
		{
			const bool is_selected = character.GetModelName() == model.first;
			if (ImGui::Selectable(model.first.c_str(), is_selected))
			{
				character.LoadModel(model.first);
				character.LoadAnimations(model.second);
			}

			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}

		ImGui::EndCombo();
	}

	if (ImGui::BeginCombo("Animation", character.GetAnimName().c_str()))
	{
		for (auto const& anim : character.GetAnimations())
		{
			const bool is_selected = character.GetAnimName() == anim.first;
			if (ImGui::Selectable(anim.first.c_str(), is_selected))
			{
				character.SetAnimation(anim.first);
			}

			if (is_selected)
				ImGui::SetItemDefaultFocus();
		}

		ImGui::EndCombo();
	}

	Vector3 pos = character.GetPosition();
	if (ImGui::InputFloat3("Position", &pos[0]))
		character.SetPosition(pos);

	ImGui::End();
}

void Game::guiTeleportMenu()
{
	if (!ImGui::BeginMenu("Warp"))
		return;

	if (ImGui::BeginMenu("Level 1"))
	{
		for (auto const& location : locations)
		{
			if (ImGui::MenuItem(std::get<0>(location).c_str()))
			{
				const Vector3& dest = std::get<1>(location);
				//_worldPhysics->GetCharacterController()->SetPosition(dest);
				_camera->SetPosition(dest);
			}
			if (ImGui::IsItemHovered())
			{
				ImGui::BeginTooltip();
				ImGui::TextUnformatted(std::get<1>(location).ToString().c_str());
				ImGui::TextUnformatted(std::get<2>(location).c_str());
				ImGui::EndTooltip();
			}
		}

		ImGui::EndMenu();
	}

	ImGui::EndMenu();
}

void Game::guiDebugMenu()
{
	if (!ImGui::BeginMenu("Debug"))
		return;

	if (ImGui::BeginMenu("Physics"))
	{
		PhysicsDebugDrawMode mode = _worldPhysics->GetDebugDrawMode();

		ImGui::CheckboxFlags("Draw Wireframe", reinterpret_cast<unsigned int*>(&mode), static_cast<unsigned int>(PhysicsDebugDrawMode::DrawWireframe));
		ImGui::CheckboxFlags("Draw AABB", reinterpret_cast<unsigned int*>(&mode), static_cast<unsigned int>(PhysicsDebugDrawMode::DrawAABB));
		ImGui::CheckboxFlags("Draw Features Text", reinterpret_cast<unsigned int*>(&mode), static_cast<unsigned int>(PhysicsDebugDrawMode::DrawFeaturesText));
		ImGui::CheckboxFlags("Draw Contact Points", reinterpret_cast<unsigned int*>(&mode), static_cast<unsigned int>(PhysicsDebugDrawMode::DrawContactPoints));
		ImGui::CheckboxFlags("Draw Text", reinterpret_cast<unsigned int*>(&mode), static_cast<unsigned int>(PhysicsDebugDrawMode::DrawText));
		ImGui::CheckboxFlags("Fast Wireframe", reinterpret_cast<unsigned int*>(&mode), static_cast<unsigned int>(PhysicsDebugDrawMode::FastWireframe));
		ImGui::CheckboxFlags("Draw Normals", reinterpret_cast<unsigned int*>(&mode), static_cast<unsigned int>(PhysicsDebugDrawMode::DrawNormals));
		ImGui::CheckboxFlags("Draw Frames", reinterpret_cast<unsigned int*>(&mode), static_cast<unsigned int>(PhysicsDebugDrawMode::DrawFrames));

		_worldPhysics->SetDebugDrawMode(mode);

		ImGui::EndMenu();
	}

	if (ImGui::MenuItem("Resource Manager..."))
		_debugResourceManagerWindowOpen = true;

	ImGui::EndMenu();
}

void Game::debugDrawP3D(const P3D::P3DFile& p3d)
{
	ImGui::SetNextWindowSize(ImVec2(330, 400), ImGuiCond_Once);
	ImGui::Begin(p3d.GetFileName().c_str());

	ImGui::SetNextItemOpen(true); // open the root node
	const auto traverse_chunk = [&](const auto& self, const P3D::P3DChunk& chunk) -> void {
		std::ostringstream name;
		name << chunk.GetType();

		if (ImGui::TreeNode(&chunk, "%s", name.str().c_str()))
		{
			ImGui::TextDisabled("Type ID: %x", static_cast<uint32_t>(chunk.GetType()));
			ImGui::TextDisabled("Data Size: %ldb", chunk.GetData().size());

			for (auto& child : chunk.GetChildren())
			{
				self(self, *child);
			}

			ImGui::TreePop();
		}
	};

	traverse_chunk(traverse_chunk, p3d.GetRoot());

	ImGui::End();
}

void Game::debugDrawRCF()
{
	if (_filesRCF.empty()) return;

	ImGui::SetNextWindowSize(ImVec2(330, 400), ImGuiCond_Once);
	ImGui::Begin("RADCORE CEMENT LIBRARY");

	for (const auto& rcf : _filesRCF)
	{
		if (ImGui::TreeNode(rcf->GetFileName().c_str()))
		{
			for (const auto& filename : rcf->GetFilenames())
			{
				if (ImGui::Selectable(filename.c_str()))
				{
					std::cout << filename.c_str() << std::endl;
					PlayAudio(*rcf, filename.c_str());
				}
			}

			ImGui::TreePop();
		}
	}

	ImGui::End();
}

} // namespace Donut
