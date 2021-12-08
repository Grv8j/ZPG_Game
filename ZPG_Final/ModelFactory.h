#pragma once

#include "Model.h"
#include "ModelPrototypes.h"

enum class MODEL_TYPE
{
	PLAIN,
	SPHERE,
	SUZI_FLAT,
	SUZI_SMOOTH,
	BUSHES,
	GIFT,
	TREE
};


class ModelFactory
{
private:
	ModelPrototypes* model_prototypes;
public:
	ModelFactory();

	Model* getModel(MODEL_TYPE type);
};