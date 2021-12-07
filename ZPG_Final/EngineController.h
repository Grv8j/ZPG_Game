#pragma once

#include "Window.h"

class EngineController
{
public:
	void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	void window_focus_callback(GLFWwindow* window, int focused);
	void window_size_callback(GLFWwindow* window, int width, int height);
	void window_iconify_callback(GLFWwindow* window, int iconified);
	void cursor_callback(GLFWwindow* window, double x, double y);
	void button_callback(GLFWwindow* window, int button, int action, int mode);
};