#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include "Shader.h"
#include "Model.h"
#include "Transformation.h"

class Object
{
private:
	Shader* shader;
	Model* model;
	Transformation* transformation;

public:
	Object(Model* model, Shader* shader);
	void draw();

	Shader* getShader();
	Transformation* getTransformation();
};

