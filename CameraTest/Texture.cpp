#include "Texture.h"

Texture::Texture(const GLchar* filePath){

};

void Texture::genTexture(const GLchar* filePath){
	//load the image file
	unsigned char* sourceImage = SOIL_load_image(filePath,
		&srctexture_Width, &srctexture_Height, 0, SOIL_LOAD_RGBA);
	//setup gl
	GLuint sourceTexture;
	glGenTextures(1, &sourceTexture);
	glBindTexture(GL_TEXTURE_2D, sourceTexture);
	//set texture properties
	glTexImage2D(sourceTexture,)
}

