#include "Transformation.h"

Transformation::Transformation()
{
	this->transMatrix = glm::mat4(1.0f);
	this->rotationAngle = 0.0f;
	this->rotationAxis = glm::vec3(0.0f, 1.0f, 0.0f);
}

void Transformation::setRotation(glm::vec3 rotationAxis, GLfloat rotationAngle)
{
	this->rotationAxis = rotationAxis;
	this->rotationAngle = rotationAngle;
}

void Transformation::setRotationAxis(glm::vec3 rotationAxis)
{
	this->rotationAxis = rotationAxis;
}

void Transformation::setRotationAngle(GLfloat rotationAngle)
{
	this->rotationAngle = rotationAngle;
}

glm::mat4 Transformation::getTransMatrix()
{
	return this->transMatrix;
}

void Transformation::rotate()
{
	this->transMatrix = glm::rotate(this->transMatrix, this->rotationAngle, this->rotationAxis);
}

void Transformation::translate(glm::vec3 transVector)
{
	this->transMatrix = glm::translate(this->transMatrix, transVector);
}

void Transformation::scale(glm::vec3 scaleVector)
{
	this->transMatrix = glm::scale(this->transMatrix, scaleVector);
}

void Transformation::reset()
{
	this->transMatrix = glm::mat4(1.0f);
}

GLfloat Transformation::getRotationAngle()
{
	return this->rotationAngle;
}
