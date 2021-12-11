#pragma once

#include "Object.h"
#include "glm/glm.hpp"
#include <vector>
#include "ShaderManager.h"
#include "ModelFactory.h"
#include "SkyboxObserver.h"

class Skybox : public SkyboxObserver
{
private:
	std::vector<Object*> sides;
	glm::vec3 position;

	void resetPositions();
public:
	Skybox();

	virtual void update(glm::vec3 position);
	void draw();
};