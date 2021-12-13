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

		case SHADER_TYPE::PHONG_TEX:
			if (this->phong_tex == nullptr)
			{
				this->phong_tex = new Shader("./Shaders/vertex_shader_phong_texture.glsl", "./Shaders/fragment_shader_phong_texture.glsl");
			}

			return this->phong_tex;

		case SHADER_TYPE::CLASSIC_TEX:
			if (this->classic_tex == nullptr)
			{
				this->classic_tex = new Shader("./Shaders/vertex_shader_texture.glsl", "./Shaders/fragment_shader_texture.glsl");
			}

			return this->classic_tex;

		case SHADER_TYPE::LIGHTS:
			if (this->lights == nullptr)
			{
				this->lights = new Shader("./Shaders/vertex_shader_lights.glsl", "./Shaders/fragment_shader_lights.glsl");
			}

			return this->lights;
	}

	return nullptr;
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
	this->phong_tex = nullptr;
	this->classic_tex = nullptr;
	this->lights = nullptr;
}