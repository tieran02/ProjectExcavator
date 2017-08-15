#include <Resources/ShaderAsset.h>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Debug/Debug.h"

ShaderAsset::ShaderAsset(const char* name, const char* vertexSourchPath, const char* fragmentSourcePath, bool isFile) : m_vertexSourchPath(vertexSourchPath),
m_fragmentSourcePath(fragmentSourcePath), m_isFile(isFile), Asset(AssetType::SHADER,name)
{
	compile();
}

ShaderAsset::~ShaderAsset()
{
	glDeleteProgram(this->program);
	LOG_INFO("Shader '" << this->GetName() << "' Deleted");

}

void ShaderAsset::Load()
{
}

void ShaderAsset::Bind() const
{
	glUseProgram(this->program);
}


void ShaderAsset::Unbind() const
{
	glUseProgram(0);
}

void ShaderAsset::SetUniform(const char *uniformName, int value) const {
	glUniform1i(GetUniformLocationByName(uniformName), value);
}

void ShaderAsset::SetUniform(const char *uniformName, unsigned int value) const {
	glUniform1i(GetUniformLocationByName(uniformName), value);
}

int ShaderAsset::GetUniformLocationByName(const char *uniformName) const {
	return glGetUniformLocation(program, uniformName);
}

void ShaderAsset::SetUniform(const char *uniformName, float value) const {
	glUniform1f(GetUniformLocationByName(uniformName), value);
}

void ShaderAsset::SetUniform(const char *uniformName, Vector2 value) const {
	glUniform2f(GetUniformLocationByName(uniformName), value.x, value.y);
}

void ShaderAsset::SetUniform(const char *uniformName, Vector3 value) const {
	glUniform3f(GetUniformLocationByName(uniformName), value.x, value.y, value.z);
}

void ShaderAsset::SetUniform(const char *uniformName, Vector4 value) const {
	glUniform4f(GetUniformLocationByName(uniformName), value.x, value.y, value.z, value.w);
}

void ShaderAsset::SetUniform(const char *uniformName, Matrix3 value, int count, bool transpose) const {
	glUniformMatrix3fv(GetUniformLocationByName(uniformName), count, transpose, &value[0][0]);
}

void ShaderAsset::SetUniform(const char *uniformName, Matrix4 value, int count, bool transpose) const {
	glUniformMatrix4fv(GetUniformLocationByName(uniformName), count, transpose, &value[0][0]);
}

GLuint ShaderAsset::GetProgramID() const {
	return this->program;
}

void ShaderAsset::compile()
{
	std::string vertexCode;
	std::string fragmentCode;
	if (m_isFile) {
		// 1. Retrieve the vertex/fragment source code from filePath
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		// ensures ifstream objects can throw exceptions:
		vShaderFile.exceptions(std::ifstream::badbit);
		fShaderFile.exceptions(std::ifstream::badbit);
		try
		{
			// Open files
			vShaderFile.open(m_vertexSourchPath);
			fShaderFile.open(m_fragmentSourcePath);
			std::stringstream vShaderStream, fShaderStream;
			// Read file's buffer contents into streams
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			// close file handlers
			vShaderFile.close();
			fShaderFile.close();
			// Convert stream into string
			vertexCode = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			LOG_ERROR("SHADER::FILE_NOT_SUCCESFULLY_READ");
		}
	}
	else
	{
		vertexCode = m_vertexSourchPath;
		fragmentCode = m_fragmentSourcePath;
	}
	const GLchar* vShaderCode = vertexCode.c_str();
	const GLchar * fShaderCode = fragmentCode.c_str();
	// 2. Compile shaders
	GLuint vertex, fragment;
	GLint success;
	GLchar infoLog[512];
	// Vertex Shader
	vertex = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertex, 1, &vShaderCode, NULL);
	glCompileShader(vertex);
	// Print compile errors if any
	glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertex, 512, NULL, infoLog);
		LOG_ERROR("SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog);
	}
	// Fragment Shader
	fragment = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragment, 1, &fShaderCode, NULL);
	glCompileShader(fragment);
	// Print compile errors if any
	glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragment, 512, NULL, infoLog);
		LOG_ERROR("SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog);
	}
	// Shader Program
	this->program = glCreateProgram();
	glAttachShader(this->program, vertex);
	glAttachShader(this->program, fragment);
	glLinkProgram(this->program);
	// Print linking errors if any
	glGetProgramiv(this->program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(this->program, 512, NULL, infoLog);
		LOG_ERROR("SHADER::PROGRAM::LINKING_FAILED\n" << infoLog);
	}
	// Delete the shaders as they're linked into our program now and no longer necessery
	glDeleteShader(vertex);
	glDeleteShader(fragment);
	LOG_INFO("Shader '" << program << "' sucessfully compiled and linked");
}
