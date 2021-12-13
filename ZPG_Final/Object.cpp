#include "Object.h"

Object::Object()
{

}

Object::Object(Model* model, Shader* shader, GLint ID)
{
	this->model = model;
	this->shader = shader;
	this->transformation = new Transformation();
	this->ID = ID;
}

void Object::draw()
{
	this->shader->useShader();
	this->shader->applyTransform(this->transformation->getTransMatrix());

	if (this->model->getTexture() != nullptr)
	{
		this->model->getTexture()->useTexture(this->shader);
	}

	this->model->getVAO()->Bind();
	glDrawArrays(this->model->getMode(), 0, this->model->getPointNo());


	this->transformation->rotate();
}

GLint Object::getID()
{
	return this->ID;
}

Shader* Object::getShader()
{
	return this->shader;
}

Transformation* Object::getTransformation()
{
	return this->transformation;
}