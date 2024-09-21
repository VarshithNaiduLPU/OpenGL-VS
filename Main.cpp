#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Vertex Shader source code
const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\0";
//Fragment Shader source code
const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"void main()\n"
"{\n"
"   FragColor = vec4(0.8f, 0.3f, 0.02f, 1.0f);\n"
"}\n\0";

int main()
{
	// Initializing glfw
	glfwInit();

	// Telling which opengl version and profile we are using
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); 
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLfloat vertices[] =
	{
		-0.5f,  0.5f,  0.0f,
		 0.5f, -0.5f,  0.0f,
		 0.0f,  0.5f,  0.0f
	};

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
	

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);

	GLuint shaderProgram = glCreateProgram();
	
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);

	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);


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