#pragma once

#include <Rendering/Shader.h>
#include <unordered_map>

class ShaderManager {
public:
    void AddShader(const char* shaderName, const char* vertextFilePath, const char* fragementFilePath, bool isFile);
    Shader* GetShader(const char* shaderName);

    void Destroy();
    void DeleteShader(const char *name);

	void AddDefaultShaders();

private:
    std::unordered_map<const char*, Shader> m_shaderMap;
};
