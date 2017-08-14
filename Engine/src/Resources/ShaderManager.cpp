#include "Resources/ShaderManager.h"
#include "Debug/Debug.h"

void ShaderManager::AddShader(const char *shaderName, const char *vertextFilePath, const char *fragementFilePath, bool isFile) {
    auto it = m_shaderMap.find(shaderName);
    if (it == m_shaderMap.end())
    {
        //Add new scene to scene map and load it
        m_shaderMap.emplace(std::piecewise_construct, std::make_tuple(shaderName), std::make_tuple(vertextFilePath,fragementFilePath, isFile));
    }else{
		std::string error = "Shader '";
		error.append(it->first);
		error.append("' alredy added");
		Debug::Log(LogLevel::logWARNING, error);
    }
}

Shader *ShaderManager::GetShader(const char *shaderName) {
	auto it = this->m_shaderMap.find(shaderName);
	if (it != m_shaderMap.end())
	{
		//Texture does exist
		return &this->m_shaderMap[shaderName];
	}
	else {
		Debug::Log(LogLevel::logERROR, static_cast<std::string>("Shader doesn't exist! ") += shaderName);
	}
	return nullptr;
}

void ShaderManager::Destroy() {
	if (this != nullptr) {
		this->m_shaderMap.clear();
	}
}

void ShaderManager::DeleteShader(const char *name) {
    auto it = this->m_shaderMap.find(name);
    if (it != m_shaderMap.end())
    {
        auto shader = it->second.GetProgramID();
		Debug::Log(LogLevel::logINFO, static_cast<std::string>("Deleted shader - ") += it->first);
		glDeleteProgram(shader);
        it = this->m_shaderMap.erase(it);
    }else
		Debug::Log(LogLevel::logERROR, static_cast<std::string>("Shader doesn't exist - ") += name);
}

void ShaderManager::AddDefaultShaders()
{
	const char* spriteVert = R""(
	#version 330 core
	layout (location = 0) in vec3 aPos;
	layout (location = 1) in vec2 aTexCoord;

	out vec2 TexCoord;

	uniform mat4 view;

	void main()
	{
		gl_Position = view * vec4(aPos, 1.0f);
		TexCoord = aTexCoord;
	}
	)"";

	const char* spriteFrag = R""(
	#version 330 core
	out vec4 FragColor;

	in vec2 TexCoord;

	uniform vec3 color = vec3(1,1,1);
	uniform sampler2D texture1;

	void main()
	{
		FragColor = texture(texture1, TexCoord) * vec4(color, 1.0);
	}
	)"";

	AddShader("sprite", spriteVert, spriteFrag, false);
}
