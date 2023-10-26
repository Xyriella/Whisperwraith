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
	
private:
public:
private:
	GLFWwindow* window;
	Settings* settings;
	std::vector<Mesh*> objects;
	double prevTime;
};

