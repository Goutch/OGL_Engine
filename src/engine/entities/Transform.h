#pragma once

#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
class Transform {
    glm::mat4 transform_mattrix=glm::mat4(1.0f);
public:
    glm::mat4 getTransformMatrix();
    void translate(glm::vec3 translation);
    void rotate(glm::vec3 axis, float angle);
    Transform();


};


