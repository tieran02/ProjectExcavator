#pragma once

#include <Math/Vector2.h>
#include <Math/Vector3.h>
#include <Math/Vector4.h>
#include <Math/Matrix3.h>
#include <Math/Matrix4.h>
#include <glad/glad.h>

class Shader
{
public:
    Shader(){};
	Shader(const char* vertexSourchPath, const char* fragmentSourcePath, bool isFile);

    void CompileFromFile(const char* vertexSourchPath, const char* fragmentSourcePath, bool isFile);

    //Bind the Program
    void Bind() const;
    //Unbind the program
    void Unbind();

    //Get the location of a uniform using the uniforms name within the shader.
    int GetUniformLocationByName(const char* uniformName) const;

    //Set a int value for a uniform variable within a shader
    void SetUniform(const char* uniformName, GLint value) const;
    //Set a uint value for a uniform variable within a shader
    void SetUniform(const char* uniformName, GLuint value) const;
    //Set a float value for a uniform variable within a shader
    void SetUniform(const char* uniformName, GLfloat value) const;
    //Set a vec2 value for a uniform variable within a shader
    void SetUniform(const char* uniformName, Vector2 value) const;
    //Set a vec3 value for a uniform variable within a shader
    void SetUniform(const char* uniformName, Vector3 value) const;
    //Set a vec4 value for a uniform variable within a shader
    void SetUniform(const char* uniformName, Vector4 value) const;
    //Set a mat3 value for a uniform variable within a shader
    void SetUniform(const char* uniformName, Matrix3 value, int count, bool transpose) const;
    //Set a mat4 value for a uniform variable within a shader
    void SetUniform(const char* uniformName, Matrix4 value, int count, bool transpose) const;

    unsigned GetProgramID() const;

private:
    // The program ID
    void compile();
    unsigned int program;
};
