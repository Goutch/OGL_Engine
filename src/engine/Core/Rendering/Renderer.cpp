
#define GLEW_STATIC

#include "Renderer.h"
#include <GL/glew.h>
#include "Shaders/Shader.h"
#include <Data/Texture.h>
#include <Geometry/VAO.h>
#include "Shaders/Material.h"

void Renderer::clear() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::clearDepth() {
    glClear(GL_DEPTH_BUFFER_BIT);
}

void Renderer::clearColor() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const VAO &vao, const Material &material) {
    glDisable(GL_DEPTH_TEST);

    material.bind();
    material.transform(mat4(1));
    material.view(mat4(1));
    material.projection(mat4(1));
    vao.bind();
    glDrawElements(GL_TRIANGLES, vao.getVertexCount(), GL_UNSIGNED_INT, nullptr);
    vao.unbind();
    material.unbind();

}

void Renderer::draw(const VAO &vao, const Shader &shader, const Texture &texture) {
    glDisable(GL_DEPTH_TEST);
    shader.bind();
    vao.bind();
    texture.bind();
    glDrawElements(GL_TRIANGLES, vao.getVertexCount(), GL_UNSIGNED_INT, nullptr);
    texture.unbind();
    vao.unbind();
    shader.unbind();
}

void Renderer::draw(const VAO &vao, const Shader &shader) {
    glDisable(GL_DEPTH_TEST);
    shader.bind();
    vao.bind();
    glDrawElements(GL_TRIANGLES, vao.getVertexCount(), GL_UNSIGNED_INT, nullptr);
    vao.unbind();
    shader.unbind();
}

void Renderer::enableWireframe(bool enable) {
   enable? glPolygonMode( GL_FRONT_AND_BACK, GL_LINE ):  glPolygonMode( GL_FRONT_AND_BACK, GL_FILL );
}

