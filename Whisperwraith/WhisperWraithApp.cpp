#include "WhisperWraithApp.h"
#include "ShaderLoader.h"

WhisperWraithApp::WhisperWraithApp(GLFWwindow* window, Settings* settings) : window(window), settings(settings), camera(16.0f/9.0f)
{
	prevMouseX = 0.0f;
	prevMouseY = 0.0f;
	prevTime = glfwGetTime();
	objects.push_back(new Mesh(ShaderLoader::GetShaderProgram("vertShader.vert", "fragShader.frag"), 
		{
			//Top
			2,6,7,
			2,7,3,
			//Bottom
			0,5,4,
			0,1,5,
			//Left
			0,6,2,
			0,4,6,
			//Right Done
			1,3,7,
			1,7,5,
			//Front Done
			0,2,3,
			0,3,1,
			//Back
			4,7,6,
			4,5,7
		},
		{
			{ { 0.0f,  0.0f,  1.0f}, {0.0f, 0.0f} },//0
			{ { 1.0f,  0.0f,  1.0f}, {1.0f, 0.0f} },//1
			{ { 0.0f,  1.0f,  1.0f}, {0.0f, 1.0f} },//2
			{ { 1.0f,  1.0f,  1.0f}, {1.0f, 1.0f} },//3
			{ { 0.0f,  0.0f,  0.0f}, {1.0f, 1.0f} },//4
			{ { 1.0f,  0.0f,  0.0f}, {0.0f, 1.0f} },//5
			{ { 0.0f,  1.0f,  0.0f}, {1.0f, 0.0f} },//6
			{ { 1.0f,  1.0f,  0.0f}, {0.0f, 0.0f} } //7
		}));
	camera.setPitchDegrees(30.0f);
	if (!settings->getFloat("scroll sensitivity", scrollSensitivity)) {
		scrollSensitivity = 0.1f;
		settings->setFloat("scroll sensitivity", 0.1f);
	}
	if (!settings->getFloat("mouse sensitivity", mouseSensitivity)) {
		mouseSensitivity = 0.1f;
		settings->setFloat("mouse sensitivity", 0.1f);
	}
}

WhisperWraithApp::~WhisperWraithApp()
{
}

void WhisperWraithApp::tick()
{
	glfwPollEvents();

	float deltaTime = static_cast<float>(glfwGetTime() - prevTime);
	prevTime = glfwGetTime();
	for (auto mesh : objects) {
		mesh->tick(deltaTime);
	}
}

void WhisperWraithApp::render()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//Render here

	for (auto mesh : objects) {
		mesh->render(camera);
	}

	glfwSwapBuffers(window);
}

void WhisperWraithApp::handleKey(GLFWwindow* window, int key, int scancode, int action, int mods)
{
}

void WhisperWraithApp::handleText(GLFWwindow* window, unsigned int codepoint)
{
}

void WhisperWraithApp::handleMouseButton(GLFWwindow* window, int button, int action, int mods)
{
	if (button == GLFW_MOUSE_BUTTON_MIDDLE) {
		isCameraRotating = action == GLFW_PRESS ? true : (action == GLFW_RELEASE ? false : isCameraRotating);
	}
}

void WhisperWraithApp::handleScroll(GLFWwindow* window, double xoffset, double yoffset)
{
	camera.scaleDistance(1.0f - yoffset * scrollSensitivity);
}

void WhisperWraithApp::handleCursorPos(GLFWwindow* window, double xpos, double ypos)
{
	float xOffset = xpos - prevMouseX;
	float yOffset = ypos - prevMouseY;

	if (isCameraRotating) {
		camera.addPitch(-yOffset * mouseSensitivity);
		camera.addYaw(-xOffset * mouseSensitivity);
	}

	prevMouseY = ypos;
	prevMouseX = xpos;
}
