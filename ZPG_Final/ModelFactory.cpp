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
	}

}