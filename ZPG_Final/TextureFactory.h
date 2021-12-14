#pragma once

#include "Texture.h"


enum class TEXTURE
{
	WOODEN_FENCE,
	NEGX,
	NEGY,
	NEGZ,
	POSX,
	POSY,
	POSZ,
	BAKE1024,
	BAKE,
	BUILDING,
	GRASS,
	TREE,
	ZOMBIE,
	SAND
};

class TextureFactory
{
public:
	Texture* getTexture(TEXTURE type);
};