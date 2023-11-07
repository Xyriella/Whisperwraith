#pragma once
#include "Settings.h"
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include "Mesh.h"

class WhisperWraithApp
{
public:
	WhisperWraithApp(GLFWwindow* window, Settings* settings);
	~WhisperWraithApp();
	void tick();
	void render();
	
	void handleKey(GLFWwindow* window, int key, int scancode, int action, int mods);
	void handleText(GLFWwindow* window, unsigned int codepoint);
	void handleMouseButton(GLFWwindow* window, int button, int action, int mods);
	void handleScroll(GLFWwindow* window, double xoffset, double yoffset);
	void handleCursorPos(GLFWwindow* window, double xpos, double ypos);

private:
public:
private:
	Camera camera;
	GLFWwindow* window;
	Settings* settings;
	std::vector<Mesh*> objects;
	double prevTime;
	float prevMouseX, prevMouseY;
	bool isCameraRotating = false;
	float scrollSensitivity;
	float mouseSensitivity;
};

