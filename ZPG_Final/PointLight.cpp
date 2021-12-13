#include "PointLight.h"

PointLight::PointLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 spectacular, glm::vec3 position) : Light(ambient, diffuse, spectacular)
{
	this->position = position;

	this->constant = 1.0f;
	this->linear = 0.09f;
	this->quadratic = 0.032f;
}

glm::vec3 PointLight::getPosition()
{
	return this->position;
}

float PointLight::getConstant()
{
	return this->constant;
}

float PointLight::getLinear()
{
	return this->linear;
}

float PointLight::getQuadratic()
{
	return this->quadratic;
}
