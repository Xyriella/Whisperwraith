#pragma once
#include <glm/ext/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

struct Vertex {
	glm::vec3 position;
	glm::vec2 texCoord;
};

struct Transform {
	glm::vec3 position = {0.0f, 0.0f, 0.0f};
	glm::vec3 rotation = { 0.0f, 0.0f, 0.0f };
	glm::vec3 scale = { 1.0f, 1.0f, 1.0f };

	glm::mat4 getModelMatrix() {
		glm::mat4 translateMat = glm::translate(glm::mat4(), position);
		glm::mat4 scaleMat = glm::scale(glm::mat4(), scale);
		glm::mat4 rotationMat = glm::yawPitchRoll(rotation.y, rotation.x, rotation.z);
		return translateMat * rotationMat * scaleMat;
	}
};