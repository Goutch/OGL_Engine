//
// Created by User on 2020-01-26.
//

#include "Editor.h"
#include <Core/Rendering/BatchRenderer.h>
#include <Entities/Spacial/MeshRenderer.h>
#include <Entities/Canvas/Rect.h>
#include <Entities/Canvas/Line.h>
#include <imgui.h>
#include <imgui_demo.cpp>
#include <Core/Log.h>
#include "Core/Input.h"

Editor::Editor(SpacialScene *scene) {
    this->current_scene = scene;
}

Editor::Editor() {
    current_scene = new SpacialScene();
}

Editor::~Editor() {
    for (int i = 0; i < cameras_canvas.size(); ++i) {
        delete cameras_canvas[i];
    }
    cameras_canvas.clear();
    delete current_scene;
}

void Editor::init(const Canvas &canvas, Renderer &renderer, Input &input) {

    Scene::init(canvas, renderer, input);
    cameras_canvas.push_back(new Canvas(canvas, renderer.DEFAULT_CANVAS_SHADER, canvas.getPixelWidth() / 2,
                                        canvas.getPixelHeight() / 2, canvas.getPixelWidth() / 4,
                                        canvas.getPixelHeight() / 4));
    current_scene->init(*cameras_canvas[0], renderer, input);;

    current_scene->getCamera().transform.position(vec3(0, 0, 3));
    current_scene->getCamera().setName("Camera 1");
    cameras.push_back(&current_scene->getCamera());
}

void Editor::update(float delta) {
    Scene::update(delta);
    current_scene->update(delta);
}

void createTree(const std::vector<SpacialEntity *> &vector, Transform *parent, int &index,
                std::set<SpacialEntity *> &selectedEntities, SpacialScene *current_scene, float &posX, float &posY,
                float &posZ, float &rotX, float &rotY, float &rotZ, float &sizeX, float &sizeY, float &sizeZ) {
    for (auto iter : vector) {
        if (iter->transform.parent == parent) {
            if (ImGui::TreeNode((void *) (intptr_t) index, iter->getName().c_str(), index++)) {
                if (ImGui::IsItemClicked()) {
                    if (!current_scene->getInput().isKeyDown(GLFW_KEY_LEFT_CONTROL))
                        selectedEntities.clear();
                    selectedEntities.emplace(iter);

                    if(!selectedEntities.empty()) {
                        vec3 pos = (*(selectedEntities.begin()++))->transform.localPosition();
                        posX = pos[0];
                        posY = pos[1];
                        posZ = pos[2];
                        vec3 rot = (*(selectedEntities.begin()++))->transform.eulerRotation();
                        rotX = rot[0];
                        rotY = rot[1];
                        rotZ = rot[2];
                        vec3 size = (*(selectedEntities.begin()++))->transform.scale();
                        sizeX = size[0];
                        sizeY = size[1];
                        sizeZ = size[2];
                    }
                }
                createTree(vector, &iter->transform, index, selectedEntities, current_scene, posX, posY, posZ, rotX, rotY, rotZ, sizeX, sizeY, sizeZ);
                ImGui::TreePop();
            }
        }
    }
}

void Editor::draw() const {

    ImGuiID dockspaceID = 0;
    float h, w;
    w = canvas->getPixelWidth();
    h = canvas->getPixelHeight();
    Scene::draw();
    ImGui::SetNextWindowPos(ImVec2(0, 0));
    ImGui::SetNextWindowSize(ImVec2(w, h), 0);
    ImGui::Begin("EDITOR");
    {
        dockspaceID = ImGui::GetID("HUB_DockSpace");
        ImGui::DockSpace(dockspaceID, ImVec2(0.0f, 0.0f),
                         0/* ImGuiDockNodeFlags_None|ImGuiDockNodeFlags_PassthruCentralNode|ImGuiDockNodeFlags_NoResize*/);
    }
    ImGui::End();


    for (int i = 0; i < cameras.size(); ++i) {
        ImGui::SetNextWindowDockID(dockspaceID, ImGuiCond_FirstUseEver);
        ImGui::Begin(std::string("Camera " + std::to_string(i + 1)).c_str());
        {
            current_scene->draw();
            cameras_canvas[i]->getFrameBuffer().bind();
            renderer->clear();
            cameras_canvas[i]->getFrameBuffer().unbind();
            current_scene->setCamera(*cameras[i]);
            renderer->renderSpace(cameras_canvas[i]->getFrameBuffer(),cameras[i]->getProjectionMatrix(),cameras[i]->getViewMatrix());

            Camera::ProjectionMode mode = current_scene->getCamera().getProjectionMode();
            ImGui::BeginChild("Projection");
            if (ImGui::Button(mode == Camera::ProjectionMode::PERSPECTIVE ? "Perspective" : "Orthographic")) {
                if (mode == Camera::ORTHOGRAPHIC)
                    current_scene->getCamera().setProjectionPerspective();
                else
                    current_scene->getCamera().setProjectionOrtho(10, 10);
            }
            ImGui::EndChild();
            ImVec2 vMin = ImGui::GetWindowContentRegionMin();
            ImVec2 vMax = ImGui::GetWindowContentRegionMax();
            if (vMax.x != cameras_canvas[i]->getPixelWidth() ||
                vMax.y != cameras_canvas[i]->getPixelHeight())
                cameras_canvas[i]->setSize(vMax.x, vMax.y);
            vMin.x += ImGui::GetWindowPos().x;
            vMin.y += ImGui::GetWindowPos().y;
            vMax.x += ImGui::GetWindowPos().x;
            vMax.y += ImGui::GetWindowPos().y;
            ImGui::GetWindowDrawList()->AddImage(
                    (void *) cameras_canvas[i]->getFrameBuffer().getTexture().getID(),
                    vMin,
                    vMax,
                    ImVec2(0, 1),
                    ImVec2(1, 0));
        }
        ImGui::End();
    }


    ImGui::SetNextWindowDockID(dockspaceID, ImGuiCond_FirstUseEver);
    ImGui::Begin("Transform");
    {

        for (auto iter : selectedEntities) {
            (*iter).transform.position(vec3(posX, posY, posZ));
            quat quaternion = quat(vec3(rotX, rotY, rotZ));
            if(activeRotation)
                (*iter).transform.rotation(quaternion);
            if (sizeX != 0 && sizeY != 0 && sizeZ != 0)
                (*iter).transform.scale(vec3(sizeX, sizeY, sizeZ));
        }

        ImGui::PushItemWidth(100);
        if (!selectedEntities.empty()) {
            vec3 pos = (*(selectedEntities.begin()++))->transform.localPosition();
            posX = pos[0];
            posY = pos[1];
            posZ = pos[2];
            vec3 rot = (*(selectedEntities.begin()++))->transform.eulerRotation();
            rotX = rot[0];
            rotY = rot[1];
            rotZ = rot[2];

            vec3 size = (*(selectedEntities.begin()++))->transform.scale();
            sizeX = size[0];
            sizeY = size[1];
            sizeZ = size[2];
        }

        ImGui::InputFloat("x", &posX, 0.1f, 0.1f);
        ImGui::SameLine();
        ImGui::InputFloat("y", &posY, 0.1f, 0.1f);
        ImGui::SameLine();
        ImGui::InputFloat("z", &posZ, 0.1f, 0.1f);
        ImGui::Checkbox("Active rotation", &activeRotation);
        ImGui::InputFloat("rot x", &rotX, 0.1f, 0.1f);
        ImGui::SameLine();
        ImGui::InputFloat("rot y", &rotY, 0.1f, 0.1f);
        ImGui::SameLine();
        ImGui::InputFloat("rot z", &rotZ, 0.1f, 0.1f);
        ImGui::InputFloat("size x", &sizeX, 0.1f, 0.1f);
        ImGui::SameLine();
        ImGui::InputFloat("size y", &sizeY, 0.1f, 0.1f);
        ImGui::SameLine();
        ImGui::InputFloat("size z", &sizeZ, 0.1f, 0.1f);
    }
    ImGui::End();

    ImGui::SetNextWindowDockID(dockspaceID, ImGuiCond_FirstUseEver);
    ImGui::Begin("Create things");
    {
        std::list<SpacialEntity *> parents;
        for (auto iter : current_scene->getSpacialEntities()) {
            if (iter->transform.parent == nullptr)
                parents.push_back(iter);
        }
        if (ImGui::TreeNode("Elements")) {
            int index = 0;

            if(ImGui::IsItemClicked())
                selectedEntities.clear();
            createTree(current_scene->getSpacialEntities(), nullptr, index, selectedEntities, current_scene, posX, posY,
                       posZ , rotX, rotY, rotZ, sizeX, sizeY, sizeZ);
            ImGui::TreePop();
        }

        if (ImGui::Button("Cube")) {
            SpacialEntity *entity;
            current_scene->addEntity(
                    entity = new MeshRenderer(renderer->CUBE, renderer->DEFAULT_SPACIAL_MATERIAL, vec3(0, 0, 0),
                                              vec3(0,0,0), vec3(1, 1, 1)));
            entity->setName("Entity: " + std::to_string(current_scene->getSpacialEntities().size()));
            if (selectedEntities.size() == 1) {
                entity->transform.parent = &(*selectedEntities.begin())->transform;
            }
        }

        if (ImGui::Button("Sphere")) {
            SpacialEntity *entity;
            current_scene->addEntity(
                    entity = new MeshRenderer(renderer->SPHERE, renderer->DEFAULT_SPACIAL_MATERIAL, vec3(0, 0, 0),
                                              vec3(0,0,0), vec3(1, 1, 1)));
            entity->setName("Entity: " + std::to_string(current_scene->getSpacialEntities().size()));
            if (selectedEntities.size() == 1) {
                entity->transform.parent = &(*selectedEntities.begin())->transform;
            }

        }
        if (ImGui::Button("Camera")) {
            Camera *entity;
            current_scene->addEntity(
                    entity = new Camera());
            entity->setName("Camera: " + std::to_string(cameras.size() + 1));
            if (selectedEntities.size() == 1) {
                entity->transform.parent = &(*selectedEntities.begin())->transform;
            }
            cameras_canvas.push_back(new Canvas(*canvas, renderer->DEFAULT_CANVAS_SHADER, 1, 1));
            cameras.push_back(entity);
        }
        if(ImGui::Button("Delete")) {
            for (auto entity : selectedEntities) {
                if(entity->getName()[0] != 'C')
                    current_scene->removeEntity(entity);
            }


            selectedEntities.clear();
        }

        std::string text;
        for (auto iter : selectedEntities)
            text += iter->getName();
        if (!selectedEntities.empty())
            ImGui::Text(text.c_str());
    }
    ImGui::End();

}









