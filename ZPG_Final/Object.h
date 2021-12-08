#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include "Shader.h"
#include "Model.h"
#include "Utilities/MatrixHandler.h"
class Object
{
private:
	Shader* shaderProgram;
	glm::mat4 transMat;
	Model* model;
	GLint idModelTransform;
	GLfloat rotationAngle;
	glm::vec3 rotationAxis;
public:
	Object(Model* model, Shader* shaderProgram);
	void draw();
	Shader* getShader();
	glm::mat4* getMatRef();
	void setRotation(GLfloat rotationAngle, glm::vec3 rotationAxis);
	void setRotationAngle(GLfloat rotationAngle);
};

