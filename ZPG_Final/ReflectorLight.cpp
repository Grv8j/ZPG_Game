#include "ReflectorLight.h"

ReflectorLight::ReflectorLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 spectacular, glm::vec3 position, glm::vec3 direction, float cutOff, float outerCutOff) : PointLight(ambient, diffuse, spectacular, position)
{
	this->cutOff = cutOff;
	this->outerCutOff = outerCutOff;
	this->position = position;
	this->direction = direction;
}