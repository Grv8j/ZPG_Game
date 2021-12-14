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




	// ---------- SCENE 1 ----------//
	Camera* camera = new Camera(engine->getWindow()->getWidth(), engine->getWindow()->getHeight(), glm::vec3(0.0f, 3.0f, 25.0f));
	//camera->addListener(constSp);
	//camera->addListener(colSp);
	camera->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::LAMBERT));
	camera->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::PHONG));
	camera->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::PHONG_TEX));
	camera->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::CLASSIC_TEX));
	camera->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::LIGHTS));


	ReflectorLight* ref = new ReflectorLight(glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(1.0f, 1.0f, 1.0f), glm::vec3(0.0f, 5.0f, 0.0f), glm::vec3(0.0f, 0.0f, 1.0f), glm::cos(glm::radians(12.5f)), glm::cos(glm::radians(15.0f)));

	Scene* with_skybox = new Scene();
	with_skybox->SetLightPos(glm::vec3(15.0f, 50.0f, 0.0f));
	with_skybox->setCamera(camera);
	//with_skybox->setDirectionalLight(new DirectionalLight(glm::vec3(0.4f, 0.4f, 0.4f), glm::vec3(0.4f, 0.4f, 0.4f), glm::vec3(0.4f, 0.4f, 0.4f), glm::vec3(0.2f, -1.0f, 0.4f)));
	with_skybox->setDirectionalLight(new DirectionalLight(glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(0.2f, -1.0f, 0.4f)));
	with_skybox->addPointLight(new PointLight(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.3f, 0.3f, 0.3f), glm::vec3(0.f, 2.f, 11.5f)));

	Skybox* skybox = new Skybox();
	with_skybox->setSkybox(skybox);
	with_skybox->setReflector(ref);



	Object* building = new Object(this->modelFactory->getModel(MODEL_TYPE::BUILDING), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
	with_skybox->AddObject(building);

	Object* building2 = new Object(this->modelFactory->getModel(MODEL_TYPE::BUILDING), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
	building2->getTransformation()->translate(glm::vec3(18.0f, 0.0f, 6.0f));
	building2->getTransformation()->setRotationAngle(-0.7f);
	building2->getTransformation()->rotate();
	building2->getTransformation()->setRotationAngle(0.0f);
	with_skybox->AddObject(building2);

	Object* building3 = new Object(this->modelFactory->getModel(MODEL_TYPE::BUILDING), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
	building3->getTransformation()->translate(glm::vec3(-18.0f, 0.0f, 6.0f));
	building3->getTransformation()->setRotationAngle(0.7f);
	building3->getTransformation()->rotate();
	building3->getTransformation()->setRotationAngle(0.0f);
	with_skybox->AddObject(building3);

	Object* terrain = new Object(this->modelFactory->getModel(MODEL_TYPE::SAND), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
	terrain->setID(1);
	terrain->getTransformation()->scale(glm::vec3(3.0f, 3.0f, 3.0f));
	with_skybox->AddObject(terrain);

	Object* tree3 = new Object(this->modelFactory->getModel(MODEL_TYPE::TREE2), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
	tree3->getTransformation()->translate(glm::vec3(8.0f, 0.0f, 0.0f));
	with_skybox->AddObject(tree3);

	Object* tree4 = new Object(this->modelFactory->getModel(MODEL_TYPE::TREE2), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
	tree4->getTransformation()->translate(glm::vec3(-8.0f, 0.0f, 0.0f));
	with_skybox->AddObject(tree4);

	Object* grassPlain = new Object(this->modelFactory->getModel(MODEL_TYPE::PLAIN_TEX_GRASS), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
	grassPlain->getTransformation()->scale(glm::vec3(36.0f, 36.0f, 36.0f));
	grassPlain->getTransformation()->translate(glm::vec3(0.0f, 0.001f, 0.0f));
	with_skybox->AddObject(grassPlain);


	for (int i = 0; i < 5; i++)
	{
		Object* brickBR = new Object(this->modelFactory->getModel(MODEL_TYPE::BAKE), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
		brickBR->getTransformation()->translate(glm::vec3(i * 8.0f, 0.0f, -20.0f));
		with_skybox->AddObject(brickBR);

		Object* brickBL = new Object(this->modelFactory->getModel(MODEL_TYPE::BAKE), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
		brickBL->getTransformation()->translate(glm::vec3(i * (-8.0f), 0.0f, -20.0f));
		with_skybox->AddObject(brickBL);
	}

	for (int i = 0; i < 5; i++)
	{
		Object* brickFR = new Object(this->modelFactory->getModel(MODEL_TYPE::BAKE), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
		brickFR->getTransformation()->translate(glm::vec3(i * 8.0f, 0.0f, 28.0f));
		with_skybox->AddObject(brickFR);

		Object* brickFL = new Object(this->modelFactory->getModel(MODEL_TYPE::BAKE), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
		brickFL->getTransformation()->translate(glm::vec3(i * (-8.0f), 0.0f, 28.0f));
		with_skybox->AddObject(brickFL);
	}

	for (int i = 0; i < 4; i++)
	{
		Object* brickLR = new Object(this->modelFactory->getModel(MODEL_TYPE::BAKE), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
		brickLR->getTransformation()->translate(glm::vec3(-35.0f, 0.0f, i * 8.0f));
		brickLR->getTransformation()->setRotationAngle(1.58f);
		brickLR->getTransformation()->rotate();
		brickLR->getTransformation()->setRotationAngle(0.0f);
		with_skybox->AddObject(brickLR);

		Object* brickLL = new Object(this->modelFactory->getModel(MODEL_TYPE::BAKE), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
		brickLL->getTransformation()->translate(glm::vec3(-35.0f, 0.0f, (i - 1) * (-8.0f)));
		brickLL->getTransformation()->setRotationAngle(1.58f);
		brickLL->getTransformation()->rotate();
		brickLL->getTransformation()->setRotationAngle(0.0f);
		with_skybox->AddObject(brickLL);

		Object* brickRR = new Object(this->modelFactory->getModel(MODEL_TYPE::BAKE), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
		brickRR->getTransformation()->translate(glm::vec3(35.0f, 0.0f, i * 8.0f));
		brickRR->getTransformation()->setRotationAngle(1.58f);
		brickRR->getTransformation()->rotate();
		brickRR->getTransformation()->setRotationAngle(0.0f);
		with_skybox->AddObject(brickRR);

		Object* brickLRL = new Object(this->modelFactory->getModel(MODEL_TYPE::BAKE), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
		brickLRL->getTransformation()->translate(glm::vec3(35.0f, 0.0f, (i - 1) * (-8.0f)));
		brickLRL->getTransformation()->setRotationAngle(1.58f);
		brickLRL->getTransformation()->rotate();
		brickLRL->getTransformation()->setRotationAngle(0.0f);
		with_skybox->AddObject(brickLRL);
	}


	Path* zombiePath = new Path();
	zombiePath->addWaypoints(glm::vec3(-20.f, 0.f, -17.f));
	zombiePath->addWaypoints(glm::vec3(20.f, 0.f, -16.f));
	zombiePath->addWaypoints(glm::vec3(20.f, 0.f, 10.f));
	zombiePath->addWaypoints(glm::vec3(-10.f, 0.f, 20.f));

	Object* zombie = new Object(this->modelFactory->getModel(MODEL_TYPE::ZOMBIE), this->shaderManager->getShader(SHADER_TYPE::LIGHTS), zombiePath);
	//zombie->getTransformation()->translate(glm::vec3(-20.0f, 0.0f, 0.0f));


	Object* zombieTest1 = new Object(this->modelFactory->getModel(MODEL_TYPE::ZOMBIE), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
	zombieTest1->getTransformation()->translate(glm::vec3(-20.f, 0.f, -10.f));
	with_skybox->AddObject(zombieTest1);

	Object* zombieTest2= new Object(this->modelFactory->getModel(MODEL_TYPE::ZOMBIE), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
	zombieTest2->getTransformation()->translate(glm::vec3(-10.f, 0.f, 20.f));
	with_skybox->AddObject(zombieTest2);

	with_skybox->AddObject(zombie);



	engine->addScene(with_skybox);









	//---------- SCENA 2 ----------//
	Camera* camera2 = new Camera(engine->getWindow()->getWidth(), engine->getWindow()->getHeight(), glm::vec3(0.0f, 3.0f, 10.0f));
	camera2->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::PHONG));
	camera2->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::PHONG_TEX));
	camera2->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::CLASSIC_TEX));
	camera2->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::LIGHTS));



	Scene* test = new Scene();
	test->setCamera(camera2);
	test->SetLightPos(glm::vec3(0.0f, 8.0f, 0.0f));
	test->addPointLight(new PointLight(glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.3f, 0.3f, 0.3f), glm::vec3(2.0f, 0.1f, 2.0f)));

	Object* tree = new Object(this->modelFactory->getModel(MODEL_TYPE::TREE), this->shaderManager->getShader(SHADER_TYPE::PHONG));


	Object* plain = new Object(this->modelFactory->getModel(MODEL_TYPE::PLAIN_TEX), this->shaderManager->getShader(SHADER_TYPE::LIGHTS));
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






	//---------- SCENA 3 ----------//
	Camera* camera3 = new Camera(engine->getWindow()->getWidth(), engine->getWindow()->getHeight(), glm::vec3(0.0f, 3.0f, 10.0f));
	camera3->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::LAMBERT));
	camera3->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::PHONG));
	camera3->addShaderListener(this->shaderManager->getShader(SHADER_TYPE::PHONG_TEX));


	Scene* balls = new Scene();
	balls->setCamera(camera3);
	balls->SetLightPos(glm::vec3(.0f, .0f, .0f));

	Object* ball1 = new Object(this->modelFactory->getModel(MODEL_TYPE::SPHERE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	ball1->getTransformation()->translate(glm::vec3(-2.0f, 0.0f, 0.0f));

	Object* ball2 = new Object(this->modelFactory->getModel(MODEL_TYPE::SPHERE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	ball2->getTransformation()->translate(glm::vec3(2.0f, 0.0f, 0.0f));

	Object* ball3 = new Object(this->modelFactory->getModel(MODEL_TYPE::SPHERE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	ball3->getTransformation()->translate(glm::vec3(0.0f, 2.0f, 0.0f));

	Object* ball4 = new Object(this->modelFactory->getModel(MODEL_TYPE::SPHERE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	ball4->getTransformation()->translate(glm::vec3(0.0f, -2.0f, 0.0f));

	balls->AddObject(ball1);
	balls->AddObject(ball2);
	balls->AddObject(ball3);
	balls->AddObject(ball4);



	engine->addScene(balls);
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

	if (index != 0)
	{
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
}


SceneMaker* SceneMaker::getInstance()
{
	if (SceneMaker::instance == 0)
	{
		return SceneMaker::instance = new SceneMaker();
	}

	return SceneMaker::instance;
}