#pragma once
#include "glm/glm.hpp"
class Camera
{
public:
	Camera(const float& aspectRatio, const float& FOV = 103.0f, const float& minPitchDegrees = -89.9f, const float& maxPitchDegrees = 0.0f);
	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();

	void setFOV(const float& FOV);
	void setAspectRatio(const float& aspectRatio);
	void setAspectRatio(const int& width, const int& height);
	void scaleDistance(const float& scale);
	void setDistance(const float& distance);
	void addDistance(const float& offset);
	void setCentre(const glm::vec3& newCentre);
	void setRotation(const float& newYaw, const float& newPitch);
	void setYawDegrees(const float& newYaw);
	void setPitchDegrees(const float& newPitch);
	void addYaw(const float& yawOffset);
	void addPitch(const float& pitchOffset);
	void setMaxPitchDegrees(const float& newMaxPitch);
	void setMinPitchDegrees(const float& newMinPitch);
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
	float maxPitch, minPitch;
	float maxDistance, minDistance;
};

