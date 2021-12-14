#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include "Shader.h"
#include "Model.h"
#include "Transformation.h"
#include "Path.h"

class Object
{
private:
	Shader* shader;
	Model* model;
	Path* path;
	Transformation* transformation;
	GLint ID;

public:
	Object();
	Object(Model* model, Shader* shader, Path* path = nullptr);
	void draw();
	GLint getID();
	void setID(GLint ID);

	Shader* getShader();
	Transformation* getTransformation();
	Path* getPath();
};

