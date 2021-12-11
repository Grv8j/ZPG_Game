#include "ModelFactory.h"

ModelFactory::ModelFactory()
{
	this->model_prototypes = new ModelPrototypes();
}

Model* ModelFactory::getModel(MODEL_TYPE type)
{
	switch (type)
	{
		case MODEL_TYPE::PLAIN:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::PLAIN);

		case MODEL_TYPE::SPHERE:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::SPHERE);

		case MODEL_TYPE::SUZI_FLAT:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::SUZI_FLAT);

		case MODEL_TYPE::SUZI_SMOOTH:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::SUZI_SMOOTH);

		case MODEL_TYPE::BUSHES:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::BUSHES);

		case MODEL_TYPE::GIFT:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::GIFT);

		case MODEL_TYPE::TREE:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::TREE);

		case MODEL_TYPE::PLAIN_TEX:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::PLAIN_TEX);

		case MODEL_TYPE::SKYBOX_NEGX:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::PLAIN_SKYBOX_NEGX);

		case MODEL_TYPE::SKYBOX_NEGY:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::PLAIN_SKYBOX_NEGY);

		case MODEL_TYPE::SKYBOX_NEGZ:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::PLAIN_SKYBOX_NEGZ);

		case MODEL_TYPE::SKYBOX_POSX:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::PLAIN_SKYBOX_POSX);

		case MODEL_TYPE::SKYBOX_POSY:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::PLAIN_SKYBOX_POSY);

		case MODEL_TYPE::SKYBOX_POSZ:
			return this->model_prototypes->getClone(MODEL_TYPE_PROTOTYPE::PLAIN_SKYBOX_POSZ);
	}

	return nullptr;
}