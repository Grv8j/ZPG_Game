#pragma once

#include <stdexcept>
#include <glm/vec4.hpp>
#include <memory>
#include <vector>
#include "Scene.h"
#include "Window.h"
#include "EngineController.h"
#include "SceneMaker.h"


class Engine
{
private:
	static Engine* instance;
	Engine();
	~Engine();

	Window* window;
	Scene* actaulScene;
	std::vector<Scene*> scenes;
	EngineController* controller;
	int currentScenePosition;

	void init_window();
	void glfw_init();
	void glew_init();
	void set_opengl_options();
	void print_info();

public:
	void init();
	void startRendering();

	Window* getWindow();
	static Engine* getInstance();
	Scene* getScene();
	EngineController* getController();

	void addScene(Scene* scene);
	void nextScene();
	void previousScene();
};


