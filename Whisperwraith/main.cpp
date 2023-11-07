#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/gl.h"
#include <iostream>
#include "WhisperWraithApp.h"
#include "Settings.h"

Settings* settings;
int width, height, xpos, ypos;
WhisperWraithApp* app;

void error_callback(int error, const char* description) {
	std::cerr << "Error: " << description << std::endl;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	app->handleKey(window, key, scancode, action, mods);
}

void text_input_callback(GLFWwindow* window, unsigned int codepoint) {
	app->handleText(window, codepoint);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
	app->handleMouseButton(window, button, action, mods);
}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {
	app->handleScroll(window, xoffset, yoffset);
}

void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {
	app->handleCursorPos(window, xpos, ypos);
}

void window_pos_callback(GLFWwindow* window, int newxpos, int newypos) {
	xpos = newxpos;
	ypos = newypos;
	settings->setInt("xpos", newxpos);
	settings->setInt("ypos", newypos);
}

int main() {

	settings = new Settings();
	std::string title;
	settings->getString("window title", title);
	settings->getInt("width", width);
	settings->getInt("height", height);
	settings->getInt("xpos", xpos);
	settings->getInt("ypos", ypos);
	//Init
	if (!glfwInit()) exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

	glfwSetErrorCallback(error_callback);
	GLFWwindow* window = glfwCreateWindow(width, height, title.data(), NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}
	glfwSetWindowPos(window, xpos, ypos);
	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);
	glfwSwapInterval(1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glfwSetWindowPosCallback(window, window_pos_callback);
	glfwSetKeyCallback(window, key_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetCharCallback(window, text_input_callback);
	glfwSetCursorPosCallback(window, cursor_pos_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	glFrontFace(GL_CW);
	glCullFace(GL_BACK);
	glEnable(GL_CULL_FACE);

	app = new WhisperWraithApp(window, settings);
	//Main loop
	while (!glfwWindowShouldClose(window)) {
		glfwGetFramebufferSize(window, &width, &height);
		settings->setInt("width", width);
		settings->setInt("height", height);
		glViewport(0, 0, width, height);
		app->tick();
		app->render();
	}
	//Cleanup
	settings->saveSettings();
	delete app;
	glfwTerminate();
	exit(EXIT_SUCCESS);
}