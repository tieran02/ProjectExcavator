#pragma once
#include "Asset.h"
#include <glad/glad.h>
#include <Math/Math.h>

class ShaderAsset : public Asset
{
public:
	ShaderAsset(const char* name, const char* vertexSourchPath, const char* fragmentSourcePath, bool isFile);
	~ShaderAsset() override;

	void Load() override;
	void Bind() const;
	void Unbind() const;

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


	GLuint GetProgramID() const;
private:
	void compile();
	unsigned int program;
	const char* m_vertexSourchPath; 
	const char* m_fragmentSourcePath; 
	bool m_isFile;
};
