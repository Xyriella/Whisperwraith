#include "Camera.h"
#include "glm/ext/matrix_transform.hpp"
#include <glm/ext/matrix_clip_space.hpp>

Camera::Camera(float aspectRatio, float FOV) : aspectRatio(aspectRatio), FOV(FOV)
{
	centre = { 0.0f, 0.0f, 0.0f };
	distance = 10.0f;
	nearPlane = 0.01f;
	farPlane = 1000.0f;
	yaw = 0.0f;
	pitch = glm::pi<float>() / 2.0f;
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
	distance *= scale;
	updateViewMatrix();
}

void Camera::setDistance(const float& distance)
{
	this->distance = distance;
	updateViewMatrix();
}

void Camera::addDistance(const float& offset)
{
	distance += offset;
	updateViewMatrix();
}

void Camera::setCentre(const glm::vec3& newCentre)
{
	centre = newCentre;
	updateViewMatrix();
}

void Camera::updateViewMatrix()
{
	glm::mat4 transform = glm::rotate(glm::mat4(), yaw, glm::vec3(0.0f, 1.0f, 0.0f)) * glm::rotate(glm::mat4(), pitch, glm::vec3(1.0f, 0.0f, 0.0f));
	glm::vec4 offset = glm::vec4(0.0f, 0.0f, distance, 1.0f);
	glm::vec3 cameraPos = centre + glm::vec3(transform * offset);
	viewMatrix = glm::lookAt(cameraPos, centre, glm::vec3(0.0f, 1.0f, 0.0f));
}

void Camera::updateProjectionMatrix()
{
	projectionMatrix = glm::perspective(FOV, aspectRatio, nearPlane, farPlane);
}


