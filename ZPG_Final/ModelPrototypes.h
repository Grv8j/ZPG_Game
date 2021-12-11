#pragma once

#include "Model.h"
#include "Models/plain.h"
#include "Models/sphere.h"
#include "Models/suzi_flat.h"
#include "Models/suzi_smooth.h"
#include "Models/Bushes.h"
#include "Models/gift.h"
#include "Models/tree.h"
#include "Models/plain_tex.h"
#include "TextureFactory.h"

enum class MODEL_TYPE_PROTOTYPE
{
	PLAIN,
	SPHERE,
	SUZI_FLAT,
	SUZI_SMOOTH,
	BUSHES,
	GIFT,
	TREE,
	PLAIN_TEX,

	PLAIN_SKYBOX_NEGX,
	PLAIN_SKYBOX_NEGY,
	PLAIN_SKYBOX_NEGZ,
	PLAIN_SKYBOX_POSX,
	PLAIN_SKYBOX_POSY,
	PLAIN_SKYBOX_POSZ,
};


class ModelPrototypes
{
private:
	Model* plain_prototype;
	Model* sphere_prototype;
	Model* suzi_flat_prototype;
	Model* suzi_smooth_prototype;
	Model* bushes_prototype;
	Model* gift_prototype;
	Model* tree_prototype;
	Model* plain_tex_prototype;

	Model* plain_skybox_negx_prototype;
	Model* plain_skybox_negy_prototype;
	Model* plain_skybox_negz_prototype;
	Model* plain_skybox_posx_prototype;
	Model* plain_skybox_posy_prototype;
	Model* plain_skybox_posz_prototype;

	TextureFactory* textureFactory;

public:
	ModelPrototypes();

	Model* getClone(MODEL_TYPE_PROTOTYPE type);
};