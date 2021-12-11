#include "TextureFactory.h"

Texture* TextureFactory::getTexture(TEXTURE type)
{
	switch (type)
	{
		case TEXTURE::WOODEN_FENCE:
			return new Texture("./Textures/wooden_fence.png", 0, TEXTURE_TYPE::RGBA);

		case TEXTURE::NEGX:
			return new Texture("./Textures/negx.jpg", 0, TEXTURE_TYPE::RGB);

		case TEXTURE::NEGY:
			return new Texture("./Textures/negy.jpg", 0, TEXTURE_TYPE::RGB);

		case TEXTURE::NEGZ:
			return new Texture("./Textures/negz.jpg", 0, TEXTURE_TYPE::RGB);

		case TEXTURE::POSX:
			return new Texture("./Textures/posx.jpg", 0, TEXTURE_TYPE::RGB);

		case TEXTURE::POSY:
			return new Texture("./Textures/posy.jpg", 0, TEXTURE_TYPE::RGB);

		case TEXTURE::POSZ:
			return new Texture("./Textures/posz.jpg", 0, TEXTURE_TYPE::RGB);
	}

	return nullptr;
}
