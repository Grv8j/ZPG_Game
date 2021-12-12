#include "Model.h"

Model::Model(const GLfloat* points, int size, int lineLen, Texture* texture, bool onlyTex) {

	int vecLen = 3;
	int uniformCount = 0;
	GLenum mode = GL_TRIANGLES;

	this->pointNo = size / lineLen;
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

Model::Model(const char* path, Texture* texture)
{
	this->texture = texture;
	this->mode = GL_TRIANGLES;

	int count = 0;
	Assimp::Importer importer;
	unsigned int importOptions = aiProcess_Triangulate
		| aiProcess_OptimizeMeshes              // slouèení malých plošek
		| aiProcess_JoinIdenticalVertices       // NUTNÉ jinak hodnì duplikuje
		| aiProcess_Triangulate                 // prevod vsech ploch na trojuhelniky
		| aiProcess_CalcTangentSpace;           // vypocet tangenty, nutny pro spravne pouziti normalove mapy

	const aiScene* scene = importer.ReadFile(path, importOptions);
	vector<float> data;

	if (scene)
	{
		aiMesh* mesh = scene->mMeshes[0];
		count = mesh->mNumFaces * 3;
		for (unsigned int i = 0; i < mesh->mNumFaces; i++) {
			for (unsigned int j = 0; j < 3; j++)
			{
				data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].x);
				data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].y);
				data.push_back(mesh->mVertices[mesh->mFaces[i].mIndices[j]].z);
				data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].x);
				data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].y);
				data.push_back(mesh->mNormals[mesh->mFaces[i].mIndices[j]].z);
				data.push_back(mesh->mTextureCoords[0][mesh->mFaces[i].mIndices[j]].x);
				data.push_back(mesh->mTextureCoords[0][mesh->mFaces[i].mIndices[j]].y);
			}
		}
	}

	vbo = new VBO(data);
	vao = new VAO();
	vao->Bind();

	this->pointNo = data.size() / 8;
	int lineLen = 8;

	for (int i = 0; i < 2; i++)
	{
		vao->LinkAttrib(*vbo, i, 3, GL_FLOAT, lineLen * sizeof(GL_FLOAT), (GLvoid*)(i * 3 * sizeof(GL_FLOAT)));
	}

	if (this->texture != nullptr)
	{
		vao->LinkAttrib(*vbo, 3, 2, GL_FLOAT, lineLen * sizeof(GL_FLOAT), (GLvoid*)(6 * sizeof(GL_FLOAT)));
	}

	vao->Unbind();
	vbo->Unbind();
}


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
