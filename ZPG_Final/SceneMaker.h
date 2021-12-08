#pragma once

#include "ShaderManager.h"
#include "ModelFactory.h"
#include "Camera.h"
#include "Engine.h"

class SceneMaker
{
private:
	ModelFactory* modelFactory;
	ShaderManager* shaderManager;

public:
	SceneMaker();
	void MakeScenes();
};