#pragma once

#include <vector>
#include "Observer.h"

class Subject
{
public:
	virtual ~Subject() {};
	virtual void addListener(Observer* observer) = 0;
	virtual void deleteListener(Observer* observer) = 0;
	virtual void notify() = 0;
};