#include "ShaderManager.h"

ShaderManager* ShaderManager::instance = 0;

Shader* ShaderManager::getShader(SHADER_TYPE type)
{
	switch (type)
	{
		case SHADER_TYPE::CONSTANT:
			if (this->constant == nullptr)
			{
				this->constant = new Shader("./Shaders/vertex_shader_constant.glsl", "./Shaders/fragment_shader_constant.glsl");
			}

			return this->constant;

		case SHADER_TYPE::LAMBERT:
			if (this->lambert == nullptr)
			{
				this->lambert = new Shader("./Shaders/vertex_shader_lambert.glsl", "./Shaders/fragment_shader_lambert.glsl");
			}

			return this->lambert;

		case SHADER_TYPE::PHONG:
			if (this->phong == nullptr)
			{
				this->phong = new Shader("./Shaders/vertex_shader_phong.glsl", "./Shaders/fragment_shader_phong.glsl");
			}

			return this->phong;
	}
}

ShaderManager* ShaderManager::getInstance()
{
	if (ShaderManager::instance == 0)
	{
		return instance = new ShaderManager();
	}

	return instance;
}

ShaderManager::ShaderManager()
{
	this->constant = nullptr;
	this->lambert = nullptr;
	this->phong = nullptr;
}