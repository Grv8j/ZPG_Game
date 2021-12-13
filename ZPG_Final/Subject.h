#pragma once

#include <vector>
//#include "Observer.h"

#include "SkyboxObserver.h"
#include "ShaderObserver.h"
#include "ReflectorObserver.h"

class Subject
{
public:
	virtual ~Subject() {};
	virtual void addShaderListener(ShaderObserver* observer) = 0;
	virtual void deleteShaderListener(ShaderObserver* observer) = 0;
	virtual void addSkyboxListener(SkyboxObserver* observer) = 0;
	virtual void deleteSkyboxListener(SkyboxObserver* observer) = 0;
	virtual void addReflectorListener(ReflectorObserver* observer) = 0;
	virtual void deleteReflectorListener(ReflectorObserver* observer) = 0;
	virtual void notify() = 0;
};