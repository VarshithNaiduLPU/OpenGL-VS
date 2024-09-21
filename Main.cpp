#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

int main()
{
	// Initializing glfw
	glfwInit();

	// Telling which opengl version and profile we are using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Creating a window
	GLFWwindow* window = glfwCreateWindow(800, 600, "OpenGL", NULL, NULL);
	// Error Handling for window creation
	if (window == NULL)
	{
		std::cout << "Failed to create a window" << std::endl;
		// Terminating glfw if window is not created
		glfwTerminate();
		return -1;
	}
	// Making the created window as the current contex
	glfwMakeContextCurrent(window);

	// Loading glad
	gladLoadGL();

	// Telling the viewport of the OpenGL
	glViewport(0, 0, 800, 600);


	// Specifying the color of the background
	glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
	// Clearing the back buffer and assining the new color to it
	glClear(GL_COLOR_BUFFER_BIT);
	// Sapping the back buffer with the front buffer
	glfwSwapBuffers(window);

	// Running the main loop while no close condition is called
	while (!glfwWindowShouldClose(window))
	{
		// Takes care of all the glfw events
		glfwPollEvents();
	}

	// Delete the window at the end of the program
	glfwDestroyWindow(window);
	// Terminating the glfw at the end of the program
	glfwTerminate();
	return 0;
}