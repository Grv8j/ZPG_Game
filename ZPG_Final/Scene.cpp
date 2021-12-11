#include "Scene.h"

Scene::Scene() 
{
	this->camera = nullptr;
	this->lightPos = glm::vec3(0.0f, 0.0f, 5.0f);
}

void Scene::Draw(GLfloat timeDelta)
{
	if (this->skybox != nullptr)
	{
		this->skybox->draw();
	}

	for (Object* element : this->objects)
	{
		element->getShader()->applyLight(this->lightPos);
		element->getShader()->useShader();
		element->draw();
	}
}

Camera* Scene::getCamera()
{
	return this->camera;
}

void Scene::setCamera(Camera* camera)
{
	this->camera = camera;
}

void Scene::AddObject(Object* object)
{
	this->objects.push_back(object);
}

void Scene::SetLightPos(glm::vec3 lightPos)
{
	this->lightPos = lightPos;
}

void Scene::setSkybox(Skybox* skybox)
{
	this->skybox = skybox;
	this->camera->addSkyboxListener(this->skybox);
}
