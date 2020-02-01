#pragma  once

#include <Core/Scene.h>
#include <Data/Texture.h>
#include <Data/AtlasTexture.h>
#include <Shaders/Material.h>
#include <Geometry/Mesh.h>
#include "Entities/Transform.h"
class LAB2 : public Scene{
    Transform transform = Transform();
    Shader shader = Shader("../src/engine/Shaders/shadersSources/DefaultVertex.glsl",
                           "../src/engine/Shaders/shadersSources/DefaultFragment.glsl");
    Texture texture = Texture("../res/wall.jpg", false);
    AtlasTexture font = AtlasTexture("../res/font.bmp", 64, 64, false);
    Material material = Material(shader, font);
    Material defaultMat = Material(shader);
    unsigned int counter=0;
    Mesh vao;
public:
    void init(Viewport &viewport, Renderer &renderer, Window &window) override;

    void render() const override;

    void update(float delta) override;
};


