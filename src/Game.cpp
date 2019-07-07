#include <iostream>
#include <string>
#include <Game.h>
#include <Pure3D/Pure3D.h>
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
	ImGui_ImplSDL2_InitForOpenGL(
		static_cast<SDL_Window*>(*_window.get()),
		static_cast<SDL_GLContext*>(*_window.get())
	);
	ImGui_ImplOpenGL3_Init("#version 130");

    if (std::filesystem::exists("wrench.p3d")) {
        File file("wrench.p3d", FileMode::Read);
        Pure3D::Pure3D p3d;
        p3d.LoadFromFile(file);
        file.Close();

        const auto& chunks = p3d.GetRoot().GetChildren();
        for (const auto& chunk : chunks) {
            std::cout << chunk->GetType() << std::endl;
        }
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
		ImGui::ShowDemoWindow();

		ImGui::Render();

		ImGuiIO& io = ImGui::GetIO();
		glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

		ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        _window->Swap();
    }
}

} // namespace Donut
