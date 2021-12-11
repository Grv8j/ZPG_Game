#include "SceneMaker.h"

SceneMaker::SceneMaker()
{
	this->modelFactory = new ModelFactory();
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
	with_skybox->setCamera(camera);

	Skybox* skybox = new Skybox();
	with_skybox->setSkybox(skybox);

	Object* treet = new Object(this->modelFactory->getModel(MODEL_TYPE::TREE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	with_skybox->AddObject(treet);

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
