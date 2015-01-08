#include "textureManager.h"

namespace textureManager{
	std::map<std::string, GLuint*> texture_catg;
	std::map<std::string, int> textureid_layer;
	std::map<std::string, std::tuple<int, int>> textureid_wh;
	std::vector<std::string> texture_filenames;
	std::string texturePath;

	/*Generate the opengl texture with an ID.*/
	/*-sourceTexture specifies the opengl texture to modify*/
	/*-c_dir specifies the current directory name of texture files(category) */
	void textureManager::genGLTexture(GLuint sourceTexture, std::string c_dir){
		//populate our texture_filenames list
		texturePath = "content/data/%c/", c_dir;
		getNFiles(getdirPath(c_dir), "png");//only accepting png image format
		//restrict mipmap level to 1, we do not need mipmaps
		GLsizei mipLevel = 1;
		GLsizei layerMAX = texture_filenames.size();
		const char* filePath;
		int srctexture_Height, srctexture_Width;
		int cLayer = 0;
		for (cLayer; cLayer < layerMAX; cLayer++){
			filePath = getfilePath(cLayer);
			unsigned char* sourceImage = SOIL_load_image(filePath,
				&srctexture_Width, &srctexture_Height, 0, SOIL_LOAD_RGBA);
			//setup gl for the first time
			if (cLayer == 0){
				glGenTextures(1, &sourceTexture);
				glBindTexture(GL_TEXTURE_2D_ARRAY, sourceTexture);
				glTexStorage3D(GL_TEXTURE_2D_ARRAY, mipLevel, GL_RGBA8, srctexture_Width, srctexture_Height, layerMAX);
			}
			glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, cLayer, srctexture_Width, srctexture_Height, layerMAX, GL_RGBA, GL_UNSIGNED_BYTE, sourceImage);
			//set hard scale then generate mipmap
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glGenerateMipmap(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, NULL);
			//texture tracker
			textureid_layer[getTexName(cLayer)] = cLayer;
			textureid_wh[getTexName(cLayer)] = std::make_tuple(srctexture_Width, srctexture_Height);
			//clear the image data
			SOIL_free_image_data(sourceImage);
			srctexture_Height = 0;
			srctexture_Width = 0;
		}
		texture_catg[c_dir] = &sourceTexture;
		//finished iterating through list, dispose data and reset
		texture_filenames.clear();
		cLayer = 0;
	}

	void textureManager::getRefbyID(std::string category, std::string texName, GLuint* glID, int lDepth){
		glID = texture_catg[category];
		lDepth = textureid_layer[texName];
	}

	void textureManager::clearTextureCatg(std::string catgName){
		texture_catg.erase(catgName);
		textureid_layer.erase(catgName);
		glDeleteTextures(1, texture_catg[catgName]);
	}

	void textureManager::clearAllTextures(){
		texture_catg.clear();
		textureid_layer.clear();
	}

	const char* textureManager::getfilePath(int& listc_Index){
		std::string filePath = texturePath + texture_filenames[listc_Index];
		return filePath.c_str();
	}

	/*-Available directories are: effects, entities, environment, gui, items.*/
	const char* textureManager::getdirPath(std::string dirName){
		return texturePath.c_str();
	}

	std::string textureManager::getTexName(int& listc_Index){
		return texture_filenames[listc_Index];
	}

	/*Get the number of files in the current directory and store each file name in a list.*/
	/*-dirPath specifies the directory path to search*/
	/*-fileFormat refers to which type of file should be included
	in counting the number of files in directory.*/
	void textureManager::getNFiles(const char* dirPath, const char* fileFormat){
		DIR* dir;
		struct dirent *ent;
		if ((dir = opendir(dirPath)) != NULL){
			printf("[INFO]Opened directory: \"%s\"\n", dirPath);
			while ((ent = readdir(dir)) != NULL){
				std::string tempFn = ent->d_name;
				if (tempFn.substr(tempFn.find_last_of(".") + 1) == fileFormat){
					texture_filenames.push_back(ent->d_name);//store just filename ignore extension
					printf("[INFO]Loaded file: %s\n", ent->d_name);
				}
			}
			closedir(dir);
			printf("[INFO]All files loaded from \"%s\" matching %s format\n", dirPath, fileFormat);
		}
		else{
			printf("[ERROR]Local directory: \"%s\" does not exist or no files detected.\n", dirPath);
		}
	}
}
