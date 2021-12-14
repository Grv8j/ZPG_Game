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
	PLAIN_TEX_GRASS,

	SKYBOX_NEGX,
	SKYBOX_NEGY,
	SKYBOX_NEGZ,
	SKYBOX_POSX,
	SKYBOX_POSY,
	SKYBOX_POSZ,

	BAKE,
	BAKE1024,
	BUILDING,
	GRASS,
	TREE2,
	ZOMBIE,
	SAND
};


class ModelFactory
{
private:
	ModelPrototypes* model_prototypes;

	ModelFactory();
	static ModelFactory* instance;

public:
	static ModelFactory* getInstance();
	Model* getModel(MODEL_TYPE type);
};