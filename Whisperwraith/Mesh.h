#pragma once
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <vector>

class Mesh
{
public:
	Mesh(GLuint program);
	void tick(float deltaTime);
	void render();
private:
public:
private:
	GLuint VBO;
	GLuint program;
	float scale;
	GLuint scaleUniformLoc;
	std::vector<glm::vec3> Vertices;
};

