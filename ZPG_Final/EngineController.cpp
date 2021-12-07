#include "EngineController.h"
#include "Engine.h"


void EngineController::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

	if (action == GLFW_REPEAT || action == GLFW_PRESS)
	{
		switch (key)
		{
			case GLFW_KEY_W:
				Engine::getInstance()->getScene()->getCurrentCam()->processKeyboardMovement(CAM_MOVE::FORWARD);
				printf("move forwards");
				break;

			case GLFW_KEY_S:
				Engine::getInstance()->getScene()->getCurrentCam()->processKeyboardMovement(CAM_MOVE::BACKWARD);
				printf("move backwards");
				break;

			case GLFW_KEY_A:
				Engine::getInstance()->getScene()->getCurrentCam()->processKeyboardMovement(CAM_MOVE::LEFT);
				printf("move left");
				break;

			case GLFW_KEY_D:
				Engine::getInstance()->getScene()->getCurrentCam()->processKeyboardMovement(CAM_MOVE::RIGHT);
				printf("move right");
				break;


			case GLFW_KEY_SPACE:
				Engine::getInstance()->getScene()->getCurrentCam()->processKeyboardMovement(CAM_MOVE::UP);
				printf("move up");
				break;

			case GLFW_KEY_LEFT_CONTROL:
				Engine::getInstance()->getScene()->getCurrentCam()->processKeyboardMovement(CAM_MOVE::DOWN);
				printf("move down");
				break;
		}
	}

	if (action == GLFW_PRESS)
	{
		if (key == GLFW_KEY_ESCAPE)
		{
			printf("Closing window\n");
			glfwSetWindowShouldClose(window, GL_TRUE);	//zavreni okna
		}
	}

	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void EngineController::window_focus_callback(GLFWwindow* window, int focused)
{
	printf("window_focus_callback \n");
}

void EngineController::window_size_callback(GLFWwindow* window, int width, int height)
{
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

void EngineController::window_iconify_callback(GLFWwindow* window, int iconified)
{
	printf("window_iconify_callback \n");
}

void EngineController::cursor_callback(GLFWwindow* window, double x, double y)
{
	printf("cursor_callback \n");
	printf("move %f %f \n", x, y);
	double xmove, ymove;
	xmove = x - (Engine::getInstance()->getWindow()->getWidth() / 2);
	ymove = y - (Engine::getInstance()->getWindow()->getHeight() / 2);

	glfwSetCursorPos(Engine::getInstance()->getWindow()->getWindow(), (Engine::getInstance()->getWindow()->getWidth() / 2), (Engine::getInstance()->getWindow()->getHeight() / 2));

	Engine::getInstance()->getScene()->getCurrentCam()->processMouseMovement(xmove, ymove);
}

void EngineController::button_callback(GLFWwindow* window, int button, int action, int mode)
{
	if (action == GLFW_PRESS) printf("button_callback [%d,%d,%d]\n", button, action, mode);
}