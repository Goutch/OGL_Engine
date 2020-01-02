#pragma once

#include <string>
#include "glm/glm.hpp"
class mat4;
class vec3;
class vec4;
class ShaderProgram {
protected:
    unsigned int program_id;

    unsigned int compileShader(unsigned int type, const std::string &source);

    std::string getSource(const std::string &path);

public:

    void unbind();

    ShaderProgram(const std::string &vertexShader, const std::string &fragmentShader);

    ~ShaderProgram();


    void bind();

protected:
    void loadIntUniform(unsigned int location, int i);

    void loadFloatUniform(unsigned int location, float f);


    void loadVectorUniform(unsigned int location, const vec3 &v);

    void loadVectorUniform(unsigned int location, const vec4 &v);


    void loadMat4Uniform(unsigned int location, const mat4 &m);

};

