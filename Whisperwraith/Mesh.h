#pragma once
#include <glad/gl.h>
#include <glm/glm.hpp>
#include <vector>
#include "utils.h"
#include "Camera.h"

class Mesh
{
public:
	Mesh(const GLuint& program, const std::vector<int>& indices, const std::vector<Vertex>& vertices);
	void tick(float deltaTime);
	void render(Camera& camera);
private:
public:
private:
	GLuint VBO;
	GLuint IBO;
	GLuint program;
	GLuint transformLoc;
	GLuint texID;
	GLuint samplerLoc;

	std::vector<Vertex> vertices;
	std::vector<int> indices;
	Transform transform;
};

