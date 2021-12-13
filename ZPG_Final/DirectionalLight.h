#pragma once

#include "Light.h"

class DirectionalLight : public Light
{
protected:
	glm::vec3 direction;

public:
	DirectionalLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 spectacular, glm::vec3 direction);

	glm::vec3 getDirection();
};