#pragma once

#include "Entity.h"
class Mesh;
class MeshRenderer :public Entity{
    EntityShader* shader;
    VAO* mesh;
public:
    MeshRenderer(VAO& mesh, EntityShader& shader, vec3 position,vec3 rotation,vec3 scale);

    EntityShader &getShader();

    VAO &getVAO();

private:
    void render(Renderer &renderer) override;

    void update(float delta, Window &window) override;
};


