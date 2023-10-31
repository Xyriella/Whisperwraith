#include "Mesh.h"
#include "glm/ext/matrix_transform.hpp"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

Mesh::Mesh(const GLuint& program, const std::vector<int>& indices, const std::vector<Vertex>& vertices) : program(program), vertices(vertices), indices(indices)
{

	transform = { {0.0f, 0.0f, 0.0f},{0.0f, 0.0f,0.0f},{1.0f, 1.0f, 1.0f} };

	glGenBuffers(1, &VBO);
	glGenBuffers(1, &IBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertices.size(), vertices.data(), GL_STATIC_DRAW);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(int) * indices.size(), indices.data(), GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)12);

	transformLoc = glGetUniformLocation(program, "transform");
	assert(transformLoc != 0xFFFFFFFF);
}

void Mesh::tick(float deltaTime)
{
	
}

void Mesh::render()
{
	glm::mat4 transform = this->transform.getModelMatrix();

	glUseProgram(program);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, IBO);
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);

	glUniformMatrix4fv(transformLoc, 1, GL_FALSE, &transform[0][0]);
	
	glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);

	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
}
