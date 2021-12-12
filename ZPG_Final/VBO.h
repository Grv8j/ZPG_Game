#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <vector>

class VBO
{
public:
	// Reference ID of the Vertex Buffer Object
	GLuint ID;
	// Constructor that generates a Vertex Buffer Object and links it to vertices
	VBO(const GLfloat* vertices, GLint verticesLen);
	VBO(std::vector<float> data);
	// Binds the VBO
	void Bind();
	// Unbinds the VBO
	void Unbind();
	// Deletes the VBO
	void Delete();

};

