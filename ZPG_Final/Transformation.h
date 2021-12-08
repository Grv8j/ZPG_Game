#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>


class Transformation
{
private:
	glm::mat4 transMatrix;

	GLfloat rotationAngle;
	glm::vec3 rotationAxis;

public:
	Transformation();

	void setRotation(glm::vec3 rotationAxis, GLfloat rotationAngle);
	void setRotationAxis(glm::vec3 rotationAxis);
	void setRotationAngle(GLfloat rotationAngle);

	glm::mat4 getTransMatrix();

	void rotate();
	void translate(glm::vec3 transVector);
	void scale(glm::vec3 scaleVector);
};