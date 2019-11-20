#pragma once

#include <vector>
#include "core/Game.h"
#include "graphics/shaders/ShaderProgram.h"
#include "graphics/Mesh.h"

class Window;

class Entity;

class Test : public Game {
private:
    std::vector<Entity *> entities;
    Mesh* quad;
    ShaderProgram* shader;
public:
    Test();

    ~Test();

    void init() override;

    void update(Window &window) override;

    void render(Renderer &renderer) override;
};


