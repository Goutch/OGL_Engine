#pragma once

#include <Geometry/Mesh.h>
#include <Shaders/LightMaterial.h>
#include <Data/Texture.h>
#include "Core/Scene.h"
#include "Geometry/Geometry.h"
class FullSceneTest :public Scene{
    Shader shader=Shader("../src/engine/Shaders/shadersSources/DefaultVertex.glsl",
                         "../src/engine/Shaders/shadersSources/DefaultFragment.glsl");
    Shader lightShader=Shader("../src/engine/Shaders/shadersSources/LightVertex.glsl",
                              "../src/engine/Shaders/shadersSources/LightFragment.glsl");

    Material dragon_material=Material(shader,Color::RED);
    Texture ground_texture=Texture("../res/wall.jpg");
    LightMaterial ground_material=LightMaterial(lightShader,ground_texture,Color::WHITE);
    Mesh dragon=Mesh("../res/dragon.obj");
    Mesh plane;
    Mesh cube;


public:
    void init(Window &window, Renderer &renderer) override;

};

