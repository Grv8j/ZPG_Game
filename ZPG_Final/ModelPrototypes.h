#pragma once

#include "Model.h"
#include "Models/plain.h"
#include "Models/sphere.h"
#include "Models/suzi_flat.h"
#include "Models/suzi_smooth.h"

enum class MODEL_TYPE_PROTOTYPE
{
	PLAIN,
	SPHERE,
	SUZI_FLAT,
	SUZI_SMOOTH
};


class ModelPrototypes
{
private:
	Model* plain_prototype;
	Model* sphere_prototype;
	Model* suzi_flat_prototype;
	Model* suzi_smooth_prototype;

public:
	Model* getClone(MODEL_TYPE_PROTOTYPE type);
};