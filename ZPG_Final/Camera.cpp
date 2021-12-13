#include"Camera.h"



Camera::Camera(int width, int height, glm::vec3 position)
{
	this->Orientation = glm::vec3(0.0f, 0.0f, -1.0f);
	this->Up = glm::vec3(0.0f, 1.0f, 0.0f);
	this->Right = glm::vec3(0.0f, 1.0f, 0.0f);
	this->Position = position;

	this->yaw = def_yaw;
	this->pitch = def_pitch;
	this->MovementSpeed = def_movement_speed;
	this->Sensitivity = def_sensitivity;

	this->reflectorOberserver = nullptr;

	this->setViewMatrix();
	this->projectionMatrix = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

	this->updateCameraVectors();
}

void Camera::updateCameraVectors() {
	glm::vec3 front;
	front.x = cos(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	front.y = sin(glm::radians(this->pitch));
	front.z = sin(glm::radians(this->yaw)) * cos(glm::radians(this->pitch));
	this->Orientation = glm::normalize(front);

	// also re-calculate the Right and Up vector
	this->Right = glm::normalize(glm::cross(this->Orientation, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	this->Up = glm::normalize(glm::cross(this->Right, this->Orientation));
}

glm::mat4 Camera::getViewMatrix()
{
	return this->viewMatrix;
}

glm::mat4 Camera::getProjectionMatrix()
{
	return this->projectionMatrix;
}


void Camera::processKeyboardMovement(CAM_MOVE direction)
{
	GLfloat velocity = this->MovementSpeed;
	printf("direction %d\n", direction);
	switch (direction)
	{
		case CAM_MOVE::FORWARD:
			this->Position += this->Orientation * velocity;
			break;

		case CAM_MOVE::BACKWARD:
			this->Position -= this->Orientation * velocity;
			break;

		case CAM_MOVE::LEFT:
			this->Position -= this->Right * velocity;
			break;

		case CAM_MOVE::RIGHT:
			this->Position += this->Right * velocity;
			break;

		case CAM_MOVE::UP:
			this->Position += this->Up * velocity;
			break;

		case CAM_MOVE::DOWN:
			this->Position -= this->Up * velocity;
			break;	
	}

	this->setViewMatrix();
	this->notify();
}

void Camera::setViewMatrix()
{
	this->viewMatrix = glm::lookAt(this->Position, this->Position + this->Orientation, WorldUp);
}

void Camera::processMouseMovement(double xoffset, double yoffset, GLboolean constrainPitch) {
	this->yaw += xoffset * this->Sensitivity;
	this->pitch -= yoffset * this->Sensitivity;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch)
	{
		if (this->pitch > 89.0f)
			this->pitch = 89.0f;
		if (this->pitch < -89.0f)
			this->pitch = -89.0f;
	}

	this->updateCameraVectors();
	this->setViewMatrix();
	this->notify();
}

void Camera::addShaderListener(ShaderObserver* observer)
{
	this->shaderObservers.push_back(observer);
}

void Camera::deleteShaderListener(ShaderObserver* observer)
{
	this->shaderObservers.erase(std::remove(this->shaderObservers.begin(), this->shaderObservers.end(), observer), this->shaderObservers.end());
}

void Camera::addSkyboxListener(SkyboxObserver* observer)
{
	this->skyboxObservers.push_back(observer);
}

void Camera::deleteSkyboxListener(SkyboxObserver* observer)
{
	this->skyboxObservers.erase(std::remove(this->skyboxObservers.begin(), this->skyboxObservers.end(), observer), this->skyboxObservers.end());
}

void Camera::addReflectorListener(ReflectorObserver* observer)
{
	this->reflectorOberserver = observer;
}

void Camera::deleteReflectorListener(ReflectorObserver* observer)
{
	this->reflectorOberserver = nullptr;
}


void Camera::notify()
{
	for (ShaderObserver* sh : this->shaderObservers)
	{
		sh->update(this->viewMatrix, this->projectionMatrix, this->Position);
	}


	for (SkyboxObserver* so : this->skyboxObservers)
	{
		so->update(this->Position);
	}

	if (this->reflectorOberserver != nullptr)
	{
		this->reflectorOberserver->update(this->Position, this->Orientation);
	}
}