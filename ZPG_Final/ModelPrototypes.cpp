#include "ModelPrototypes.h"

Model* ModelPrototypes::getClone(MODEL_TYPE_PROTOTYPE type)
{
	switch (type)
	{
		case MODEL_TYPE_PROTOTYPE::PLAIN:
			if (this->plain_prototype == nullptr)
			{
				this->plain_prototype = new Model(plain, 36, 6);
			}

			return new Model(*this->plain_prototype);

		case MODEL_TYPE_PROTOTYPE::SPHERE:
			if (this->sphere_prototype == nullptr)
			{
				this->sphere_prototype = new Model(sphere, 2880 * 6, 6);
			}

			return new Model(*this->sphere_prototype);

		case MODEL_TYPE_PROTOTYPE::SUZI_FLAT:
			if (this->suzi_flat_prototype == nullptr)
			{
				this->suzi_flat_prototype = new Model(suziFlat, 2904 * 6, 6, 3, 2);
			}

			return new Model(*this->suzi_flat_prototype);

		case MODEL_TYPE_PROTOTYPE::SUZI_SMOOTH:
			if (this->suzi_smooth_prototype == nullptr)
			{
				this->suzi_smooth_prototype = new Model(suziSmooth, 2904 * 6, 6, 3, 2);
			}

			return new Model(*this->suzi_smooth_prototype);
	}
}