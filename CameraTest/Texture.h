#ifndef TEXTURE_H
#define TEXTURE_H

#include <glew.h>
#include <SOIL.h>
#include <SDL_opengl.h>
#include <vector>

class Texture{
public:
	std::vector<GLuint> glTexture;
	int srctexture_Height, srctexture_Width;
	
	Texture(const GLchar*);
private:
	void genTexture(const GLchar*);
	void applyTexture();
};

#endif