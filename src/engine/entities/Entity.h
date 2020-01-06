#pragma once




#include "Transform.h"
class Renderer;
class EntityShader;
class Transform;
class VAO;
class Window;
class Entity{
public:
    Entity(vec3 position){transform.translate(position);};
    Transform transform;
    virtual void render(Renderer& renderer)=0;
    virtual void update(float delta,Window& window)=0;

};