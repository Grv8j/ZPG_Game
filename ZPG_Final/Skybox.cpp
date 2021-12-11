#include "Skybox.h"

void Skybox::resetPositions()
{
	for (Object* o : this->sides)
	{
		o->getTransformation()->reset();
	}
}

Skybox::Skybox()
{
	auto shader = ShaderManager::getInstance()->getShader(SHADER_TYPE::CLASSIC_TEX);
	auto mf = new ModelFactory();

	this->sides.push_back(new Object(mf->getModel(MODEL_TYPE::SKYBOX_NEGY), shader));
	this->sides.push_back(new Object(mf->getModel(MODEL_TYPE::SKYBOX_POSY), shader));
	this->sides.push_back(new Object(mf->getModel(MODEL_TYPE::SKYBOX_NEGX), shader));
	this->sides.push_back(new Object(mf->getModel(MODEL_TYPE::SKYBOX_POSX), shader));
	this->sides.push_back(new Object(mf->getModel(MODEL_TYPE::SKYBOX_NEGZ), shader));
	this->sides.push_back(new Object(mf->getModel(MODEL_TYPE::SKYBOX_POSZ), shader));

	auto s0 = this->sides[0]->getTransformation();
	s0->translate(glm::vec3(0.0f, -1.0f, 0.0f));
	s0->setRotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(-90.0f));
	s0->rotate();

	auto s1 = this->sides[1]->getTransformation();
	s1->translate(glm::vec3(0.0f, 1.0f, 0.0f));
	s1->setRotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(-90.0f));
	s1->rotate();

	auto s2 = this->sides[2]->getTransformation();
	s2->translate(glm::vec3(-1.0f, 0.0f, 0.0f));
	s2->setRotation(glm::vec3(1.0f, 0.0f, 0.0f), glm::radians(180.0f));
	s2->rotate();
	s2->setRotation(glm::vec3(0.0f, 0.0f, -1.0f), glm::radians(-90.0f));
	s2->rotate();

	auto s3 = this->sides[3]->getTransformation();
	s3->translate(glm::vec3(1.0f, 0.0f, 0.0f));
	s3->setRotation(glm::vec3(0.0f, 0.0f, -1.0f), glm::radians(90.0f));
	s3->rotate();

	auto s4 = this->sides[4]->getTransformation();
	s4->translate(glm::vec3(0.0f, 0.0f, -1.0f));
	s4->setRotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(90.f));
	s4->rotate();
	s4->setRotation(glm::vec3(0.0f, 0.0f, 1.0f), glm::radians(-90.f));
	s4->rotate();

	auto s5 = this->sides[5]->getTransformation();
	s5->translate(glm::vec3(0.0f, 0.0f, 1.0f));
	s5->setRotation(glm::vec3(1.0f, 0.0f, 0.0f), glm::radians(90.f));
	s5->rotate();
	s5->setRotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(-90.f));
	s5->rotate();
}

void Skybox::update(glm::vec3 position)
{
	this->position = position;
	
	this->resetPositions();
	
	auto s0 = this->sides[0]->getTransformation();
	s0->translate(this->position);
	s0->translate(glm::vec3(0.0f, -1.0f, 0.0f));
	s0->setRotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(-90.0f));
	s0->rotate();

	auto s1 = this->sides[1]->getTransformation();
	s1->translate(this->position);
	s1->translate(glm::vec3(0.0f, 1.0f, 0.0f));
	s1->setRotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(-90.0f));
	s1->rotate();

	auto s2 = this->sides[2]->getTransformation();
	s2->translate(this->position);
	s2->translate(glm::vec3(-1.0f, 0.0f, 0.0f));
	s2->setRotation(glm::vec3(1.0f, 0.0f, 0.0f), glm::radians(180.0f));
	s2->rotate();
	s2->setRotation(glm::vec3(0.0f, 0.0f, -1.0f), glm::radians(-90.0f));
	s2->rotate();

	auto s3 = this->sides[3]->getTransformation();
	s3->translate(this->position);
	s3->translate(glm::vec3(1.0f, 0.0f, 0.0f));
	s3->setRotation(glm::vec3(0.0f, 0.0f, -1.0f), glm::radians(90.0f));
	s3->rotate();

	auto s4 = this->sides[4]->getTransformation();
	s4->translate(this->position);
	s4->translate(glm::vec3(0.0f, 0.0f, -1.0f));
	s4->setRotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(90.f));
	s4->rotate();
	s4->setRotation(glm::vec3(0.0f, 0.0f, 1.0f), glm::radians(-90.f));
	s4->rotate();

	auto s5 = this->sides[5]->getTransformation();
	s5->translate(this->position);
	s5->translate(glm::vec3(0.0f, 0.0f, 1.0f));
	s5->setRotation(glm::vec3(1.0f, 0.0f, 0.0f), glm::radians(90.f));
	s5->rotate();
	s5->setRotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(-90.f));
	s5->rotate();
	
}

void Skybox::draw()
{
	for (Object* o : this->sides)
	{
		o->getShader()->useShader();
		o->draw();
	}

	glClear(GL_DEPTH_BUFFER_BIT);
}
