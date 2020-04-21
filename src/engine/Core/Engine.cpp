
#include "Engine.h"
#include <API/GL/GL_API.h>
#include <imgui.h>
#include <imgui_impl_glfw.h>
#include <imgui_impl_opengl3.h>
#include "Window.h"
#include "Core/Rendering/BatchRenderer.h"
#include "Scenes/Demo3D/SpacialSceneDemo.h"

Engine::Engine() {
    Log::logLevel(Log::DEBUG);
    graphics = new GL_API();
    window = new Window(graphics->createWindow("WINDOW", 300, 200));
    input = new Input(window->getHandle());
    renderer = new BatchRenderer();
    canvas = new Canvas(*window, renderer->DEFAULT_2D_SHADER);
    imGuiEnabled = true;
    initImgui();
}

void Engine::start() {
    double delta_time = 0;
    Timer delta_time_timer;

    Log::status("Starting main loop..");
    while (!window->shouldClose()) {

        window->pollEvents();
        if (input->isKeyDown(GLFW_KEY_ESCAPE)) {
            window->close();
        }
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        if (scene) {

            scene->update((float) delta_time);
            scene->draw();
            scene->render();
            renderer->clearColor();
            printFPS();
            renderer->renderOnMainBuffer(*canvas);
        } else {
            renderer->clear();
            drawSceneSelector();
        }
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        window->swapBuffer();

        delta_time = delta_time_timer.ms();
        delta_time_timer.reset();

    }
    Log::status("Cleaning up..");
    delete scene;
}

Engine::~Engine() {
    delete canvas;
    delete renderer;
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    graphics->terminate();
    delete graphics;
    delete input;
    delete window;
}

void Engine::printFPS() {
    fps++;
    if (last_fps_print < std::time(0) - 1) {
        Log::debug("Fps:" + std::to_string(fps));
        Log::debug("Draw calls:"+std::to_string(renderer->getDrawCount()));
        Log::debug("Vertices:"+std::to_string(renderer->getVerticesCount()));
        fps = 0;
        last_fps_print = std::time(0);
    }
}

void Engine::initImgui() {
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO &io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(&window->getHandle(), true);
    ImGui_ImplOpenGL3_Init("#version 330 core");
    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;
    io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;
}


void Engine::drawSceneSelector() {
    ImGui::Begin("SceneSelector");
    {
        if (ImGui::Button("3D editor")) {
            runInEditor<Scene>();
        }
        if (ImGui::Button("3D Features Scene")) {
            run<SpacialSceneDemo>();
        }
    }
    ImGui::End();
}












