
#pragma once

#include "Entities/Spacial/SpacialEntity.h"
#include "Ressources/Color.h"
class Light: public SpacialEntity {
protected:
    Color color=Color::WHITE;
public:
    Light(const Color& color,vec3 position,vec3 rotation=vec3(0),vec3 scale=vec3(1));
    Light(vec3 position,vec3 rotation=vec3(0),vec3 scale=vec3(1));
    Light(const Color& color);
    Light();
    const Color& getColor();

};
