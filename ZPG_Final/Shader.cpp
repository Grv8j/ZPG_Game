#include "Shader.h"

Shader::Shader(GLuint ID)
{
	this->ID = ID;
}

Shader::Shader(const char* vertex_shader, const char* fragment_shader)
{
	this->ID = loadShader(vertex_shader, fragment_shader);
}

void Shader::use() const
{
	glUseProgram(this->ID);
}

GLint Shader::getUniformLocation(const char* name)
{
	return glGetUniformLocation(this->ID, name);
}

void Shader::applyTransform(glm::mat4 transformMatrix)
{
	glUniformMatrix4fv(this->getUniformLocation("modelMatrix"), 1, GL_FALSE, &transformMatrix[0][0]);
}

void Shader::useShader()
{
	this->use();

	glUniformMatrix4fv(this->getUniformLocation("viewMatrix"), 1, GL_FALSE, &this->viewMatrix[0][0]);
	glUniformMatrix4fv(this->getUniformLocation("projectionMatrix"), 1, GL_FALSE, &this->projectionMatrix[0][0]);
	glUniform3fv(this->getUniformLocation("cameraPos"), 1, glm::value_ptr(this->cameraPosition));

}

void Shader::update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, glm::vec3 cameraPosition)
{
	this->viewMatrix = viewMatrix;
	this->projectionMatrix = projectionMatrix;
	this->cameraPosition = cameraPosition;
}

void Shader::applyLight(glm::vec3 lightPosition)
{
	glUniform3fv(this->getUniformLocation("lightPos"), 1, glm::value_ptr(lightPosition));
}

void Shader::applyDirectionalLight(DirectionalLight* light)
{
	glUniform3fv(this->getUniformLocation("dirLight.ambient"), 1, glm::value_ptr(light->getAmbient()));
	glUniform3fv(this->getUniformLocation("dirLight.diffuse"), 1, glm::value_ptr(light->getDiffuse()));
	glUniform3fv(this->getUniformLocation("dirLight.specular"), 1, glm::value_ptr(light->getSpectacular()));
	glUniform3fv(this->getUniformLocation("dirLight.direction"), 1, glm::value_ptr(light->getDirection()));
}

void Shader::applyPointLights(std::vector<PointLight*> pointLights)
{
	for (int i = 0; i < pointLights.size(); i++)
	{
		std::string position = std::string("pointLights[") + std::to_string(i) + std::string("]");
		glUniform3fv(this->getUniformLocation((position + std::string(".ambient")).c_str()), 1, glm::value_ptr(pointLights[i]->getAmbient()));
		glUniform3fv(this->getUniformLocation((position + std::string(".diffuse")).c_str()), 1, glm::value_ptr(pointLights[i]->getDiffuse()));
		glUniform3fv(this->getUniformLocation((position + std::string(".specular")).c_str()), 1, glm::value_ptr(pointLights[i]->getSpectacular()));
		glUniform3fv(this->getUniformLocation((position + std::string(".position")).c_str()), 1, glm::value_ptr(pointLights[i]->getPosition()));
		glUniform1f(this->getUniformLocation((position + std::string(".constant")).c_str()), pointLights[i]->getConstant());
		glUniform1f(this->getUniformLocation((position + std::string(".linear")).c_str()), pointLights[i]->getLinear());
		glUniform1f(this->getUniformLocation((position + std::string(".quadratic")).c_str()), pointLights[i]->getQuadratic());
	}

	glUniform1i(this->getUniformLocation("pointLightsCount"), pointLights.size());
}

void Shader::applyReflector(ReflectorLight* reflector)
{
	glUniform3fv(this->getUniformLocation("flashlight.ambient"), 1, glm::value_ptr(reflector->getAmbient()));
	glUniform3fv(this->getUniformLocation("flashlight.diffuse"), 1, glm::value_ptr(reflector->getDiffuse()));
	glUniform3fv(this->getUniformLocation("flashlight.specular"), 1, glm::value_ptr(reflector->getSpectacular()));
	glUniform3fv(this->getUniformLocation("flashlight.direction"), 1, glm::value_ptr(reflector->getDirection()));
	glUniform3fv(this->getUniformLocation("flashlight.position"), 1, glm::value_ptr(reflector->getPosition()));
	glUniform1f(this->getUniformLocation("flashlight.constant"), reflector->getConstant());
	glUniform1f(this->getUniformLocation("flashlight.linear"), reflector->getLinear());
	glUniform1f(this->getUniformLocation("flashlight.quadratic"), reflector->getQuadratic());
	glUniform1f(this->getUniformLocation("flashlight.cutOff"), reflector->getCutOff());
	glUniform1f(this->getUniformLocation("flashlight.outerCutOff"), reflector->getOuterCutOff());
}
