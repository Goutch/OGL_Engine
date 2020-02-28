//
// Created by User on 2020-01-26.
//

#include "Editor.h"
#include <Core/Rendering/BatchRenderer.h>
#include <Entities/Spacial/MeshRenderer.h>
#include <Entities/Canvas/Rect.h>
#include <Entities/Canvas/Line.h>
#include <imgui.h>
Editor::Editor(Scene* scene) {
    this->current_scene=scene;
}

Editor::~Editor() {
    delete current_scene_canvas;
    delete current_scene;
}

void Editor::init(const Canvas &canvas, Renderer &renderer, Window &window) {
    Scene::init(canvas, renderer, window);
    current_scene_canvas = new Canvas(canvas, renderer.DEFAULT_CANVAS_SHADER, canvas.getPixelWidth() / 2,
                                      canvas.getPixelHeight() / 2, canvas.getPixelWidth() / 4,
                                      canvas.getPixelHeight() / 4);
    current_scene->init(*current_scene_canvas, renderer, window);;
}
void Editor::setScene(Scene* scene) {
    this->current_scene=scene;
    current_scene->init(*current_scene_canvas, *renderer, *window);
}
void Editor::update(float delta) {
    Scene::update(delta);
    current_scene->update(delta);
}

void Editor::draw() const {
    current_scene->draw();
    current_scene->render();
    ImGuiID dockspaceID = 0;
    float h,w;
    w=canvas->getPixelWidth();
    h=canvas->getPixelHeight();
    Scene::draw();


    ImGui::SetNextWindowPos(ImVec2(0,0));
    ImGui::SetNextWindowSize(ImVec2(w,h),0);
    ImGui::Begin("EDITOR");
    {
        dockspaceID = ImGui::GetID("HUB_DockSpace");
        ImGui::DockSpace(dockspaceID , ImVec2(0.0f, 0.0f),0/* ImGuiDockNodeFlags_None|ImGuiDockNodeFlags_PassthruCentralNode|ImGuiDockNodeFlags_NoResize*/);
    }
    ImGui::End();


    ImGui::SetNextWindowDockID(dockspaceID , ImGuiCond_FirstUseEver);
    ImGui::Begin("Scene rendering");
    {
        ImVec2 vMin = ImGui::GetWindowContentRegionMin();
        ImVec2 vMax = ImGui::GetWindowContentRegionMax();
        if(vMax.x!=current_scene_canvas->getPixelWidth()||
            vMax.y!=current_scene_canvas->getPixelHeight())
            current_scene_canvas->setSize(vMax.x,vMax.y);
        vMin.x += ImGui::GetWindowPos().x;
        vMin.y += ImGui::GetWindowPos().y;
        vMax.x += ImGui::GetWindowPos().x;
        vMax.y += ImGui::GetWindowPos().y;
        ImGui::GetWindowDrawList()->AddImage(
                (void *) current_scene_canvas->getFrameBuffer().getTexture().getID(),
                vMin,
                vMax,
                ImVec2(0, 1),
                ImVec2(1, 0));
    }
    ImGui::End();
}








