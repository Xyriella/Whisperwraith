#include "WhisperWraithApp.h"
#include "ShaderLoader.h"

WhisperWraithApp::WhisperWraithApp(GLFWwindow* window, Settings* settings) : window(window), settings(settings)
{
	prevTime = glfwGetTime();
	objects.push_back(new Mesh(ShaderLoader::GetShaderProgram("vertShader.vert", "fragShader.frag")));
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
		mesh->render();
	}

	glfwSwapBuffers(window);
}
