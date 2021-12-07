#include "Shader.h"

Shader::Shader(GLuint ID)
{
	this->ID = ID;
}

Shader::Shader(const char* vertex_shader, const char* fragment_shader)
{
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_shader, NULL);
	glCompileShader(vertexShader);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
	glCompileShader(fragmentShader);
	this->ID = glCreateProgram();
	glAttachShader(this->ID, fragmentShader);
	glAttachShader(this->ID, vertexShader);
	glLinkProgram(this->ID);

	GLint status;
	glGetProgramiv(this->ID, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(this->ID, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(this->ID, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
		throw(1);
	}
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