#ifndef TEXTURE_H
#define TEXTURE_H

#include <glew.h>
#include <SOIL.h>
#include <SDL_opengl.h>

class Texture{
public:
	Texture(const GLchar*);
private:
	void genTexture();
	GLchar* getfilePath();
};

#endif