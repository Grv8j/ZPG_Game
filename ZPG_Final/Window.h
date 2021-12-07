#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Window {
private:
	int window_width;
	int window_height;
	int framebuffer_width;
	int framebuffer_height;

	GLFWwindow* window;

public:
	Window(const int window_width, const int window_height, const char* title);
	~Window();

	bool shouldClose();
	void swapBuffers();
	void setViewport();

	GLFWwindow* getWindow();

	int getWidth();
	int getHeight();
};

