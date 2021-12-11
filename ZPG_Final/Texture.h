#pragma once
#include "SOIL.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include "Shader.h"

enum class TEXTURE_TYPE
{
	RGB,
	RGBA
};

class Texture
{
private:
	GLuint textureID;
	int index;

public:
	Texture(const char* path, int index, TEXTURE_TYPE type = TEXTURE_TYPE::RGB);

	void useTexture(Shader* s);
};