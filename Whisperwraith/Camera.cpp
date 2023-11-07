#include "Camera.h"
#include "glm/ext/matrix_transform.hpp"
#include <glm/ext/matrix_clip_space.hpp>
#include <glm/gtx/euler_angles.hpp>

Camera::Camera(const float& aspectRatio, const float& FOV, const float& minPitchDegrees, const float& maxPitchDegrees) : aspectRatio(aspectRatio), FOV(FOV)
{
	centre = { 0.0f, 0.0f, 0.0f };
	distance = 10.0f;
	minDistance = 2.0f;
	maxDistance = 40.0f;
	nearPlane = 0.01f;
	farPlane = 1000.0f;
	yaw = 0.0f;
	pitch = glm::pi<float>() / 2.0f;
	setMinPitchDegrees(minPitchDegrees);
	setMaxPitchDegrees(maxPitchDegrees);
	updateProjectionMatrix();
	updateViewMatrix();
}

glm::mat4 Camera::getViewMatrix()
{
	return viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix()
{
	return projectionMatrix;
}

void Camera::setFOV(const float& FOV)
{
	this->FOV = FOV;
	updateProjectionMatrix();
}

void Camera::setAspectRatio(const float& aspectRatio)
{
	this->aspectRatio = aspectRatio;
	updateProjectionMatrix();
}

void Camera::setAspectRatio(const int& width, const int& height)
{
	aspectRatio = ((float)width) / ((float)height);
	updateProjectionMatrix();
}

void Camera::scaleDistance(const float& scale)
{
	distance = glm::clamp(scale * distance, minDistance, maxDistance);
	updateViewMatrix();
}

void Camera::setDistance(const float& distance)
{
	this->distance = glm::clamp(distance, minDistance, maxDistance);
	updateViewMatrix();
}

void Camera::addDistance(const float& offset)
{
	distance = glm::clamp(distance + offset, minDistance, maxDistance);
	updateViewMatrix();
}

void Camera::setCentre(const glm::vec3& newCentre)
{
	centre = newCentre;
	updateViewMatrix();
}

void Camera::setRotation(const float& newYaw, const float& newPitch)
{
	yaw = newYaw;
	pitch = glm::clamp(newPitch, minPitch, maxPitch);
	updateViewMatrix();
}

void Camera::setYawDegrees(const float& newYaw)
{
	yaw = newYaw * glm::pi<float>() / 180.0f;
	updateViewMatrix();
}

void Camera::setPitchDegrees(const float& newPitch)
{
	pitch = glm::clamp(newPitch * glm::pi<float>() / 180.0f, minPitch, maxPitch);
	updateViewMatrix();
}

void Camera::addYaw(const float& yawOffset)
{
	yaw += yawOffset;
	updateViewMatrix();
}

void Camera::addPitch(const float& pitchOffset)
{
	pitch = glm::clamp(pitch + pitchOffset, minPitch, maxPitch);
	updateViewMatrix();
}

void Camera::setMaxPitchDegrees(const float& newMaxPitch)
{
	maxPitch = glm::max(minPitch + 0.01f, newMaxPitch * glm::pi<float>() / 180.0f);
	pitch = glm::clamp(pitch, minPitch, maxPitch);
	updateViewMatrix();
}

void Camera::setMinPitchDegrees(const float& newMinPitch)
{
	minPitch = glm::min(maxPitch + 0.01f, newMinPitch * glm::pi<float>() / 180.0f);
	pitch = glm::clamp(pitch, minPitch, maxPitch);
	updateViewMatrix();
}

void Camera::updateViewMatrix()
{
	//glm::mat4 transform = glm::rotate(glm::identity<glm::mat4>(), yaw, glm::vec3(0.0f, 1.0f, 0.0f)) * glm::rotate(glm::mat4(), pitch, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::mat4 transform = glm::yawPitchRoll(yaw, pitch, 0.0f);
	glm::vec4 offset = glm::vec4(0.0f, 0.0f, distance, 1.0f);
	glm::vec3 cameraPos = centre + glm::vec3(transform * offset);
	viewMatrix = glm::lookAt(cameraPos, centre, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::updateProjectionMatrix()
{
	projectionMatrix = glm::perspective(FOV, aspectRatio, nearPlane, farPlane);
}


