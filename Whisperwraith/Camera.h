#pragma once
#include "glm/glm.hpp"
class Camera
{
public:
	Camera(float aspectRatio, float FOV);
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();

	void setFOV(const float& FOV);
	void setAspectRatio(const float& aspectRatio);
	void setAspectRatio(const int& width, const int& height);
	void scaleDistance(const float& scale);
	void setDistance(const float& distance);
	void addDistance(const float& offset);
	void setCentre(const glm::vec3& newCentre);
private:
	void updateViewMatrix();
	void updateProjectionMatrix();
public:
private:
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	glm::vec3 centre;
	float yaw, pitch;
	float distance;
	float aspectRatio;
	float FOV;
	float nearPlane;
	float farPlane;
};

