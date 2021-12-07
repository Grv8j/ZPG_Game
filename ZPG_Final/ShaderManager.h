#pragma once

#include "Shader.h"

enum class SHADER_TYPE
{
	CONSTANT,
	LAMBERT,
	PHONG
};

class ShaderManager
{
private:
	Shader* constant;
	Shader* lambert;
	Shader* phong;

	static ShaderManager* instance;
	ShaderManager();
	~ShaderManager();

public:
	Shader* getShader(SHADER_TYPE type);
	static ShaderManager* getInstance();
};