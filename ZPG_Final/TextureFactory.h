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
	POSZ
};

class TextureFactory
{
public:
	Texture* getTexture(TEXTURE type);
};