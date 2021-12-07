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

void Shader::useShader()
{
	this->use();

	glUniformMatrix4fv(getUniformLocation("viewMatrix"), 1, GL_FALSE, &this->viewMatrix[0][0]);
	glUniformMatrix4fv(getUniformLocation("projectionMatrix"), 1, GL_FALSE, &this->projectionMatrix[0][0]);
	glUniform3fv(getUniformLocation("cameraPos"), 1, glm::value_ptr(this->cameraPosition));

}

GLuint Shader::getShaderProgram()
{
	return this->ID;
}

void Shader::update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, glm::vec3 cameraPosition)
{
	this->viewMatrix = viewMatrix;
	this->projectionMatrix = projectionMatrix;
	this->cameraPosition = cameraPosition;
}