#pragma  once

#include <Core/Scene.h>
#include <Data/Texture.h>
#include <Data/AtlasTexture.h>
#include <Shaders/Spacial/SpacialMaterial.h>
#include <Geometry/Mesh.h>
#include <Shaders/Canvas/FontMaterial.h>
#include "Entities/Spacial/Transform.h"
#include <Events/KeyPressListener.h>
#include <Shaders/Shader.h>
class TextTest : public Scene{
    Transform transform = Transform();
    Shader shader = Shader("../src/engine/Shaders/ShadersSources/TextVertex.glsl",
                           "../src/engine/Shaders/ShadersSources/TextFragment.glsl");
    FontMaterial font = FontMaterial(shader,"../res/consolas.bmp",128, 128);

public:
    void init(const Canvas &viewport, Renderer &renderer, Window &window) override;

};


