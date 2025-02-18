#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <string>

class Shader {
public:
    unsigned int progID;   

    Shader(const std::string & vertexFilePath, const std::string & fragFilePath);
    void use() const;

    unsigned int ID() const;

    void setBool(const std::string & name,  bool value) const;
    void setInt(const std::string & name,   int value) const;
    void setFloat(const std::string & name, float  value) const;
};

#endif
