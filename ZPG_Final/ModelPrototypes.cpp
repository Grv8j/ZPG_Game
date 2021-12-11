#include "ModelPrototypes.h"

ModelPrototypes::ModelPrototypes()
{
	this->textureFactory = new TextureFactory();
}

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
				this->suzi_flat_prototype = new Model(suziFlat, 2904 * 6, 6);
			}

			return new Model(*this->suzi_flat_prototype);

		case MODEL_TYPE_PROTOTYPE::SUZI_SMOOTH:
			if (this->suzi_smooth_prototype == nullptr)
			{
				this->suzi_smooth_prototype = new Model(suziSmooth, 2904 * 6, 6);
			}

			return new Model(*this->suzi_smooth_prototype);

		case MODEL_TYPE_PROTOTYPE::BUSHES:
			if (this->bushes_prototype == nullptr)
			{
				this->bushes_prototype = new Model(bushes, 8730 * 6, 6);
			}

			return new Model(*this->bushes_prototype);

		case MODEL_TYPE_PROTOTYPE::GIFT:
			if (this->gift_prototype == nullptr)
			{
				this->gift_prototype = new Model(gift, 66624 * 6, 6);
			}

			return new Model(*this->gift_prototype);

		case MODEL_TYPE_PROTOTYPE::TREE:
			if (this->tree_prototype == nullptr)
			{
				this->tree_prototype = new Model(tree, 92814 * 6, 6);
			}

			return new Model(*this->tree_prototype);

		case MODEL_TYPE_PROTOTYPE::PLAIN_TEX:
			if (this->plain_tex_prototype == nullptr)
			{
				this->plain_tex_prototype = new Model(plain_tex, 48, 8, this->textureFactory->getTexture(TEXTURE::WOODEN_FENCE));
			}

			return new Model(*this->plain_tex_prototype);

		case MODEL_TYPE_PROTOTYPE::PLAIN_SKYBOX_NEGX:
			if (this->plain_skybox_negx_prototype == nullptr)
			{
				this->plain_skybox_negx_prototype = new Model(plain_tex, 48, 8, this->textureFactory->getTexture(TEXTURE::NEGX), true);
			}

			return new Model(*this->plain_skybox_negx_prototype);

		case MODEL_TYPE_PROTOTYPE::PLAIN_SKYBOX_NEGY:
			if (this->plain_skybox_negy_prototype == nullptr)
			{
				this->plain_skybox_negy_prototype = new Model(plain_tex, 48, 8, this->textureFactory->getTexture(TEXTURE::NEGY), true);
			}

			return new Model(*this->plain_skybox_negy_prototype);

		case MODEL_TYPE_PROTOTYPE::PLAIN_SKYBOX_NEGZ:
			if (this->plain_skybox_negz_prototype == nullptr)
			{
				this->plain_skybox_negz_prototype = new Model(plain_tex, 48, 8, this->textureFactory->getTexture(TEXTURE::NEGZ), true);
			}

			return new Model(*this->plain_skybox_negz_prototype);

		case MODEL_TYPE_PROTOTYPE::PLAIN_SKYBOX_POSX:
			if (this->plain_skybox_posx_prototype == nullptr)
			{
				this->plain_skybox_posx_prototype = new Model(plain_tex, 48, 8, this->textureFactory->getTexture(TEXTURE::POSX), true);
			}

			return new Model(*this->plain_skybox_posx_prototype);

		case MODEL_TYPE_PROTOTYPE::PLAIN_SKYBOX_POSY:
			if (this->plain_skybox_posy_prototype == nullptr)
			{
				this->plain_skybox_posy_prototype = new Model(plain_tex, 48, 8, this->textureFactory->getTexture(TEXTURE::POSY), true);
			}

			return new Model(*this->plain_skybox_posy_prototype);

		case MODEL_TYPE_PROTOTYPE::PLAIN_SKYBOX_POSZ:
			if (this->plain_skybox_posz_prototype == nullptr)
			{
				this->plain_skybox_posz_prototype = new Model(plain_tex, 48, 8, this->textureFactory->getTexture(TEXTURE::POSZ), true);
			}

			return new Model(*this->plain_skybox_posz_prototype);
	}

	return nullptr;
}