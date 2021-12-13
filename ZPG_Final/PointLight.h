#pragma once
#include "light.h"

class PointLight : public Light
{
protected:
	float constant;
	float linear;
	float quadratic;

	glm::vec3 position;

public:
	PointLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 spectacular, glm::vec3 position);

	glm::vec3 getPosition();
	float getConstant();
	float getLinear();
	float getQuadratic();
};