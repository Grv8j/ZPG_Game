#include <stdexcept>
#include "Window.h"
#include "Engine.h"

Window::Window(const int window_width, const int window_height, const char* title){
	this->window_width = window_width;
	this->window_height = window_height;
	this->framebuffer_width = this->window_width;
	this->framebuffer_height = this->window_height;

	this->window = glfwCreateWindow(window_width, window_height, title, NULL, NULL);

	glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

	if (!this->window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	this->setViewport();

	glfwMakeContextCurrent(this->window);
	glfwSwapInterval(1);

	glfwSetWindowUserPointer(window, this);
	
	glfwSetKeyCallback(this->window, [](GLFWwindow* window, int key, int scancode, int action, int mods) -> void
		{
			Engine::getInstance()->getController()->key_callback(window, key, scancode, action, mods);
		});

	glfwSetWindowFocusCallback(this->window, [](GLFWwindow* window, int focused) -> void
		{
			Engine::getInstance()->getController()->window_focus_callback(window, focused);
		});

	glfwSetWindowIconifyCallback(this->window, [](GLFWwindow* window, int iconified) -> void
		{
			Engine::getInstance()->getController()->window_iconify_callback(window, iconified);
		});

	//pri zmene velikosti okna nastavi viewport na velikost aktualniho okna
	glfwSetWindowSizeCallback(this->window, [](GLFWwindow* window, int width, int height) -> void
		{
			Engine::getInstance()->getController()->window_size_callback(window, width, height);
		});

	glfwSetCursorPosCallback(this->window, [](GLFWwindow* window, double x, double y) -> void
		{
			Engine::getInstance()->getController()->cursor_callback(window, x, y);
		});

	glfwSetMouseButtonCallback(this->window, [](GLFWwindow* window, int button, int action, int mode) -> void
		{
			Engine::getInstance()->getController()->button_callback(window, button, action, mode);
		});
}

bool Window::shouldClose()
{
	return ((glfwWindowShouldClose(this->window)) == 1 ? true : false);
}

void Window::swapBuffers()
{
	glfwSwapBuffers(this->window);
}

void Window::setViewport()
{
	glViewport(0, 0, this->window_height, this->window_width);
}

GLFWwindow* Window::getWindow()
{
	return this->window;
}

int Window::getWidth()
{
	return this->window_width;;
}

int Window::getHeight()
{
	return this->window_height;
}

Window::~Window()
{
	glfwDestroyWindow(this->window);
}
