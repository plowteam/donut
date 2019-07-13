#include <FreeCamera.h>
#include <Game.h>
#include <Input.h>
#include <LineRenderer.h>
#include <FreeCamera.h>
#include <SpriteBatch.h>
#include <P3D/Texture.h>
#include <SDL.h>
#include <Window.h>
#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/quaternion.hpp>
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

	if (std::filesystem::exists("font0_24.p3d"))
	{
		auto p3dFont = std::make_unique<P3D::P3DFile>("font0_24.p3d");
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

	_level = std::make_unique<Level>();

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

void Game::Run()
{
	// measure our delta time
	uint64_t now     = SDL_GetPerformanceCounter();
	uint64_t last    = 0;
	double deltaTime = 0.0;

	FreeCamera camera;
	camera.MoveTo(glm::vec3(230.0f, -19.0f, 150.0f));

	LineRenderer lines(10000);
	SpriteBatch sprites;
	GL::ShaderProgram* spriteShader = sprites.GetShader();

	SDL_Event event;
	bool running = true;
	while (running)
	{
		last = now;
		now  = SDL_GetPerformanceCounter();

		deltaTime = ((now - last) / (double)SDL_GetPerformanceFrequency());

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
			camera.LookDelta(mouseDeltaX * 0.25f, mouseDeltaY * 0.25f);
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
			camera.Move(inputForce, (float)deltaTime);
		}

		lines.DrawSphere(glm::vec3(0), 100, 16, 16, glm::vec4(0.0f, 1.0f, 1.0f, 1.0f));
		lines.DrawAABBox(glm::vec3(-100.0f), glm::vec3(100.0f), glm::vec4(1.0f, 1.0f, 0.0f, 1.0f));

		for (auto const& intersect : _level->GetIntersects())
		{
			auto const& aabb = intersect->GetAABB();
			lines.DrawAABBox(aabb.GetMin(), aabb.GetMax(), glm::vec4(0.0f, 1.0f, 0.0f, 1.0f));
			
		}

		ImGui_ImplOpenGL3_NewFrame();
		ImGui_ImplSDL2_NewFrame(static_cast<SDL_Window*>(*_window));
		ImGui::NewFrame();

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

		ImGui::BeginMainMenuBar();
		for (auto const& model : models)
		{
			if (ImGui::Button(model.first.c_str())) LoadModel(model.first, model.second);
		}

		if (_skinModel != nullptr && !_skinModel->AnimationNames.empty())
		{
			if (ImGui::BeginCombo("##combo", _skinModel->AnimationNames[_skinModel->_animIndex].c_str()))
			{
				for (int n = 0; n < _skinModel->AnimationNames.size(); n++)
				{
					bool is_selected = (_skinModel->_animIndex == n);
					if (ImGui::Selectable(_skinModel->AnimationNames[n].c_str(), is_selected))
						_skinModel->_animIndex = n;
					if (is_selected)
						ImGui::SetItemDefaultFocus();
				}
				ImGui::EndCombo();
			}
		}

		ImGui::EndMainMenuBar();

		if (_skinModel != nullptr)
		{
			debugDrawP3D(_skinModel->GetP3DFile());

			if (_skinModel->GetAnimP3DFile() != nullptr)
			{
				debugDrawP3D(*_skinModel->GetAnimP3DFile());
			}

			_skinModel->Update(deltaTime);
		}

		if (_textureFontP3D != nullptr)
		{
			ImGui::Begin("Font Textures");
			for (int i = 0; i < _textureFontP3D->GetNumTextures(); ++i)
			{
				auto texture = _textureFontP3D->GetTexture(i);
				ImGui::Text(_textureFontP3D->GetTextureName(i).c_str());
				ImGui::Image((void*)texture->GetHandle(), ImVec2(texture->GetWidth(), texture->GetHeight()));
			}
			ImGui::End();
		}

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

		glm::mat4 viewMatrix = camera.GetViewMatrix(); //glm::lookAt(_camPos, _lookAt, glm::vec3(0, 1, 0));
		glm::mat4 mvp        = projectionMatrix * viewMatrix * glm::scale(glm::mat4(1.0f), glm::vec3(-1.0f, 1.0f, 1.0f));

		lines.Flush(mvp);

		if (_level != nullptr) _level->Draw(GetResourceManager(), mvp);

		// -230.0f, 19.0f, -150.0f
		mvp = mvp * glm::translate(glm::mat4(1.0f), glm::vec3(229.0f, 3.5f, -180.0f));
		mvp = mvp * glm::rotate(glm::mat4(1.0f), glm::radians(180.0f), glm::vec3(0.0f, 1.0f, 0.0f));

		if (_skinModel != nullptr) _skinModel->Draw(GetResourceManager(), mvp);

		glm::mat4 proj = glm::ortho(0.0f, io.DisplaySize.x, io.DisplaySize.y, 0.0f);

		sprites.Begin();

		//for (int i = 0; i < 32; ++i)
		//{
		//	sprites.Draw(nullptr, glm::vec2(i * 32, i * 32), glm::vec2(32, 32), glm::vec4(1.0f, 1.0f, 0.0f, 0.5f));
		//}

		sprites.End(proj);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		_window->Swap();
	}
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
