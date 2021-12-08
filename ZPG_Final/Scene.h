#pragma once
#include "Object.h"
#include "Camera.h"
#include <vector>

class Scene
{
private:
	std::vector <Object*> objects;
	Camera* camera;
	glm::vec3 lightPos;
public:
	Scene();
	void Draw(GLfloat timeDelta);
	void setCamera(Camera* camera);
	void AddObject(Object* object);
	void SetLightPos(glm::vec3 lightPos);

	Camera* getCamera();
};

