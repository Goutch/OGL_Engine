

#include <Geometry/Geometry.h>
#include "Text.h"
#include "Core/Rendering/Renderer.h"
#include "Core/Scene.h"


Text::Text(std::string text, const vec3 &position, FontMaterial &font) : Entity(position),font(font) {
    Geometry::make_text(mesh, text, font);
}
void Text::draw(const Scene &scene) const {
    Entity::draw(scene);
    scene.getRenderer().draw(mesh, font, transform);
}
