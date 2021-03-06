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
#include "Shader.h"
#include "SkyboxObserver.h"

const glm::vec3 WorldUp = glm::vec3(0.0f, 1.0f, 0.0f);

enum class CAM_MOVE
{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	UP,
	DOWN
};

const float def_yaw = -90.0f;
const float def_pitch = 0.0f;
const float def_sensitivity = 0.05f;
const float def_movement_speed = 0.5f;

class Camera : public Subject
{
private:
	std::vector<ShaderObserver*> shaderObservers;
	std::vector<SkyboxObserver*> skyboxObservers;
	ReflectorObserver* reflectorOberserver;

	glm::vec3 Position;
	glm::vec3 Orientation;
	glm::vec3 Up;
	glm::vec3 Right;

	GLfloat MovementSpeed;
	GLfloat Sensitivity;
	GLfloat pitch;
	GLfloat yaw;

	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;

	void updateCameraVectors();
	void setViewMatrix();

	
public:
	// Camera constructor to set up initial values
	Camera(int width, int height, glm::vec3 position);

	void processKeyboardMovement(CAM_MOVE direction);
	void processMouseMovement(double xoffset, double yoffset, GLboolean constrainPitch = true);

	//Observer functions
	virtual void addShaderListener(ShaderObserver* observer);
	virtual void deleteShaderListener(ShaderObserver* observer);

	virtual void addSkyboxListener(SkyboxObserver* observer);
	virtual void deleteSkyboxListener(SkyboxObserver* observer);

	virtual void addReflectorListener(ReflectorObserver* observer);
	virtual void deleteReflectorListener(ReflectorObserver* observer);

	virtual void notify();


	glm::mat4 getViewMatrix();
	glm::mat4 getProjectionMatrix();
};