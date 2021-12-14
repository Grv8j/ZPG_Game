#include "TextureFactory.h"

Texture* TextureFactory::getTexture(TEXTURE type)
{
	switch (type)
	{
		case TEXTURE::WOODEN_FENCE:
			return new Texture("./Textures/wooden_fence.png", 0, TEXTURE_TYPE::RGBA);

		case TEXTURE::NEGX:
			return new Texture("./Textures/negx2.png", 0, TEXTURE_TYPE::RGBA);

		case TEXTURE::NEGY:
			return new Texture("./Textures/negy2.png", 0, TEXTURE_TYPE::RGBA);

		case TEXTURE::NEGZ:
			return new Texture("./Textures/negz2.png", 0, TEXTURE_TYPE::RGBA);

		case TEXTURE::POSX:
			return new Texture("./Textures/posx2.png", 0, TEXTURE_TYPE::RGBA);

		case TEXTURE::POSY:
			return new Texture("./Textures/posy2.png", 0, TEXTURE_TYPE::RGBA);

		case TEXTURE::POSZ:
			return new Texture("./Textures/posz2.png", 0, TEXTURE_TYPE::RGBA);

		case TEXTURE::BAKE1024:
			return new Texture("./Textures/bake1024.jpg", 0, TEXTURE_TYPE::RGB);

		case TEXTURE::BAKE:
			return new Texture("./Textures/bake.png", 0, TEXTURE_TYPE::RGB);

		case TEXTURE::BUILDING:
			return new Texture("./Textures/building.png", 0, TEXTURE_TYPE::RGBA);

		case TEXTURE::GRASS:
			return new Texture("./Textures/grass.png", 0, TEXTURE_TYPE::RGBA);

		case TEXTURE::TREE:
			return new Texture("./Textures/tree.png", 0, TEXTURE_TYPE::RGBA);

		case TEXTURE::ZOMBIE:
			return new Texture("./Textures/zombie.png", 0, TEXTURE_TYPE::RGBA);

		case TEXTURE::SAND:
			return new Texture("./Textures/sand.jpg", 0, TEXTURE_TYPE::RGB);
	}

	return nullptr;
}
