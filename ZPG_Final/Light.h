#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Light
{
protected:
	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 spectacular;

public:
	Light(glm::vec3 ambient, glm::vec3 diffuse, glm::vec3 spectacular);

	glm::vec3 getAmbient();
	glm::vec3 getDiffuse();
	glm::vec3 getSpectacular();
};
