#include "Texture.h"

Texture::Texture(const GLchar* filePath){

};

/*Generate the opengl texture with an ID.*/
/*-sourceTexture specifies the opengl texture to modify*/
/*-c_dir specifies the current directory name of texture files */
void Texture::genGLTexture(GLuint sourceTexture, std::string c_dir){
	//populate texture list
	getNFiles(getdirPath(c_dir), ".png");//only accepting png image format
	//restrict mipmap level to 1, we do not need mipmaps
	GLsizei mipLevel = 1;
	GLsizei layerValue = texture_files.size;
	//gl handles
	GLchar* filePath;
	GLint texID;
	int srctexture_Height, srctexture_Width;
	int cLayer = 0;
	//cycle through image files and store in the texture array
	for (cLayer; cLayer < layerValue; cLayer++){
		//get a new image file from path
		filePath = getfilePath(cLayer, layerValue);
		//load the image file
		unsigned char* sourceImage = SOIL_load_image(filePath,
			&srctexture_Width, &srctexture_Height, 0, SOIL_LOAD_RGBA);
		//setup gl for the first time
		if (cLayer == 0){ 
			glGenTextures(1, &sourceTexture);
			glBindTexture(GL_TEXTURE_2D_ARRAY, sourceTexture);		
			//get the gl texture id
			glGetIntegerv(GL_TEXTURE_BINDING_2D, &texID);
			//allocate texture storage
			glTexStorage3D(GL_TEXTURE_2D_ARRAY, mipLevel, GL_RGBA8, srctexture_Width, srctexture_Height, layerValue);
		}
		//upload image data to the layer
		glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, cLayer, srctexture_Width, srctexture_Height, layerValue, GL_RGBA, GL_UNSIGNED_BYTE, sourceImage);
		//set hard scale then generate mipmap
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
	//finished iterating through list, dispose data and reset
	texture_files.clear();
	cLayer = 0;
}	

/*Iterate through a texture file listing and return each value.*/
GLchar* Texture::getfilePath(int& listc_Index, int& listMAX){
	GLchar* texName;
	texName = texture_files[listc_Index];
	return texName;
}

/*Return the texture directory.*/
/*-Available directories are: effects, entities, environment, gui, items.*/
std::string Texture::getdirPath(std::string dirName){
	std::string texturePath = "content/data/%c/", dirName;
	return texturePath;
}

/*Get the number of files in the current directory and store each file name in a list.*/
/*-dirPath specifies the directory path to search*/
/*-fileFormat refers to which type of file should be included
in counting the number of files in directory.*/
void Texture::getNFiles(std::string dirPath,std::string fileFormat){

}

