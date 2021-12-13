#pragma once
#include <glm/vec3.hpp>

class ReflectorObserver
{
public:
	virtual ~ReflectorObserver() {};
	virtual void update(glm::vec3 position, glm::vec3 direction) = 0;
};