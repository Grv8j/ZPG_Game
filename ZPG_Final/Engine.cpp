#include "Engine.h"


Engine* Engine::instance = 0;
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;

void Engine::init() {

	glfwSetErrorCallback([](int err, const char* description) -> void 
		{
			fputs(description, stderr);
		});

	//GLFW INIT
	this->glfw_init();
	//WINDOW INIT
	this->init_window();
	//GLEW INIT
	this->glew_init();
	//OPENGL OPTIONS
	this->set_opengl_options();

	//info print
	this->print_info();
}

void Engine::startRendering()
{
	glfwSetCursorPos(this->window->getWindow(), (this->window->getWidth() / 2), (this->window->getHeight() / 2));

	SceneMaker::getInstance()->MakeScenes();

	this->actaulScene->getCamera()->notify();

	while (!this->window->shouldClose()) {
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
		this->actaulScene->Draw(deltaTime);

		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		this->window->swapBuffers();
	}

	this->window->~Window();
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

Window* Engine::getWindow()
{
	return this->window;
}


Engine::Engine()
{
	this->controller = new EngineController();
}

void Engine::init_window()
{
	this->window = new Window(1200, 700, "Game");
}

void Engine::glfw_init()
{
	if (!glfwInit())
	{
		fprintf(stderr, "ERROR: Could not start GLFW\n");
		exit(EXIT_FAILURE);
	}
}

void Engine::glew_init()
{
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "ERROR: glew init failed\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	//umoznuje nam pouzivat moderni opengl
	glewExperimental = GL_TRUE;
}

void Engine::set_opengl_options()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
	//glOrtho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);

	glClearColor(0.2, 0.2, 0.2, 0.2);
}

void Engine::print_info()
{
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);
}

Engine* Engine::getInstance()
{
	if (instance == 0)
	{
		return instance = new Engine();
	}

	return instance;
}

Scene* Engine::getScene()
{
	return this->actaulScene;
}

EngineController* Engine::getController()
{
	return this->controller;
}

void Engine::addScene(Scene* scene)
{
	this->scenes.push_back(scene);

	if (this->scenes.size() == 1)
	{
		this->actaulScene = this->scenes[0];
		this->currentScenePosition = 0;
	}
}

void Engine::nextScene()
{
	this->currentScenePosition++;

	if (this->currentScenePosition == this->scenes.size())
	{
		this->currentScenePosition = 0;
	}

	this->actaulScene = this->scenes[this->currentScenePosition];
}

void Engine::previousScene()
{
	this->currentScenePosition--;

	if (this->currentScenePosition == -1)
	{
		this->currentScenePosition = this->scenes.size() - 1;
	}

	this->actaulScene = this->scenes[this->currentScenePosition];
}
