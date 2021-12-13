#include "Scene.h"

Scene::Scene() 
{
	this->camera = nullptr;
	this->lightPos = glm::vec3(0.0f, 0.0f, 0.0f);
	this->directionalLight = nullptr;
}

void Scene::Draw(GLfloat timeDelta)
{
	if (this->skybox != nullptr)
	{
		this->skybox->draw();
	}

	for (Object* o : this->objects)
	{
		o->getShader()->useShader();

		if (this->directionalLight != nullptr)
		{
			o->getShader()->applyDirectionalLight(this->directionalLight);
		}

		if (this->pointLights.size() > 0)
		{
			o->getShader()->applyPointLights(this->pointLights);
		}

		if (this->reflector != nullptr)
		{
			o->getShader()->applyReflector(this->reflector);
		}

		o->getShader()->applyLight(this->lightPos);


		glStencilFunc(GL_ALWAYS, o->getID(), 0xFF);
		o->draw();
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

void Scene::setDirectionalLight(DirectionalLight* directLight)
{
	this->directionalLight = directLight;
}

void Scene::addPointLight(PointLight* pointLight)
{
	this->pointLights.push_back(pointLight);
}

void Scene::setReflector(ReflectorLight* reflector)
{
	this->reflector = reflector;
	this->camera->addReflectorListener(this->reflector);
}
