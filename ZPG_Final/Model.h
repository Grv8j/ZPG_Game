#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "VAO.h"
#include "VBO.h"
#include "Texture.h"
#include <assimp/Importer.hpp>// C++ importerinterface
#include <assimp/scene.h>// aiSceneoutputdata structure
#include <assimp/postprocess.h>// Post processingflags#include <memory>
#include <vector>

class Model
{
private:
    int pointNo;
    VAO* vao;
    VBO* vbo;
    GLenum mode;
    Texture* texture;


public:
    //Model(TEX tex, const GLfloat *points, int size, int lineLen, int vecLen = 3, int uniformCount = 0, GLenum mode = GL_TRIANGLES);
    Model(const GLfloat* points, int size, int lineLen, Texture* texture = nullptr, bool onlyTex = false);
    Model(const char* path, Texture* texture);
    VAO* getVAO();
    VBO* getVBO();
    int getPointNo();
    GLenum getMode();
    void setTexture(Texture* texture);
    Texture* getTexture();
};
