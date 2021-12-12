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

	static SceneMaker* instance;
	SceneMaker();
public:
	static SceneMaker* getInstance();
	void MakeScenes();

	void AddOnClickModel(MODEL_TYPE type);
};