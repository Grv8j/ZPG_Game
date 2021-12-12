#include "SceneMaker.h"

SceneMaker* SceneMaker::instance = 0;

SceneMaker::SceneMaker()
{
	this->modelFactory = ModelFactory::getInstance();
	this->shaderManager = ShaderManager::getInstance();
}

void SceneMaker::MakeScenes()
{
	//Engine instance
	auto engine = Engine::getInstance();

	Camera* camera = new Camera(engine->getWindow()->getWidth(), engine->getWindow()->getHeight(), glm::vec3(0.0f, 3.0f, 10.0f));
	//camera->addListener(constSp);
	//camera->addListener(colSp);
	camera->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::LAMBERT));
	camera->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::PHONG));
	camera->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::PHONG_TEX));
	camera->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::CLASSIC_TEX));



	// ---------- SCENE 3 ----------//
	Scene* with_skybox = new Scene();
	with_skybox->SetLightPos(glm::vec3(15.0f, 50.0f, 0.0f));
	with_skybox->setCamera(camera);

	Skybox* skybox = new Skybox();
	with_skybox->setSkybox(skybox);

	Object* treet = new Object(this->modelFactory->getModel(MODEL_TYPE::TREE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	//with_skybox->AddObject(treet);

	Object* building = new Object(this->modelFactory->getModel(MODEL_TYPE::BUILDING), this->shaderManager->getShader(SHADER_TYPE::PHONG_TEX));
	with_skybox->AddObject(building);

	Object* terrain = new Object(this->modelFactory->getModel(MODEL_TYPE::GRASS), this->shaderManager->getShader(SHADER_TYPE::PHONG_TEX));
	terrain->getTransformation()->scale(glm::vec3(3.0f, 3.0f, 3.0f));
	with_skybox->AddObject(terrain);

	Object* tree3 = new Object(this->modelFactory->getModel(MODEL_TYPE::TREE2), this->shaderManager->getShader(SHADER_TYPE::PHONG_TEX));
	tree3->getTransformation()->translate(glm::vec3(8.0f, 0.0f, 0.0f));
	with_skybox->AddObject(tree3);

	Object* zombie = new Object(this->modelFactory->getModel(MODEL_TYPE::ZOMBIE), this->shaderManager->getShader(SHADER_TYPE::PHONG_TEX));
	zombie->getTransformation()->translate(glm::vec3(-8.0f, 0.0f, 0.0f));
	with_skybox->AddObject(zombie);

	Object* brick = new Object(this->modelFactory->getModel(MODEL_TYPE::BAKE), this->shaderManager->getShader(SHADER_TYPE::PHONG_TEX));
	brick->getTransformation()->translate(glm::vec3(-10.0f, 0.0f, 5.0f));
	with_skybox->AddObject(brick);




	engine->addScene(with_skybox);









	//---------- SCENA 1 ----------//
	

	Scene* test = new Scene();
	test->setCamera(camera);
	test->SetLightPos(glm::vec3(0.0f, 5.0f, 0.0f));

	Object* tree = new Object(this->modelFactory->getModel(MODEL_TYPE::TREE), this->shaderManager->getShader(SHADER_TYPE::PHONG));

	//Object* plain = new Object(this->modelFactory->getModel(MODEL_TYPE::PLAIN), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	Object* plain = new Object(this->modelFactory->getModel(MODEL_TYPE::PLAIN_TEX), this->shaderManager->getShader(SHADER_TYPE::PHONG_TEX));
	plain->getTransformation()->scale(glm::vec3(10.0f, 10.0f, 10.0f));

	Object* gift = new Object(this->modelFactory->getModel(MODEL_TYPE::GIFT), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	gift->getTransformation()->scale(glm::vec3(2.0f, 2.0f, 2.0f));
	gift->getTransformation()->translate(glm::vec3(1.0f, 0.0f, 0.0f));
	gift->getTransformation()->setRotationAngle(0.1f);


	Object* bush1 = new Object(this->modelFactory->getModel(MODEL_TYPE::BUSHES), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	bush1->getTransformation()->translate(glm::vec3(-1.0f, 0.0f, 0.0f));
	bush1->getTransformation()->scale(glm::vec3(4.0f, 4.0f, 4.0f));

	Object* bush2 = new Object(this->modelFactory->getModel(MODEL_TYPE::BUSHES), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	bush2->getTransformation()->translate(glm::vec3(-3.0f, 0.0f, 0.0f));
	bush2->getTransformation()->scale(glm::vec3(4.0f, 4.0f, 4.0f));

	test->AddObject(tree);
	test->AddObject(plain);
	test->AddObject(gift);
	test->AddObject(bush1);
	test->AddObject(bush2);

	engine->addScene(test);





	//---------- SCENA 2 ----------//
	Scene* scenaNemca = new Scene();
	Object* sphereO1 = new Object(this->modelFactory->getModel(MODEL_TYPE::SPHERE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	sphereO1->getTransformation()->translate(glm::vec3(-2.0f, 0.0f, 0.0f));

	Object* sphereO2 = new Object(this->modelFactory->getModel(MODEL_TYPE::SPHERE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	sphereO2->getTransformation()->translate(glm::vec3(2.0f, 0.0f, 0.0f));

	Object* sphereO3 = new Object(this->modelFactory->getModel(MODEL_TYPE::SPHERE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	sphereO3->getTransformation()->translate(glm::vec3(0.0f, 2.0f, 0.0f));

	Object* sphereO4 = new Object(this->modelFactory->getModel(MODEL_TYPE::SPHERE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	sphereO4->getTransformation()->translate(glm::vec3(0.0f, -2.0f, 0.0f));

	scenaNemca->AddObject(sphereO1);
	scenaNemca->AddObject(sphereO2);
	scenaNemca->AddObject(sphereO3);
	scenaNemca->AddObject(sphereO4);
	scenaNemca->SetLightPos(glm::vec3(.0f, .0f, .0f));
	scenaNemca->setCamera(camera);

	engine->addScene(scenaNemca);



}

void SceneMaker::AddOnClickModel(MODEL_TYPE type)
{
	GLbyte color[4];
	GLfloat depth;
	GLuint index;

	auto windowGLFW = Engine::getInstance()->getWindow()->getWindow();

	double xpos, ypos;
	glfwGetCursorPos(windowGLFW, &xpos, &ypos);

	GLint lx = (GLint)xpos;
	GLint ly = (GLint)ypos;

	int newy = Engine::getInstance()->getWindow()->getHeight() - ypos;

	glReadPixels(xpos, newy, 1, 1, GL_RGBA, GL_UNSIGNED_BYTE, color);
	glReadPixels(xpos, newy, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &depth);
	glReadPixels(xpos, newy, 1, 1, GL_STENCIL_INDEX, GL_UNSIGNED_INT, &index);

	printf("Clicked on pixel %d, %d, color %02hhx%02hhx%02hhx%02hhx, depth %f, stencil index %u\n",
		lx, ly, color[0], color[1], color[2], color[3], depth, index);
	glm::vec3 screenX = glm::vec3(xpos, newy, depth);

	auto camera = Engine::getInstance()->getScene()->getCamera();
	auto window = Engine::getInstance()->getWindow();

	glm::mat4 view = camera->getViewMatrix();
	glm::mat4 projection = camera->getProjectionMatrix();
	glm::vec4 viewPort = glm::vec4(0, 0, window->getWidth(), window->getHeight());
	glm::vec3 pos = glm::unProject(screenX, view, projection, viewPort);

	printf("unProject [%f,%f,%f]\n", pos.x, pos.y, pos.z);

	auto sm = ShaderManager::getInstance();
	auto mf = ModelFactory::getInstance();

	Object* toAdd = new Object(mf->getModel(type), sm->getShader(SHADER_TYPE::PHONG_TEX));
	toAdd->getTransformation()->translate(glm::vec3(pos.x, pos.y, pos.z));
	Engine::getInstance()->getScene()->AddObject(toAdd);
}


SceneMaker* SceneMaker::getInstance()
{
	if (SceneMaker::instance == 0)
	{
		return SceneMaker::instance = new SceneMaker();
	}

	return SceneMaker::instance;
}