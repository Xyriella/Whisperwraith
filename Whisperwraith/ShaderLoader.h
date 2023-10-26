#pragma once
#include <glad/gl.h>
#include <string>
#include <map>

class ShaderLoader
{
public:
	static GLuint GetShaderProgram(const std::string& vertShaderName, const std::string& fragShaderName);
private:
	ShaderLoader();
	static GLuint LoadShaderObject(const std::string& shaderName, GLenum shaderType);
public:
private:
	static std::map<std::string, GLuint> shaderPrograms;
};

