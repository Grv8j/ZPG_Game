#pragma once

#include "Shader.h"

enum class SHADER_TYPE
{
	CONSTANT,
	LAMBERT,
	PHONG,
	PHONG_TEX,
	CLASSIC_TEX
};

class ShaderManager
{
private:
	Shader* constant;
	Shader* lambert;
	Shader* phong;
	Shader* phong_tex;
	Shader* classic_tex;

	static ShaderManager* instance;
	ShaderManager();
	~ShaderManager();

public:
	Shader* getShader(SHADER_TYPE type);
	static ShaderManager* getInstance();
};