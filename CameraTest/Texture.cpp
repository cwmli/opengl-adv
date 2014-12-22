#include "Texture.h"

Texture::Texture(const GLchar* filePath){

};

void Texture::genTexture(const GLchar* filePath){
	/*Generate a opengl texture using SOIL library and apply texture properties*/
	//load the image file
	unsigned char* sourceImage = SOIL_load_image(filePath,
		&srctexture_Width, &srctexture_Height, 0, SOIL_LOAD_RGBA);
	//setup gl
	GLuint sourceTexture;
	glGenTextures(1, &sourceTexture);
	glBindTexture(GL_TEXTURE_2D, sourceTexture);
	//set texture properties
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, srctexture_Width, srctexture_Height, 0, GL_RGBA, GL_UNSIGNED_BYTE, sourceImage );
	//set hard scale
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glGenerateMipmap(GL_TEXTURE_2D);
	//unbind the texture
	glBindTexture(GL_TEXTURE_2D, NULL);
	//clear the image data
	SOIL_free_image_data(sourceImage);
}	


