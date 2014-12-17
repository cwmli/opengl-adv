#ifndef TEXTURE_H
#define TEXTURE_H

#include <glew.h>
#include <SOIL.h>

class Texture{
public:
	GLuint glTexture;
	int srctexture_Height, srctexture_Width;
	
	Texture(const GLchar*);
private:
	void genTexture(const GLchar*);
	void applyTexture();
};

#endif