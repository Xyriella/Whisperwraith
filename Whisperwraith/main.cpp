#define GLFW_INCLUDE_NONE
#include "GLFW/glfw3.h"
#include "glad/gl.h"
#include <iostream>

void error_callback(int error, const char* description) {
	std::cerr << "Error: " << description << std::endl;
}

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods) {

}

void text_input_callback(GLFWwindow* window, unsigned int codepoint) {

}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {

}

void scroll_callback(GLFWwindow* window, double xoffset, double yoffset) {

}

void cursor_pos_callback(GLFWwindow* window, double xpos, double ypos) {

}

int main() {
	//Init
	if (!glfwInit()) exit(EXIT_FAILURE);

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 6);


	glfwSetErrorCallback(error_callback);

	GLFWwindow* window = glfwCreateWindow(80 * 16, 80 * 9, "Whisperwraith", NULL, NULL);
	if (!window) {
		std::cerr << "Window creation failed" << std::endl;
	}
	glfwMakeContextCurrent(window);
	gladLoadGL(glfwGetProcAddress);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glfwSetKeyCallback(window, key_callback);
	glfwSetScrollCallback(window, scroll_callback);
	glfwSetCharCallback(window, text_input_callback);
	glfwSetCursorPosCallback(window, cursor_pos_callback);
	glfwSetMouseButtonCallback(window, mouse_button_callback);

	//Main loop
	while (!glfwWindowShouldClose(window)) {

	}

	//Cleanup
	glfwTerminate();
	exit(EXIT_SUCCESS);
}