#pragma once

#include <stdexcept>
#include <glm/vec4.hpp>
#include <memory>
#include "Scene.h"
#include "Window.h"
#include "EngineController.h"

class Engine{
private:
	static Engine* instance;
	Engine();
	~Engine();

	Window* window;
	Scene* currentScene;
	EngineController* controller;

	void init_window();
	void glfw_init();
	void glew_init();
	void set_opengl_options();
	void print_info();
public:
	void init();
	void startRendering();

	virtual void onKey(int key, int scancode, int action, int mods);
	virtual void onMove(double x, double y);
	virtual void onClick(int button, int action, double x, double y);
	//void processHeldKeys();

	Window* getWindow();
	static Engine* getInstance();
	Scene* getScene();
	EngineController* getController();
};


