#include "Light.h"

Light::Light(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 spectacular)
{
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->spectacular = spectacular;
}

glm::vec3 Light::getAmbient()
{
	return this->ambient;
}

glm::vec3 Light::getDiffuse()
{
	return this->diffuse;
}

glm::vec3 Light::getSpectacular()
{
	return this->spectacular;
}
