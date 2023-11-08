#include "TextureManager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

std::map<std::string, std::pair<GLuint, int>> TextureManager::textures = std::map<std::string, std::pair<GLuint, int>>();

GLuint TextureManager::getTextureFromFile(std::string fileName)
{
	if (textures.find(fileName) != textures.end()) {
		textures[fileName].second++;
		return textures[fileName].first;
	}
	
	int texWidth, texHeight;
	int channelInFile;

	unsigned char* data = stbi_load(fileName.c_str(), &texWidth, &texHeight, &channelInFile, 4);
	if (*data == NULL) {
		return NULL;
	}

	GLuint texID;

	glGenTextures(1, &texID);
	glBindTexture(GL_TEXTURE_2D, texID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texWidth, texHeight, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	textures.insert({ fileName, {texID, 1} });
	return texID;
}

void TextureManager::dereferenceTexture(std::string fileName)
{
	if (textures.size() == 0) return;
	if (textures.find(fileName) != textures.end()) {
		if (textures[fileName].second == 1) {
			glDeleteTextures(1, &textures[fileName].first);
			textures.erase(fileName);
		}
		textures[fileName].second--;
	}
}
