//
// Created by User on 2020-01-06.
//

#include "Entity.h"
Entity::Entity(vec3 position, vec3 rotation, vec3 scale) {
    transform.translate(position);
    transform.rotate(quat(rotation));
    transform.scale(scale);
}


void Entity::draw(const Scene &scene) const{

}
void Entity::update(float delta,Scene &scene) {

}

void Entity::init(Scene &scene) {

}

void Entity::destroy(Scene& scene) {

}
