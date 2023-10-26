#include "ShaderLoader.h"
#include <fstream>
#include <iostream>

std::map<std::string, GLuint> ShaderLoader::shaderPrograms = std::map<std::string, GLuint>();

GLuint ShaderLoader::GetShaderProgram(const std::string& vertShaderName, const std::string& fragShaderName)
{
	std::string key = fragShaderName + vertShaderName;
	if (shaderPrograms.find(key) != shaderPrograms.end()) {
		return shaderPrograms[key];
	}
	GLuint shaderProgram = glCreateProgram();

	GLuint fragShader = LoadShaderObject(fragShaderName, GL_FRAGMENT_SHADER);
	GLuint vertShader = LoadShaderObject(vertShaderName, GL_VERTEX_SHADER);

	glAttachShader(shaderProgram, fragShader);
	glAttachShader(shaderProgram, vertShader);

	glLinkProgram(shaderProgram);

	glDetachShader(shaderProgram, fragShader);
	glDeleteShader(fragShader);

	glDetachShader(shaderProgram, vertShader);
	glDeleteShader(vertShader);

	GLint success;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

	if (!success) {
		GLchar infoLog[1024];
		glGetShaderInfoLog(shaderProgram, sizeof(infoLog), NULL, infoLog);
		std::cerr << "Error linking shader program: " << infoLog;
	}

	glValidateProgram(shaderProgram);
	shaderPrograms.emplace(key, shaderProgram);
	return shaderProgram;
}

GLuint ShaderLoader::LoadShaderObject(const std::string& shaderName, GLenum shaderType)
{
	std::ifstream shaderFileStream(shaderName);
	std::string shaderFileText((std::istreambuf_iterator<char>(shaderFileStream)), (std::istreambuf_iterator<char>()));
	shaderFileStream.close();

	GLuint shaderObj = glCreateShader(shaderType);
	GLint lengths[1];
	lengths[0] = shaderFileText.length();
	const char* shaderTextPtr = shaderFileText.c_str();
	glShaderSource(shaderObj, 1, &shaderTextPtr, lengths);

	glCompileShader(shaderObj);

	GLint success;
	glGetShaderiv(shaderObj, GL_COMPILE_STATUS, &success);

	if (!success) {
		GLchar infoLog[1024];
		glGetShaderInfoLog(shaderObj, sizeof(infoLog), NULL, infoLog);
		std::cerr << "Error compiling shader type " << shaderType << ": " << infoLog;
	}

	return shaderObj;
}
