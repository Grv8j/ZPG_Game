#include"Camera.h"



Camera::Camera(int width, int height, glm::vec3 position)
{
	Position = position;
	yaw = -90.0f;
	pitch = 0.0f;
	MovementSpeed = 0.1f;
	viewMat = glm::lookAt(Position, Position + Orientation, WorldUp);
	projMat = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);
	CalcOrientation();
}

void Camera::UpdateShader(GLuint shaderProg) {
	GLint idViewMat = glGetUniformLocation(shaderProg, "viewMatrix");
	GLint idProjMat = glGetUniformLocation(shaderProg, "projectionMatrix");

	glUniformMatrix4fv(idViewMat, 1, GL_FALSE, &viewMat[0][0]);
	glUniformMatrix4fv(idProjMat, 1, GL_FALSE, &projMat[0][0]);

}

void Camera::CalcOrientation() {
	glm::vec3 front;
	front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	front.y = sin(glm::radians(pitch));
	front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	Orientation = glm::normalize(front);
	// also re-calculate the Right and Up vector
	Right = glm::normalize(glm::cross(Orientation, WorldUp));  // normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
	Up = glm::normalize(glm::cross(Right, Orientation));
}

void Camera::CalcView() {
	viewMat = glm::lookAt(Position, Position + Orientation, WorldUp);
	this->notify();
}

void Camera::Move(CAM_MOVE direction)
{
	GLfloat velocity = MovementSpeed;
	printf("direction %d\n", direction);
	switch (direction)
	{
		case CAM_MOVE::FORWARD:
			Position += Orientation * velocity;
			break;

		case CAM_MOVE::BACKWARD:
			Position -= Orientation * velocity;
			break;

		case CAM_MOVE::LEFT:
			Position -= Right * velocity;
			break;

		case CAM_MOVE::RIGHT:
			Position += Right * velocity;
			break;

		case CAM_MOVE::UP:
			Position += Up * velocity;
			break;

		case CAM_MOVE::DOWN:
			Position -= Up * velocity;
			break;	
	}

	CalcView();
}

void Camera::Rotate(double xoffset, double yoffset, GLboolean constrainPitch) {
	yaw += xoffset * Sensitivity;
	pitch -= yoffset * Sensitivity;

	// make sure that when pitch is out of bounds, screen doesn't get flipped
	if (constrainPitch)
	{
		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;
	}

	CalcOrientation();
	CalcView();
}

void Camera::addListener(Observer* observer)
{
	this->shaderObservers.push_back((ShaderObserver*)observer);
}

void Camera::deleteListener(Observer* observer)
{
	this->shaderObservers.erase(std::remove(this->shaderObservers.begin(), this->shaderObservers.end(), (ShaderObserver*)observer), this->shaderObservers.end());
}

void Camera::notify()
{
	for (ShaderObserver* o : this->shaderObservers)
	{
		o->update(this->viewMat, this->projMat, this->Position);
	}
}