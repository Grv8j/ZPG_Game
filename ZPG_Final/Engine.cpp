#include "Engine.h"
#include "Shaders/Fragment_shader.h"
#include "Shaders/Vertex_shader.h"
#include "Shaders/ShaderProg.h"
#include "Shaders/ShaderLoader.h"
#include "Object.h"
#include "Utilities/MatrixHandler.h"
#include "Camera.h"
#include "Scene.h"
#include "Models/sphere.h"
#include "Models/plain.h"
#include "Models/suzi_flat.h"
#include "Models/suzi_smooth.h"




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

void Engine::startRendering() {

	const float points1[] = {
   -.4f, -.7f, .5f, 		1, 1, .4f, 
   -.4f,  .3f, .5f, 		1, 1, .4f, 
	.4f, -.7f, .5f, 		1, 1, .4f, 
	.4f,  .3f, .5f, 		1, 1, .4f, 

	.4f, -.7f, -.5f, 		0.85f, 0.85f, .3f, 
	.4f,  .3f, -.5f, 		0.85f, 0.85f, .3f, 

	-.4f, -.7f, -.5f, 		1, 1, .4f, 
	-.4f,  .3f, -.5f, 		1, 1, .4f, 

	-.4f, -.7f, .5f, 		0.85f, 0.85f, .3f, 
   -.4f,  .3f, .5f, 		0.85f, 0.85f, .3f, 
	};
	const float points2[] = {
   -.6f,  .3f, .75f, 		1, 0, 0, 
	.6f,  .3f, .75f, 		.7f, 0, 0,
	.0f , .9f, .45f, 	1, 0, 0, 
	.6f,  .3f, -.75f, 	1, 0, 0, 
	.0f , .9f, -.45f, 	.7f, 0, 0,
	-.6f,  .3f, -.75f, 	1, 0, 0, 
	.0f , .9f, .45f, 	1, 0, 0, 
	-.6f,  .3f, .75f, 	.7f, 0, 0
	};
	const float points3[] = {
	.1f, -.7f, -.51f,	.4f, .2f, .0f, 
	.1f, -.2f, -.51f,	.4f, .2f, .0f, 
	.3f, -.7f, -.51f, 	.4f, .2f, .0f, 
	.3f, -.2f, -.51f, 	.4f, .2f, .0f, 
	};

	glm::vec3 yAxis = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 xAxis = glm::vec3(1.0f, 0.0f, 0.0f);
	glm::vec3 zAxis = glm::vec3(0.0f, 0.0f, 1.0f);

	glfwSetCursorPos(this->window->getWindow(), (window->getWidth() / 2), (window->getHeight() / 2));

	//ShaderProg* sp = new ShaderProg(vertex_shader, fragment_shader);
	GLuint colShID = 0;
	GLuint constShID = 0;
	GLuint lambertShID = 0;
	GLuint phongShID = 0;


	new ShaderLoader("./Shaders/vertex_shader.glsl", "./Shaders/fragment_shader.glsl", &colShID);
	new ShaderLoader("./Shaders/vertex_shader_constant.glsl", "./Shaders/fragment_shader_constant.glsl", &constShID);
	new ShaderLoader("./Shaders/vertex_shader_lambert.glsl", "./Shaders/fragment_shader_lambert.glsl", &lambertShID);
	new ShaderLoader("./Shaders/vertex_shader_phong.glsl", "./Shaders/fragment_shader_phong.glsl", &phongShID);



	ShaderProg* colSp = new ShaderProg(colShID);
	ShaderProg* constSp = new ShaderProg(constShID);
	ShaderProg* lambSp = new ShaderProg(lambertShID);
	ShaderProg* phongSp = new ShaderProg(phongShID);



	Object* cube = new Object(new Model(points1, 10 * (3 + 3), 6, 3, 2, GL_TRIANGLE_STRIP), constSp);
	Object* roof = new Object(new Model(points2, 8  * (3 + 3), 6, 3, 2, GL_TRIANGLE_STRIP), colSp);
	Object* sphereO = new Object(new Model(sphere, 2880 * (3 + 3), 6), colSp);
	sphereO->setRotation(0.8f, glm::vec3(.0f, .0f, 1.0f));
	MatrixHandler::translate(sphereO->getMatRef(), glm::vec3(0.0f, 0.0f, 10.0f));

	Object* plainO = new Object(new Model(plain, 6 * (3 + 3), 6), colSp);
	MatrixHandler::scale(plainO->getMatRef(), glm::vec3(.3f, .3f, .3f));
	MatrixHandler::translate(plainO->getMatRef(), glm::vec3(0.0f, -1.0f, 5.0f));



	Object* suziFlatO = new Object(new Model(suziFlat, 2904 * (3 + 3), 6, 3, 2), lambSp);
	suziFlatO->setRotation(0.02f, glm::vec3(.0f, 1.0f, .0f));
	MatrixHandler::translate(suziFlatO->getMatRef(), glm::vec3(5.0f, 0.0f, 2.0f));

	Object* suziSmoothO = new Object(new Model(suziSmooth, 2904 * (3 + 3), 6, 3, 2), phongSp);
	suziSmoothO->setRotation(-0.02f, glm::vec3(.0f, 1.0f, .0f));
	MatrixHandler::translate(suziSmoothO->getMatRef(), glm::vec3(5.0f, 0.0f, 8.0f));


	Camera* camera = new Camera(window->getWidth(), window->getHeight(), glm::vec3(0.0f, 0.0f, 5.0f));
	camera->addListener(constSp);
	camera->addListener(colSp);
	camera->addListener(lambSp);
	camera->addListener(phongSp);


	this->currentScene = new Scene();
	currentScene->AddCamera(camera);
	currentScene->AddObject(cube);
	currentScene->AddObject(roof);
	currentScene->AddObject(sphereO);
	currentScene->AddObject(plainO);
	currentScene->AddObject(suziFlatO);
	currentScene->AddObject(suziSmoothO);

	Scene* scenaNemca = new Scene();
	Object* sphereO1 = new Object(new Model(sphere, 2880 * (3 + 3), 6), phongSp);
		MatrixHandler::translate(sphereO1->getMatRef(), glm::vec3(-2.0f, 0.0f, 0.0f));
	Object* sphereO2 = new Object(new Model(sphere, 2880 * (3 + 3), 6), phongSp);
		MatrixHandler::translate(sphereO2->getMatRef(), glm::vec3(2.0f, 0.0f, 0.0f));
	Object* sphereO3 = new Object(new Model(sphere, 2880 * (3 + 3), 6), phongSp);	
		MatrixHandler::translate(sphereO3->getMatRef(), glm::vec3(0.0f, 2.0f, 0.0f));
	Object* sphereO4 = new Object(new Model(sphere, 2880 * (3 + 3), 6), phongSp);
		MatrixHandler::translate(sphereO4->getMatRef(), glm::vec3(0.0f, -2.0f, 0.0f));
	scenaNemca->AddObject(sphereO1);
	scenaNemca->AddObject(sphereO2);
	scenaNemca->AddObject(sphereO3);
	scenaNemca->AddObject(sphereO4);
	scenaNemca->SetLightPos(glm::vec3(.0f, .0f, .0f));
	scenaNemca->AddCamera(camera);
	currentScene = scenaNemca;

	


	while (!this->window->shouldClose()) {
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;

		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		currentScene->Draw(deltaTime);
		//processHeldKeys();

		// update other events like input handling
		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		this->window->swapBuffers();
	}

	this->window->~Window();
	glfwTerminate();
	exit(EXIT_SUCCESS);
}

Window* Engine::getWindow() {
	return this->window;
}

void Engine::onClick(int button, int action, double x, double y) {
	if (action == GLFW_PRESS) {
		printf("press %d %d %f %f\n", button, action, x, y);
	}
	if (action == GLFW_RELEASE) {
		printf("release %d %d %f %f\n", button, action, x, y);
	}
	return;
}
void Engine::onKey(int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS) {
		printf("press %d %d %d %d\n", key, scancode, action, mods);
	}
	if (action == GLFW_RELEASE) {
		printf("release %d %d %d %d\n", key, scancode, action, mods);
	}
	if (action == GLFW_PRESS && key == GLFW_KEY_ESCAPE) {
		printf("Zaviram\n");
		glfwSetWindowShouldClose(window->getWindow(), GLFW_TRUE);
	}
	return;
}
void Engine::onMove(double x, double y) {
	printf("move %f %f \n", x, y);
	double xmove, ymove;
	xmove = x - (window->getWidth() / 2);
	ymove = y - (window->getHeight() / 2);

	glfwSetCursorPos(window->getWindow(), (window->getWidth() / 2), (window->getHeight() / 2));

	this->currentScene->getCurrentCam()->Rotate(xmove, ymove);
}

Engine::Engine() {
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
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
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
	return this->currentScene;
}

EngineController* Engine::getController()
{
	return this->controller;
}

/*
void Engine::processHeldKeys()
{
	if (glfwGetKey(window->getWindow(), GLFW_KEY_W) == GLFW_PRESS)
	{
		currentScene->getCurrentCam()->Move(CAM_FORWARD);
	}
	if (glfwGetKey(window->getWindow(), GLFW_KEY_A) == GLFW_PRESS)
	{
		currentScene->getCurrentCam()->Move(CAM_LEFT);
	}
	if (glfwGetKey(window->getWindow(), GLFW_KEY_S) == GLFW_PRESS)
	{
		currentScene->getCurrentCam()->Move(CAM_BACKWARD);
	}
	if (glfwGetKey(window->getWindow(), GLFW_KEY_D) == GLFW_PRESS)
	{
		currentScene->getCurrentCam()->Move(CAM_RIGHT);
	}
	if (glfwGetKey(window->getWindow(), GLFW_KEY_SPACE) == GLFW_PRESS)
	{
		currentScene->getCurrentCam()->Move(CAM_UP);
	}
	if (glfwGetKey(window->getWindow(), GLFW_KEY_LEFT_CONTROL) == GLFW_PRESS)
	{
		currentScene->getCurrentCam()->Move(CAM_DOWN);
	}
}
*/