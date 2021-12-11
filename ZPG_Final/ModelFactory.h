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
	TREE,
	PLAIN_TEX,

	SKYBOX_NEGX,
	SKYBOX_NEGY,
	SKYBOX_NEGZ,
	SKYBOX_POSX,
	SKYBOX_POSY,
	SKYBOX_POSZ,
};


class ModelFactory
{
private:
	ModelPrototypes* model_prototypes;
public:
	ModelFactory();

	Model* getModel(MODEL_TYPE type);
};