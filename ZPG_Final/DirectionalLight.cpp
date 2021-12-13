#include "DirectionalLight.h"

DirectionalLight::DirectionalLight(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 spectacular, glm::vec3 direction) : Light(ambient, diffuse, spectacular)
{
	this->direction = direction;
}

glm::vec3 DirectionalLight::getDirection()
{
	return this->direction;
}
