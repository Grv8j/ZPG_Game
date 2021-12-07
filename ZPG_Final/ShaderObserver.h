#pragma once
#include "Observer.h"

class ShaderObserver : public Observer
{
public:
	virtual ~ShaderObserver() {};
	virtual void update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, glm::vec3 cameraPosition) = 0;
};