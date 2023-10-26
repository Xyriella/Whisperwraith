#include "Mesh.h"

Mesh::Mesh(GLuint program) : program(program), scale(1.0f)
{
	Vertices = std::vector<glm::vec3>({ {-1.0f, -1.0f, 0.0f},{1.0f,-1.0f, 0.0f},{0.0f, 1.0f, 0.0f} });
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(glm::vec3) * Vertices.size(), Vertices.data(), GL_STATIC_DRAW);
	scaleUniformLoc = glGetUniformLocation(program, "scale");
	assert(scaleUniformLoc != 0xFFFFFFFF);
}

void Mesh::tick(float deltaTime)
{
	scale += deltaTime;
}

void Mesh::render()
{
	glUseProgram(program);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glEnableVertexAttribArray(0);

	glUniform1f(scaleUniformLoc, sinf(scale));

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	glDrawArrays(GL_TRIANGLES, 0, 3);

	glDisableVertexAttribArray(0);
}
