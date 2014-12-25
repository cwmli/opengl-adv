#include "Texture.h"

//called once during startup
Texture::Texture(const GLchar* filePath){

};

/*Generate the opengl texture with an ID.*/
/*-sourceTexture specifies the opengl texture to modify*/
/*-c_dir specifies the current directory name of texture files */
void Texture::genGLTexture(GLuint sourceTexture, std::string c_dir){
	//populate our texture_filenames list
	getNFiles(getdirPath(c_dir), ".png");//only accepting png image format
	//restrict mipmap level to 1, we do not need mipmaps
	GLsizei mipLevel = 1;
	GLsizei layerValue = 0;//texture_filenames.size;
	const char* filePath;
	GLint texID;
	int srctexture_Height, srctexture_Width;
	int cLayer = 0;
	for (cLayer; cLayer < layerValue; cLayer++){
		filePath = getfilePath(cLayer);
		unsigned char* sourceImage = SOIL_load_image(filePath,
			&srctexture_Width, &srctexture_Height, 0, SOIL_LOAD_RGBA);
		//setup gl for the first time
		if (cLayer == 0){ 
			glGenTextures(1, &sourceTexture);
			glBindTexture(GL_TEXTURE_2D_ARRAY, sourceTexture);		
			glGetIntegerv(GL_TEXTURE_BINDING_2D, &texID);
			glTexStorage3D(GL_TEXTURE_2D_ARRAY, mipLevel, GL_RGBA8, srctexture_Width, srctexture_Height, layerValue);
		}
		glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, cLayer, srctexture_Width, srctexture_Height, layerValue, GL_RGBA, GL_UNSIGNED_BYTE, sourceImage);
		//set hard scale then generate mipmap
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glGenerateMipmap(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, NULL);
		//texture tracker
		//this->texture_ids[getTexName(cLayer)].push_back(texID);
		//this->textureid_layer[getTexName(cLayer)].push_back(cLayer);
		//clear the image data
		SOIL_free_image_data(sourceImage);
		srctexture_Height = 0;
		srctexture_Width = 0;
	}
	//finished iterating through list, dispose data and reset
	//texture_filenames.clear();
	cLayer = 0;
}	

const char* Texture::getfilePath(int& listc_Index){
	std::string filePath;
	//filePath = texturePath + texture_filenames[listc_Index];
	const char* data = filePath.c_str();
	return data;
}

/*-Available directories are: effects, entities, environment, gui, items.*/
std::string Texture::getdirPath(std::string dirName){
	this->texturePath = "content/data/%c/", dirName;
	return texturePath;
}

std::string Texture::getTexName(int& listc_Index){
	//return texture_filenames[listc_Index];
}

/*Get the number of files in the current directory and store each file name in a list.*/
/*-dirPath specifies the directory path to search*/
/*-fileFormat refers to which type of file should be included
in counting the number of files in directory.*/
void Texture::getNFiles(std::string dirPath,std::string fileFormat){

}

