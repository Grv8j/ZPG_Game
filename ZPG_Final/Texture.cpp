#include "Texture.h"


Texture::Texture(const char* path, int index, TEXTURE_TYPE type)
{
	this->index = index;

	GLuint tex;

	glGenTextures(1, &tex);
	glBindTexture(GL_TEXTURE_2D, tex);

	if (type == TEXTURE_TYPE::RGBA)
	{
		tex = SOIL_load_OGL_texture(path, SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	}

	else
	{
		tex = SOIL_load_OGL_texture(path, SOIL_LOAD_RGB, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
	}

	if (tex == NULL)
	{
		fprintf(stderr, "ERROR: An error occurred while loading image\n");
	}

	glGenerateMipmap(GL_TEXTURE_2D);



	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	//glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


	this->textureID = tex;
}

void Texture::useTexture(Shader* s)
{
	glUniform1i(s->getUniformLocation("textureUnitID"), 0);
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, this->textureID);
}
