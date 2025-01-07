#include <iostream>
#include <fstream>
#include <sstream>
#include "Shader.h"

Shader::Shader(const std::string & vertexPath, const std::string & fragPath) {

    // Read in the shader code 
    std::string vertexCode;
    std::ifstream vShaderFile;
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        vShaderFile.open(vertexPath);
        std::stringstream vShaderStream;
        vShaderStream << vShaderFile.rdbuf();
        vShaderFile.close();
        vertexCode = vShaderStream.str();
    } catch (std::ifstream::failure e) {
        std::cerr << "Shader::Shader() -> vShaderFile not read" << std::endl;
        return;
    }
    
    std::string fragmentCode;
    std::ifstream fShaderFile;
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);

    try {
        fShaderFile.open(fragPath);
        std::stringstream fShaderStream;
        fShaderStream << fShaderFile.rdbuf();
        fShaderFile.close();
        fragmentCode = fShaderStream.str();
    } catch (std::istream::failure e) {
        std::cerr << "Shader::Shader() -> fShaderFile not read" << std::endl;
        return;
    }

    // Convert from string to char *
    
    const char * vShaderCode = vertexCode.c_str();
    const char * fShaderCode = fragmentCode.c_str();
    

    // Compile the shaders
    unsigned int vertex, fragment;
    int success;
    char infoLog[512];

    // Vertex Shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);

    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cerr << "Shader::Shader() -> vShader compilation failed: " << infoLog << std::endl;
    }

    // Fragment Shader
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);

    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cerr << fShaderCode << std::endl;
        std::cerr << "Shader::Shader() -> fShader compilation failed: " << infoLog << std::endl;
    }

    // Create the shader program
    progID = glCreateProgram();
    glAttachShader(progID, vertex);
    glAttachShader(progID, fragment);
    glLinkProgram(progID);

    glGetShaderiv(progID, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(progID, 512, NULL, infoLog);  
        std::cerr << "Shader::Shade() -> Linking failed: " << infoLog << std::endl;
    }
}


void Shader::use() const {
    glUseProgram(progID);
}


unsigned int Shader::ID() const {
    return progID;
}


void Shader::setBool(const std::string & name, bool value) const {
    glUniform1i(glGetUniformLocation(progID, name.c_str()), (int) value);
}


void Shader::setInt(const std::string & name, int value) const {
    glUniform1i(glGetUniformLocation(progID, name.c_str()), value);
}


void Shader::setFloat(const std::string & name, float value) const {
    glUniform1f(glGetUniformLocation(progID, name.c_str()), value);
}
