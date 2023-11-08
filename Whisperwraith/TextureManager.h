#pragma once
#include <map>
#include <glad/gl.h>
#include <string>
class TextureManager
{
public:
	static GLuint getTextureFromFile(std::string fileName);
	static void dereferenceTexture(std::string fileName);
private:
public:
private:
	static std::map < std::string, std::pair<GLuint, int>> textures;
};

