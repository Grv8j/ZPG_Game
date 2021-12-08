#include "SceneMaker.h"

SceneMaker::SceneMaker()
{
	this->modelFactory = new ModelFactory();
	this->shaderManager = ShaderManager::getInstance();
}

void SceneMaker::MakeScenes()
{
	auto engine = Engine::getInstance();

	Camera* camera = new Camera(engine->getWindow()->getWidth(), engine->getWindow()->getHeight(), glm::vec3(0.0f, 3.0f, 10.0f));
	//camera->addListener(constSp);
	//camera->addListener(colSp);
	camera->addListener(this->shaderManager->getShader(SHADER_TYPE::LAMBERT));
	camera->addListener(this->shaderManager->getShader(SHADER_TYPE::PHONG));

	Scene* test = new Scene();
	test->AddCamera(camera);
	test->SetLightPos(glm::vec3(3.0f, 2.0f, -3.0f));

	Object* tree = new Object(this->modelFactory->getModel(MODEL_TYPE::TREE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	tree->setRotationAngle(0.0f);

	Object* plain = new Object(this->modelFactory->getModel(MODEL_TYPE::PLAIN), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	plain->setRotationAngle(0.0f);
	MatrixHandler::scale(plain->getMatRef(), glm::vec3(10.0f, 10.0f, 10.0f));

	Object* gift = new Object(this->modelFactory->getModel(MODEL_TYPE::GIFT), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	MatrixHandler::scale(gift->getMatRef(), glm::vec3(2.0f, 2.0f, 2.0f));
	MatrixHandler::translate(gift->getMatRef(), glm::vec3(1.0f, 0.0f, 0.0f));

	Object* bush1 = new Object(this->modelFactory->getModel(MODEL_TYPE::BUSHES), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	bush1->setRotationAngle(0.0f);
	MatrixHandler::translate(bush1->getMatRef(), glm::vec3(-1.0f, 0.0f, 0.0f));
	MatrixHandler::scale(bush1->getMatRef(), glm::vec3(4.0f, 4.0f, 4.0f));
	Object* bush2 = new Object(this->modelFactory->getModel(MODEL_TYPE::BUSHES), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	bush2->setRotationAngle(0.0f);
	MatrixHandler::translate(bush2->getMatRef(), glm::vec3(-3.0f, 0.0f, 0.0f));
	MatrixHandler::scale(bush2->getMatRef(), glm::vec3(4.0f, 4.0f, 4.0f));

	test->AddObject(tree);
	test->AddObject(plain);
	test->AddObject(gift);
	test->AddObject(bush1);
	test->AddObject(bush2);

	engine->addScene(test);


	Scene* scenaNemca = new Scene();
	Object* sphereO1 = new Object(this->modelFactory->getModel(MODEL_TYPE::SPHERE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	MatrixHandler::translate(sphereO1->getMatRef(), glm::vec3(-2.0f, 0.0f, 0.0f));
	Object* sphereO2 = new Object(this->modelFactory->getModel(MODEL_TYPE::SPHERE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	MatrixHandler::translate(sphereO2->getMatRef(), glm::vec3(2.0f, 0.0f, 0.0f));
	Object* sphereO3 = new Object(this->modelFactory->getModel(MODEL_TYPE::SPHERE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	MatrixHandler::translate(sphereO3->getMatRef(), glm::vec3(0.0f, 2.0f, 0.0f));
	Object* sphereO4 = new Object(this->modelFactory->getModel(MODEL_TYPE::SPHERE), this->shaderManager->getShader(SHADER_TYPE::PHONG));
	MatrixHandler::translate(sphereO4->getMatRef(), glm::vec3(0.0f, -2.0f, 0.0f));
	scenaNemca->AddObject(sphereO1);
	scenaNemca->AddObject(sphereO2);
	scenaNemca->AddObject(sphereO3);
	scenaNemca->AddObject(sphereO4);
	scenaNemca->SetLightPos(glm::vec3(.0f, .0f, .0f));
	scenaNemca->AddCamera(camera);

	engine->addScene(scenaNemca);
}
