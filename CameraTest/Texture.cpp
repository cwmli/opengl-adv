#include "Texture.h"

Texture::Texture(const GLchar* filePath){

};

/*Private functions*/
void Texture::genTexture(){
	/*Generate a opengl texture using SOIL library and apply texture properties*/
	//2d array handles
	GLsizei layerValue = 3;
	GLsizei mipLevel = 1;
	//gl handles
	GLuint sourceTexture;
	GLchar* filePath;
	int srctexture_Height, srctexture_Width;
	int cLayer = 0;
	//cycle through images and store in the texture array
	for (cLayer; cLayer < layerValue; cLayer++){
		//get a new image file from path
		filePath = getfilePath();
		//load the image file
		unsigned char* sourceImage = SOIL_load_image(filePath,
			&srctexture_Width, &srctexture_Height, 0, SOIL_LOAD_RGBA);
		//setup gl
		if (cLayer == 0){ //first layer, then generate textures
			glGenTextures(1, &sourceTexture);
			glBindTexture(GL_TEXTURE_2D_ARRAY, sourceTexture);		
			//allocate texture storage
			glTexStorage3D(GL_TEXTURE_2D_ARRAY, mipLevel, GL_RGBA8, srctexture_Width, srctexture_Height, layerValue);
		}
		//upload image data to the layer
		glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, cLayer, srctexture_Width, srctexture_Height, layerValue, GL_RGBA, GL_UNSIGNED_BYTE, sourceImage);
		//set hard scale then gen mipmap
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glGenerateMipmap(GL_TEXTURE_2D);
		//unbind the texture
		glBindTexture(GL_TEXTURE_2D, NULL);
		//clear the image data
		SOIL_free_image_data(sourceImage);
		srctexture_Height = 0;
		srctexture_Width = 0;
	}
	//reset layer depth
	cLayer = 0;
}	

GLchar* Texture::getfilePath(){
	/*Search for image files in local directory "content/data/.../"*/
	/*available directories are: effects, entities, environment, gui, items*/
	GLchar* texturePath = "content/data/%c/", dirName;
	return texturePath;
}


