#pragma once
#pragma once

#include <stdexcept>
#include <glm/vec4.hpp>
#include <glm/mat4x4.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include <vector>
#include <memory>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<glm/gtc/type_ptr.hpp>

#include "ShaderLoader.h"
#include "ShaderObserver.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "ReflectorLight.h"

class Shader : public ShaderObserver, public ShaderLoader
{
private:
	GLuint ID;
	glm::mat4 viewMatrix;
	glm::mat4 projectionMatrix;
	glm::vec3 cameraPosition;

	void use() const;
public:
	Shader(GLuint ID);
	Shader(const char* vertex_shader, const char* fragment_shader);
	void useShader();
	GLuint getShaderProgram();
	virtual void update(glm::mat4 viewMatrix, glm::mat4 projectionMatrix, glm::vec3 cameraPosition);

	void applyLight(glm::vec3 lightPosition);
	void applyDirectionalLight(DirectionalLight* light);
	void applyPointLights(std::vector<PointLight*> pointLights);
	void applyReflector(ReflectorLight* reflector);

	GLint getUniformLocation(const char* name);
	void applyTransform(glm::mat4 transformMatrix);
};