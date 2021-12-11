#pragma once

#include "Observer.h"

class SkyboxObserver : public Observer
{
public:
	virtual ~SkyboxObserver() {};
	virtual void update(glm::vec3 position) = 0;
};