#pragma once
#include <GL/glew.h>
#include<GLFW/glfw3.h>
#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>
#include<glm/gtx/rotate_vector.hpp>
#include<glm/gtx/vector_angle.hpp>
#include <vector>

#include "Subject.h"

#include "Shaders/ShaderProg.h"

const glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);

enum class CAM_MOVE {
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

class Camera : public Subject
{
private:
	std::vector<ShaderObserver*> shaderObservers;

public:

	// Stores the main vectors of the camera
	glm::vec3 Position;
	glm::vec3 Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::vec3 Right = glm::vec3(0.0f, 1.0f, 0.0f);
	glm::mat4 viewMat;
	glm::mat4 projMat;
	GLfloat MovementSpeed;
	GLfloat Sensitivity = 0.05f;
	GLfloat pitch;
	GLfloat yaw;

	// Camera constructor to set up initial values
	Camera(int width, int height, glm::vec3 position);

	void UpdateShader(GLuint shaderProg);
	void CalcOrientation();
	void CalcView();
	void Move(CAM_MOVE direction);
	void Rotate(double xoffset, double yoffset, GLboolean constrainPitch = true);
	

	//Observer functions
	virtual void addListener(Observer* observer);
	virtual void deleteListener(Observer* observer);
	virtual void notify();
};