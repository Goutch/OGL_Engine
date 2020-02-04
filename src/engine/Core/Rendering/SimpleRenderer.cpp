
#define GLEW_STATIC

#include <GL/glew.h>
#include "SimpleRenderer.h"
#include <Shaders/Material.h>
#include <Data/FBO.h>
#include "Geometry/VAO.h"
#include <Entities/Transform.h>

void SimpleRenderer::draw(const VAO &vao, const Material &material, const Transform& transform) {
    render_queue.emplace(&material,&vao,&transform);
}

void SimpleRenderer::render(const FBO &buffer, const mat4 &projection, const mat4 &view_mat) {
    glEnable(GL_DEPTH_TEST);
    buffer.bind();
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());
    clear();
    while(!render_queue.empty()) {
        std::tuple<const Material*,const VAO*,const Transform *>& renderableObject=render_queue.front();
        const Material& material=*std::get<0>(renderableObject);
        const VAO& vao=*std::get<1>(renderableObject);
        const Transform& transform=*std::get<2>(renderableObject);

        material.bind();
        material.projection(projection);
        material.view(view_mat);
        material.transform(transform.getMatrix());
        vao.bind();
        glDrawElements(GL_TRIANGLES,vao.getVertexCount(),GL_UNSIGNED_INT,nullptr);
        vao.unbind();
        material.unbind();

        render_queue.pop();
    }
    buffer.unbind();
}

void SimpleRenderer::renderDepth(const FBO &buffer, const glm::mat4 &depth_space_mat) {
    glEnable(GL_DEPTH_TEST);
    buffer.bind();
    glViewport(0, 0, buffer.getTexture().getWidth(), buffer.getTexture().getHeight());
    clearDepth();
    DEPTH_SHADER.bind();
    DEPTH_SHADER.loadUniform(depthShader_light_space_matrix_location, depth_space_mat);
    while(!render_queue.empty()) {
        std::tuple<const Material*,const VAO*,const Transform *>& renderableObject=render_queue.front();
        const Material& material=*std::get<0>(renderableObject);
        const VAO& vao=*std::get<1>(renderableObject);
        const Transform& transform=*std::get<2>(renderableObject);

        DEPTH_SHADER.loadUniform(depthShader_transform_mat_location, transform.getMatrix());
        vao.bind();
        glDrawElements(GL_TRIANGLES,vao.getVertexCount(),GL_UNSIGNED_INT,nullptr);
        vao.unbind();
        render_queue.pop();
    }
    DEPTH_SHADER.unbind();
    buffer.unbind();
}

void SimpleRenderer::renderUI(const FBO &buffer, const mat4 &projection) {

}

void SimpleRenderer::drawUI(const VAO &vao, const Material &material, const Transform &transform) {

}




