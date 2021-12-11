#pragma once
#include "Object.h"
#include "Camera.h"
#include "Skybox.h"
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

class Scene
{
private:
	std::vector <Object*> objects;
	Camera* camera;
	Skybox* skybox;
	glm::vec3 lightPos;
public:
	Scene();
	void Draw(GLfloat timeDelta);
	void setCamera(Camera* camera);
	void AddObject(Object* object);
	void SetLightPos(glm::vec3 lightPos);
	void setSkybox(Skybox* skybox);

	Camera* getCamera();
};

