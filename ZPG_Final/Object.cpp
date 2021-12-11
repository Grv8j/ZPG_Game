#include "Object.h"

Object::Object(Model* model, Shader* shader)
{
	this->model = model;
	this->shader = shader;
	this->transformation = new Transformation();
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

Shader* Object::getShader()
{
	return this->shader;
}

Transformation* Object::getTransformation()
{
	return this->transformation;
}