#pragma once

#include "PointLight.h"


class ReflectorLight : public PointLight
{
private:
	float cutOff;
	float outerCutOff;

	glm::vec3 direction;
	glm::vec3 position;
public:
	ReflectorLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 spectacular, glm::vec3 position, glm::vec3 direction, float cutOff, float outerCutOff);
};