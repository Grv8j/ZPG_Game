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

		case MODEL_TYPE_PROTOTYPE::BUSHES:
			if (this->bushes_prototype == nullptr)
			{
				this->bushes_prototype = new Model(bushes, 8730 * 6, 6, 3, 2);
			}

			return new Model(*this->bushes_prototype);

		case MODEL_TYPE_PROTOTYPE::GIFT:
			if (this->gift_prototype == nullptr)
			{
				this->gift_prototype = new Model(gift, 66624 * 6, 6, 3, 2);
			}

			return new Model(*this->gift_prototype);

		case MODEL_TYPE_PROTOTYPE::TREE:
			if (this->tree_prototype == nullptr)
			{
				this->tree_prototype = new Model(tree, 92814 * 6, 6, 3, 2);
			}

			return new Model(*this->tree_prototype);
	}
}