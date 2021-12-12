#include "Skybox.h"

void Skybox::resetPositions()
{
	for (Object* o : this->sides)
	{
		o->getTransformation()->reset();
	}
}

void Skybox::nullRotations()
{
	for (Object* o : this->sides)
	{
		o->getTransformation()->setRotationAngle(0.0f);
	}
}

void Skybox::setNEGY(Transformation* t)
{
	t->translate(glm::vec3(0.0f, -1.0f, 0.0f));
	t->setRotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(-90.0f));
	t->rotate();
}

void Skybox::setPOSY(Transformation* t)
{
	t->translate(glm::vec3(0.0f, 1.0f, 0.0f));
	t->setRotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(-90.0f));
	t->rotate();
}

void Skybox::setNEGX(Transformation* t)
{
	t->translate(glm::vec3(-1.0f, 0.0f, 0.0f));
	t->setRotation(glm::vec3(1.0f, 0.0f, 0.0f), glm::radians(180.0f));
	t->rotate();
	t->setRotation(glm::vec3(0.0f, 0.0f, -1.0f), glm::radians(-90.0f));
	t->rotate();
}

void Skybox::setPOSX(Transformation* t)
{
	t->translate(glm::vec3(1.0f, 0.0f, 0.0f));
	t->setRotation(glm::vec3(0.0f, 0.0f, -1.0f), glm::radians(90.0f));
	t->rotate();
}

void Skybox::setNEGZ(Transformation* t)
{
	t->translate(glm::vec3(0.0f, 0.0f, -1.0f));
	t->setRotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(90.f));
	t->rotate();
	t->setRotation(glm::vec3(0.0f, 0.0f, 1.0f), glm::radians(-90.f));
	t->rotate();
}

void Skybox::setPOSZ(Transformation* t)
{
	t->translate(glm::vec3(0.0f, 0.0f, 1.0f));
	t->setRotation(glm::vec3(1.0f, 0.0f, 0.0f), glm::radians(90.f));
	t->rotate();
	t->setRotation(glm::vec3(0.0f, 1.0f, 0.0f), glm::radians(-90.f));
	t->rotate();
}

Skybox::Skybox()
{
	auto shader = ShaderManager::getInstance()->getShader(SHADER_TYPE::CLASSIC_TEX);
	auto mf = ModelFactory::getInstance();
	
	this->sides.push_back(new Object(mf->getModel(MODEL_TYPE::SKYBOX_NEGY), shader));
	this->sides.push_back(new Object(mf->getModel(MODEL_TYPE::SKYBOX_POSY), shader));
	this->sides.push_back(new Object(mf->getModel(MODEL_TYPE::SKYBOX_NEGX), shader));
	this->sides.push_back(new Object(mf->getModel(MODEL_TYPE::SKYBOX_POSX), shader));
	this->sides.push_back(new Object(mf->getModel(MODEL_TYPE::SKYBOX_NEGZ), shader));
	this->sides.push_back(new Object(mf->getModel(MODEL_TYPE::SKYBOX_POSZ), shader));

	auto s0 = this->sides[0]->getTransformation();
	this->setNEGY(s0);

	auto s1 = this->sides[1]->getTransformation();
	this->setPOSY(s1);

	auto s2 = this->sides[2]->getTransformation();
	this->setNEGX(s2);

	auto s3 = this->sides[3]->getTransformation();
	this->setPOSX(s3);

	auto s4 = this->sides[4]->getTransformation();
	this->setNEGZ(s4);

	auto s5 = this->sides[5]->getTransformation();
	this->setPOSZ(s5);
	
	this->nullRotations();
}

void Skybox::update(glm::vec3 position)
{
	this->position = position;	
	this->resetPositions();
	
	auto s0 = this->sides[0]->getTransformation();
	s0->translate(this->position);
	this->setNEGY(s0);

	auto s1 = this->sides[1]->getTransformation();
	s1->translate(this->position);
	this->setPOSY(s1);

	auto s2 = this->sides[2]->getTransformation();
	s2->translate(this->position);
	this->setNEGX(s2);

	auto s3 = this->sides[3]->getTransformation();
	s3->translate(this->position);
	this->setPOSX(s3);

	auto s4 = this->sides[4]->getTransformation();
	s4->translate(this->position);
	this->setNEGZ(s4);

	auto s5 = this->sides[5]->getTransformation();
	s5->translate(this->position);
	this->setPOSZ(s5);

	this->nullRotations();
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
