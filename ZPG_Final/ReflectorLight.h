#pragma once

#include "PointLight.h"
#include "ReflectorObserver.h"


class ReflectorLight : public PointLight, public ReflectorObserver
{
private:
	float cutOff;
	float outerCutOff;

	glm::vec3 direction;
public:
	ReflectorLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 spectacular, glm::vec3 position, glm::vec3 direction, float cutOff, float outerCutOff);

	glm::vec3 getDirection();
	float getCutOff();
	float getOuterCutOff();

	void update(glm::vec3 position, glm::vec3 direction);
};