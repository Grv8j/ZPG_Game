#include "Model.h"

Model::Model(const GLfloat* points, int size, int lineLen, Texture* texture, bool onlyTex) {

	int vecLen = 3;
	int uniformCount = 0;
	GLenum mode = GL_TRIANGLES;

	pointNo = size / lineLen;
	this->mode = mode;
	this->texture = texture;
	vbo = new VBO(points, size);

	int i_top = 0;

	if (uniformCount == 0)
		i_top = lineLen / vecLen;
	else
		i_top = uniformCount;


	vao = new VAO();
	vao->Bind();

	if (!onlyTex)
	{
		for (int i = 0; i < i_top; i++)
		{
			vao->LinkAttrib(*vbo, i, vecLen, GL_FLOAT, lineLen * sizeof(GL_FLOAT), (GLvoid*)(i * vecLen * sizeof(GL_FLOAT)));
		}
	}

	else
	{
		vao->LinkAttrib(*vbo, 0, vecLen, GL_FLOAT, lineLen * sizeof(GL_FLOAT), (GLvoid*)(0 * vecLen * (sizeof(GL_FLOAT))));
	}
	
	
	if (this->texture != nullptr)
	{
		vao->LinkAttrib(*vbo, 3, 2, GL_FLOAT, lineLen * sizeof(GL_FLOAT), (GLvoid*)(6 * sizeof(GL_FLOAT)));
	}

	vao->Unbind();
	vbo->Unbind();
}

/*
Model::Model(const GLfloat* points, GLint noPoints, GLint lineLen)
{
	this->pointNo = noPoints;
	this->mode = GL_TRIANGLES;
	this->vbo = new VBO(points, this->pointNo * lineLen);
	this->vao = new VAO();
	this->vao->Bind();
}
*/

VAO* Model::getVAO() {
	return vao;
}

VBO* Model::getVBO() {
	return vbo;
}
int Model::getPointNo() {
	return pointNo;
}
GLenum Model::getMode() {
	return mode;
}

void Model::setTexture(Texture* texture)
{
	this->texture = texture;
}

Texture* Model::getTexture()
{
	return this->texture;
}
