#include <Core/FpsTimer.h>
#include <FreeCamera.h>
#include <Game.h>
#include <Input/Input.h>
#include <Level.h>
#include <P3D/Texture.h>
#include <P3D/TextureFont.h>
#include <Physics/WorldPhysics.h>
#include <Render/LineRenderer.h>
#include <Render/SkinModel.h>
#include <Render/SpriteBatch.h>
#include <ResourceManager.h>
#include <SDL.h>
#include <Window.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/gtx/transform.hpp>
#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl.h>
#include <iostream>
#include <sstream>
#include <string>

namespace Donut
{

const std::string kWindowTitle = "donut";

void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
                                GLsizei length, const GLchar* message, const void* userParam)
{
	fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
	        (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""), type, severity, message);
}

Game::Game(int argc, char** argv)
{
	const int windowWidth = 1280, windowHeight = 1024;
	_window = std::make_unique<Window>(kWindowTitle, windowWidth, windowHeight);

	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback(MessageCallback, 0);
	glDebugMessageControl(GL_DEBUG_SOURCE_API, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, 0,
	                      GL_FALSE);

	glEnable(GL_TEXTURE_1D);
	glEnable(GL_TEXTURE_2D);

	ImGui::CreateContext();
	ImGui_ImplSDL2_InitForOpenGL(static_cast<SDL_Window*>(*_window),
	                             static_cast<SDL_GLContext*>(*_window));
	ImGui_ImplOpenGL3_Init("#version 130");

	// init sub classes
	_resourceManager = std::make_unique<ResourceManager>();

	loadGlobal();
	LoadModel("homer_m.p3d", "homer_a.p3d");

	if (std::filesystem::exists("font0_16.p3d"))
	{
		auto p3dFont     = std::make_unique<P3D::P3DFile>("font0_16.p3d");
		const auto& root = p3dFont->GetRoot();
		for (const auto& chunk : root.GetChildren())
		{
			switch (chunk->GetType())
			{
			case P3D::ChunkType::TextureFont:
			{
				_textureFontP3D = P3D::TextureFont::Load(*chunk);
				break;
			}
			}
		}
	}

	_lineRenderer = std::make_unique<LineRenderer>(1000000);

	_worldPhysics = std::make_unique<WorldPhysics>(_lineRenderer.get());
	_level        = std::make_unique<Level>(_worldPhysics.get());

	_level->LoadP3D("L1_TERRA.p3d");

	// simpsons house l1z1.p3d;l1r1.p3d;l1r7.p3d;
	_level->LoadP3D("l1z1.p3d");
	_level->LoadP3D("l1r1.p3d");
	_level->LoadP3D("l1r7.p3d");

	// rest of the shit, load the whole world why not!!
	_level->LoadP3D("l1r2.p3d");
	_level->LoadP3D("l1r3.p3d");
	_level->LoadP3D("l1r4a.p3d");
	_level->LoadP3D("l1r6.p3d");
	_level->LoadP3D("l1z2.p3d");
	_level->LoadP3D("l1z3.p3d");
	_level->LoadP3D("l1z4.p3d");
	_level->LoadP3D("l1z6.p3d");
	_level->LoadP3D("l1z7.p3d");

	_camera = std::make_unique<FreeCamera>();
	_camera->MoveTo(glm::vec3(228.0f, -5.0f, -174.0f));

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
	_globalP3D = std::make_unique<P3D::P3DFile>("global.p3d");

	const auto& root = _globalP3D->GetRoot();
	for (const auto& chunk : root.GetChildren())
	{
		if (chunk->GetType() != P3D::ChunkType::Texture) continue;

		auto texture = P3D::Texture::Load(*chunk);
		auto texdata = texture->GetData();

		auto tex2d = std::make_unique<GL::Texture2D>(texdata.width, texdata.height, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, texdata.data.data());
		_resourceManager->AddTexture(texture->GetName(), std::move(tex2d));
	}
}

void Game::LoadModel(const std::string& name, const std::string& anim)
{
	if (_skinModel != nullptr) _skinModel.reset();

	_skinModel = std::make_unique<SkinModel>(name);
	_skinModel->LoadAnimations(anim);
}

void Game::LockMouse(bool lockMouse)
{
	if (_mouseLocked == lockMouse)
	{
		return;
	}

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

std::vector<std::tuple<std::string, glm::vec3, std::string>> locations {
	{ "Simpsons' House", glm::vec3(220, 3.5, -172), "l1z1.p3d;l1r1.p3d;l1r7.p3d;" },
	{ "Kwik E Mart", glm::vec3(209, 3.6, -285), "l1z2.p3d;l1r1.p3d;l1r2.p3d;" },
	{ "Church", glm::vec3(193.8, -0.9, -570), "l1r2.p3d;l1z2.p3d;l1z3.p3d;" },
	{ "Springfield Elementary", glm::vec3(-11, 0.7, -586), "l1z3.p3d;l1r2.p3d;l1r3.p3d;" },
	{ "Burns' Mansion", glm::vec3(-186, 3.5, -96), "l1z4.p3d;l1r3.p3d;l1r4a.p3d;" },
	{ "Stonecutters Tunnel", glm::vec3(-405, 2, 60), "l1z4.p3d;l1r3.p3d;l1r4a.p3d;" },
	{ "Power Plant Interior", glm::vec3(-80, 0.8, 297), "l1r4a.p3d;l1z6.p3d;l1r6.p3d;" },
	{ "Power Plant Parking Lot", glm::vec3(40, 0, 296), "l1z6.p3d;l1r6.p3d;" },
	{ "Tomacco", glm::vec3(190, -0.7, 425), "l1r6.p3d;l1z6.p3d;l1z7.p3d;" },
	{ "Trailer Park", glm::vec3(391, -2.2, 494), "l1z7.p3d;l1r6.p3d;l1r7.p3d;" },
	{ "Cletus' House", glm::vec3(333.5, -1.8, 356), "l1z7.p3d;l1r6.p3d;l1r7.p3d;" },
	{ "Graveyard", glm::vec3(368, 5.1, 5.4), "l1z1.p3d;l1r1.p3d;l1r7.p3d;" }
};

std::vector<std::pair<std::string, std::string>> models {
	{ "homer_m.p3d", "homer_a.p3d" },
	{ "h_evil_m.p3d", "homer_a.p3d" },
	{ "h_fat_m.p3d", "homer_a.p3d" },
	{ "h_undr_m.p3d", "homer_a.p3d" },
	{ "marge_m.p3d", "marge_a.p3d" },
	{ "bart_m.p3d", "bart_a.p3d" },
	{ "apu_m.p3d", "apu_a.p3d" },
	{ "a_amer_m.p3d", "apu_a.p3d" },
};

void Game::Run()
{
	// measure our delta time
	uint64_t now     = SDL_GetPerformanceCounter();
	uint64_t last    = 0;
	double deltaTime = 0.0;

	FpsTimer timer;

	SpriteBatch sprites;
	GL::ShaderProgram* spriteShader = sprites.GetShader();

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

		auto inputForce = glm::vec3(0.0f);
		if (Input::IsDown(Button::KeyW)) inputForce += glm::vec3(0.0f, 0.0f, 1.0f);
		if (Input::IsDown(Button::KeyS)) inputForce -= glm::vec3(0.0f, 0.0f, 1.0f);
		if (Input::IsDown(Button::KeyA)) inputForce += glm::vec3(1.0f, 0.0f, 0.0f);
		if (Input::IsDown(Button::KeyD)) inputForce -= glm::vec3(1.0f, 0.0f, 0.0f);
		if (glm::length2(inputForce) > 0.0f)
		{
			inputForce = glm::normalize(inputForce);
			inputForce *= Input::IsDown(Button::KeyLSHIFT) ? 60.0f : 10.0f;
			_camera->Move(inputForce, static_cast<float>(deltaTime));
		}

		_worldPhysics->Update(static_cast<float>(deltaTime));

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame(static_cast<SDL_Window*>(*_window));
		ImGui::NewFrame();

		ImGui::BeginMainMenuBar();

		guiTeleportMenu();
		guiModelMenu();

		ImGui::EndMainMenuBar();

		if (_skinModel != nullptr)
			_skinModel->Update(deltaTime);

		ImGui::Render();

		ImGuiIO& io = ImGui::GetIO();
		glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_BLEND);
		//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
		glEnable(GL_SAMPLE_ALPHA_TO_COVERAGE);
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glm::mat4 projectionMatrix = glm::perspective(
		    glm::radians(70.0f), io.DisplaySize.x / io.DisplaySize.y, 0.1f, 10000.0f);

		glm::mat4 viewMatrix = _camera->GetViewMatrix(); //glm::lookAt(_camPos, _lookAt, glm::vec3(0, 1, 0));
		glm::mat4 mvp        = projectionMatrix * viewMatrix * glm::scale(glm::mat4(1.0f), glm::vec3(-1.0f, 1.0f, -1.0f));

		_lineRenderer->Flush(mvp);

		if (_level != nullptr) _level->Draw(GetResourceManager(), mvp);

		// -230.0f, 19.0f, -150.0f
		auto charPos = _worldPhysics->GetCharacterController()->GetPosition() - glm::vec3(0.0, 0.90f, 0.0f);

		mvp = mvp * glm::translate(glm::mat4(1.0f), charPos);
		mvp = mvp * glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		if (_skinModel != nullptr) _skinModel->Draw(GetResourceManager(), mvp);

		glm::mat4 proj = glm::ortho(0.0f, io.DisplaySize.x, io.DisplaySize.y, 0.0f);

		sprites.Begin();

		if (_textureFontP3D != nullptr)
		{
			std::string s = "Call Mr Plow, that's my name, that name again is Mr Plow!";
			sprites.DrawText(_textureFontP3D.get(), s, glm::vec2(64 + 3, 128 + 3), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
			sprites.DrawText(_textureFontP3D.get(), s, glm::vec2(64, 128), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));

			int fps = timer.GetFps();
			std::stringstream ss;
			ss << fps << " fps";
			sprites.DrawText(_textureFontP3D.get(), ss.str(), glm::vec2(32 + 3, 32 + 3), glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
			sprites.DrawText(_textureFontP3D.get(), ss.str(), glm::vec2(32, 32), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));
		}

		sprites.End(proj);

		glDisable(GL_SAMPLE_ALPHA_TO_COVERAGE);
		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		_window->Swap();
	}
}

void Game::guiModelMenu()
{
	if (ImGui::BeginMenu("Model"))
	{
		for (auto const& model : models)
		{
			if (ImGui::MenuItem(model.first.c_str())) LoadModel(model.first, model.second);
		}
		ImGui::EndMenu();
	}

	if (_skinModel != nullptr && !_skinModel->AnimationNames.empty())
	{
		ImGui::PushItemWidth(150.0f);
		if (ImGui::BeginCombo("##combo", _skinModel->AnimationNames[_skinModel->_animIndex].c_str()))
		{
			for (int n = 0; n < _skinModel->AnimationNames.size(); n++)
			{
				const bool is_selected = (_skinModel->_animIndex == n);
				if (ImGui::Selectable(_skinModel->AnimationNames[n].c_str(), is_selected))
					_skinModel->_animIndex = n;
				if (is_selected)
					ImGui::SetItemDefaultFocus();
			}
			ImGui::EndCombo();
		}
	}
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
				const glm::vec3& dest = std::get<1>(location);
				_worldPhysics->GetCharacterController()->SetPosition(dest);
				_camera->MoveTo(dest);
			}
			if (ImGui::IsItemHovered())
			{
				ImGui::BeginTooltip();
				ImGui::TextUnformatted(glm::to_string(std::get<1>(location)).c_str());
				ImGui::TextUnformatted(std::get<2>(location).c_str());
				ImGui::EndTooltip();
			}
		}

		ImGui::EndMenu();
	}

	ImGui::EndMenu();
}

void Game::debugDrawP3D(const P3D::P3DFile& p3d)
{
	ImGui::SetNextWindowSize(ImVec2(330, 400), ImGuiSetCond_Once);
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

} // namespace Donut
