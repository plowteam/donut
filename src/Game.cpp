#include <iostream>
#include <sstream>
#include <string>
#include <Game.h>
#include <SDL.h>
#include <Window.h>
#include <glad/glad.h>

#include <imgui.h>
#include <imgui_impl_opengl3.h>
#include <imgui_impl_sdl.h>

#include <P3D/Loaders/TextureLoader.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Donut {

const std::string kWindowTitle = "donut";

void GLAPIENTRY MessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
                                GLsizei length, const GLchar* message, const void* userParam) {
    fprintf(stderr, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s\n",
            (type == GL_DEBUG_TYPE_ERROR ? "** GL ERROR **" : ""), type, severity, message);
}

Game::Game(int argc, char** argv) {
    const int windowWidth = 1280, windowHeight = 1024;
    _window = std::make_unique<Window>(kWindowTitle, windowWidth, windowHeight);
    _camPos = glm::vec3(0.0f, 2.0f, -2.0f);
    _lookAt = glm::vec3(0.0f, 1.15f, 0.0f);

    glEnable(GL_DEBUG_OUTPUT);
    glDebugMessageCallback(MessageCallback, 0);
    glDebugMessageControl(GL_DEBUG_SOURCE_API, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, 0,
                          GL_FALSE);

	glEnable(GL_TEXTURE_1D);
	glEnable(GL_TEXTURE_2D);

    ImGui::CreateContext();
    ImGui_ImplSDL2_InitForOpenGL(static_cast<SDL_Window*>(*_window.get()),
                                 static_cast<SDL_GLContext*>(*_window.get()));
    ImGui_ImplOpenGL3_Init("#version 130");

    loadGlobal();
	LoadModel("homer_m.p3d");
}

Game::~Game() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    _window.reset();

    SDL_Quit();
}

void Game::loadGlobal() {
    _globalP3D = std::make_unique<P3D::P3DFile>("global.p3d");

	_textures = std::map<std::string, std::unique_ptr<GL::Texture2D>>();

    const auto& root = _globalP3D->GetRoot();
    for (const auto& chunk : root.GetChildren()) {
        if (chunk->GetType() != P3D::ChunkType::Texture)
            continue;

		P3D::TextureLoader loader;
        auto texture = loader.Load(*chunk.get());

		auto texdata = texture->GetData();

		auto tex2d = std::make_unique<GL::Texture2D>(texdata.width, texdata.height, GL_RGB, GL_RGB, GL_UNSIGNED_BYTE, texdata.data.data());
		_textures[texture->GetName()] = std::move(tex2d);
    }
}

void Game::LoadModel(const std::string& name) {
    if (_skinModel != nullptr)
	    _skinModel.reset();

    _skinModel = std::make_unique<SkinModel>(name);
}

void Game::Run() {
    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT)
                running = false;

            ImGui_ImplSDL2_ProcessEvent(&event);
        }

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplSDL2_NewFrame(static_cast<SDL_Window*>(*_window.get()));
        ImGui::NewFrame();

		std::vector<std::string> models{"homer_m.p3d", "marge_m.p3d", "bart_m.p3d", "barney_m.p3d", "carl_m.p3d", "hooker_m.p3d"};

		ImGui::BeginMainMenuBar();
        for (auto const& model : models) {
            if (ImGui::Button(model.c_str()))
                LoadModel(model.c_str());
		}

		ImGui::EndMainMenuBar();

        if (_skinModel != nullptr)
            debugDrawP3D(_skinModel->GetP3DFile());

        ImGui::Begin("Camera");
        ImGui::SliderFloat3("pos", &_camPos[0], -10.0f, 10.f);
        ImGui::SliderFloat3("lookat", &_lookAt[0], -10.0f, 10.f);
        ImGui::End();

		ImGui::Begin("Global Textures");
		for (auto const& [key, val] : _textures)
		{
			ImGui::Text(key.c_str());
			ImGui::Image((void*)val->GetHandle(), ImVec2(val->GetWidth(), val->GetHeight()));
		}
		ImGui::End();

        ImGui::Render();

        ImGuiIO& io = ImGui::GetIO();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glEnable(GL_DEPTH_TEST);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glm::mat4 projectionMatrix = glm::perspective(
            glm::radians(70.0f), io.DisplaySize.x / io.DisplaySize.y, 0.1f, 100.0f);

        glm::mat4 viewMatrix = glm::lookAt(_camPos, _lookAt, glm::vec3(0, 1, 0));
        glm::mat4 mvp = projectionMatrix * viewMatrix * glm::mat4(1.0f);

		// bind to texture 0 for now
		_textures["char_swatches1.bmp"]->Bind(0);
        if (_skinModel != nullptr)
            _skinModel->Draw(mvp);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        _window->Swap();
    }
}

void Game::debugDrawP3D(const P3D::P3DFile& p3d) {
    ImGui::SetNextWindowSize(ImVec2(330, 400), ImGuiSetCond_Once);
    ImGui::Begin(p3d.GetFileName().c_str());

    ImGui::SetNextItemOpen(true); // open the root node
    const auto traverse_chunk = [&](const auto& self, const P3D::P3DChunk& chunk) -> void {
        std::ostringstream name;
        name << chunk.GetType();

        if (ImGui::TreeNode(&chunk, "%s", name.str().c_str())) {
            ImGui::TextDisabled("Type ID: %x", static_cast<std::uint32_t>(chunk.GetType()));
            ImGui::TextDisabled("Data Size: %ldb", chunk.GetData().size());

            for (auto& child : chunk.GetChildren()) {
                self(self, *child);
            }

            ImGui::TreePop();
        }
    };

    traverse_chunk(traverse_chunk, p3d.GetRoot());

    ImGui::End();
}

} // namespace Donut
