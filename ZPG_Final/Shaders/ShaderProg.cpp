#include "ShaderProg.h"

ShaderProg::ShaderProg(GLuint shaderProgID) {
	this->shaderProgram = shaderProgID;
}
ShaderProg::ShaderProg(const char* vertex_shader, const char* fragment_shader) {
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex_shader, NULL);
	glCompileShader(vertexShader);
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment_shader, NULL);
	glCompileShader(fragmentShader);
	this->shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, fragmentShader);
	glAttachShader(shaderProgram, vertexShader);
	glLinkProgram(shaderProgram);

	GLint status;
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(shaderProgram, GL_INFO_LOG_LENGTH, &infoLogLength);
		GLchar* strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(shaderProgram, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
		throw(1);
	}
}

void ShaderProg::useShader() {
	glUseProgram(shaderProgram);

	GLint idViewMat = glGetUniformLocation(shaderProgram, "viewMatrix");
	GLint idProjMat = glGetUniformLocation(shaderProgram, "projectionMatrix");
	GLint idCamPos = glGetUniformLocation(shaderProgram, "cameraPos");


	glUniformMatrix4fv(idViewMat, 1, GL_FALSE, &this->viewMatrix[0][0]);
	glUniformMatrix4fv(idProjMat, 1, GL_FALSE, &this->projectionMatrix[0][0]);
	glUniform3fv(idCamPos, 1, glm::value_ptr(this->cameraPosition));

}

GLuint ShaderProg::getShaderProgram() {
	return shaderProgram;
}

void ShaderProg::update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, glm::vec3 cameraPosition)
{
	this->viewMatrix = viewMatrix;
	this->projectionMatrix = projectionMatrix;
	this->cameraPosition = cameraPosition;
}