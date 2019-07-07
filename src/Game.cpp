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

namespace Donut {

const std::string kWindowTitle = "donut";

Game::Game(int argc, char** argv) {
    const int windowWidth = 1280, windowHeight = 1024;
    _window = std::make_unique<Window>(kWindowTitle, windowWidth, windowHeight);

    ImGui::CreateContext();
    ImGui_ImplSDL2_InitForOpenGL(static_cast<SDL_Window*>(*_window.get()),
                                 static_cast<SDL_GLContext*>(*_window.get()));
    ImGui_ImplOpenGL3_Init("#version 130");

    if (std::filesystem::exists("homer_m.p3d")) {
        File file("homer_m.p3d", FileMode::Read);

        _p3d = std::make_unique<Pure3D::Pure3D>();
        _p3d->LoadFromFile(file);

        file.Close();
    }
}

Game::~Game() {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();

    _window.reset();

    SDL_Quit();
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

        if (_p3d != nullptr) {
            debugDrawP3D("homer_m.p3d", *_p3d);
        }

        ImGui::Render();

        ImGuiIO& io = ImGui::GetIO();
        glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        _window->Swap();
    }
}

void Game::debugDrawP3D(const std::string& name, const Pure3D::Pure3D& p3d)
{
    ImGui::SetNextWindowSize(ImVec2(330, 400), ImGuiSetCond_Once);
    ImGui::Begin(name.c_str());

    const auto traverse_chunk = [&](const auto& self, Pure3D::Chunk& chunk) -> void {
        std::ostringstream name;
        name << chunk.GetType();

        if (ImGui::TreeNode(&chunk, name.str().c_str())) {
            ImGui::TextDisabled("Type ID: %lx", chunk.GetType());
            ImGui::TextDisabled("Data Size: %db", chunk.GetData().size());

            for (std::unique_ptr<Pure3D::Chunk>& child : chunk.GetChildren()) {
                self(self, *child.get());
            }

            ImGui::TreePop();
        }
    };

    traverse_chunk(traverse_chunk, _p3d->GetRoot());

    ImGui::End();
}

} // namespace Donut
