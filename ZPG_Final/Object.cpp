#include "Object.h"

Object::Object()
{

}

Object::Object(Model* model, Shader* shader, Path* path)
{
	this->model = model;
	this->shader = shader;
	this->transformation = new Transformation();
	this->path = path;
	this->ID = 0;
}

void Object::draw()
{
	if (this->path != nullptr)
	{
		this->transformation->reset();
		this->transformation->translate(this->path->moveToNext(0.0015f));
	}

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

void Object::setID(GLint ID)
{
	this->ID = ID;
}

Shader* Object::getShader()
{
	return this->shader;
}

Transformation* Object::getTransformation()
{
	return this->transformation;
}

Path* Object::getPath()
{
	return this->path;
}
