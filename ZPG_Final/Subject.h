#pragma once

#include <vector>
#include "Observer.h"

class Subject
{
public:
	virtual ~Subject() {};
	virtual void addShaderListener(Observer* observer) = 0;
	virtual void deleteShaderListener(Observer* observer) = 0;
	virtual void addSkyboxListener(Observer* observer) = 0;
	virtual void deleteSkyboxListener(Observer* observer) = 0;
	virtual void notify() = 0;
};