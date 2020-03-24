//
// Created by User on 2020-03-22.
//

#include "Plane.h"
Plane::Plane(){}
Plane::Plane(glm::vec4 equation) {
    set(equation);
}
void Plane::set(glm::vec4 equation){
    this->normal = glm::vec3(equation.x, equation.y, equation.z);
    float l=glm::length(normal);
    normal/=l;
    this->d = equation.w/l;
}

float Plane::distance(const glm::vec3 &point) const{
    return (normal.x * point.x) + (normal.y * point.y) + (normal.z * point.z)+d;
}
