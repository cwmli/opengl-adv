#include "texture_loader.h"

#include <glew.h>
#include <SOIL.h>
#include <dirent.h>
#include <glm/glm.hpp>

namespace texture_loader{
	std::map<std::string, GLuint> texture_category;
	std::map<std::string, int> texture_layer;
	std::map<std::string, std::tuple<int, int>> texture_width_height;
	std::vector<std::string> texture_filenames;
	std::string texture_path;

	/*Generate the opengl texture with an ID.*/
	/*-source_texture specifies the opengl texture to modify*/
	/*-c_dir specifies the current directory name of texture files(category) */
	void texture_loader::GenerateOGLTexture(std::string c_dir, std::string subfolder){
		GLuint source_texture;
		//populate our texture_filenames list
		texture_path = "content/data/%c/%c", c_dir, subfolder;
		GetNumOfFiles(get_texture_path(c_dir), "png");//only accepting png image format
		//restrict mipmap level to 1, we do not need mipmaps
		GLsizei mip_level = 1;
		GLsizei layer_max = texture_filenames.size();
		const char* file_path;
		int srctexture_Height, srctexture_Width;
		int current_layer = 0;
		for (current_layer; current_layer < layer_max; current_layer++){
			file_path = get_file_path(current_layer);
			unsigned char* source_image = SOIL_load_image(file_path,
				&srctexture_Width, &srctexture_Height, 0, SOIL_LOAD_RGBA);
			//setup gl for the first time
			if (current_layer == 0){
				glGenTextures(1, &source_texture);
				glBindTexture(GL_TEXTURE_2D_ARRAY, source_texture);
				glTexStorage3D(GL_TEXTURE_2D_ARRAY, mip_level, GL_RGBA8, srctexture_Width, srctexture_Height, layer_max);
			}
			glTexSubImage3D(GL_TEXTURE_2D_ARRAY, 0, 0, 0, current_layer, srctexture_Width, srctexture_Height, layer_max, GL_RGBA, GL_UNSIGNED_BYTE, source_image);
			//set hard scale then generate mipmap
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
			glGenerateMipmap(GL_TEXTURE_2D);
			glBindTexture(GL_TEXTURE_2D, NULL);
			//texture tracker
			texture_layer[get_texture_filename(current_layer)] = current_layer;
			texture_width_height[get_texture_filename(current_layer)] = std::make_tuple(srctexture_Width, srctexture_Height);
			//clear the image data
			SOIL_free_image_data(source_image);
			srctexture_Height = 0;
			srctexture_Width = 0;
		}
		texture_category[c_dir] = source_texture;
		//finished iterating through list, dispose data and reset
		texture_filenames.clear();
		current_layer = 0;
	}

	/*Get the number of files in the current directory and store each file name in a list.*/
	/*-dirPath specifies the directory path to search*/
	/*-fileFormat refers to which type of file should be included
	in counting the number of files in directory.*/
	void texture_loader::GetNumOfFiles(const char* dirPath, const char* fileFormat){
		DIR* dir;
		struct dirent *ent;
		if ((dir = opendir(dirPath)) != NULL){
			while ((ent = readdir(dir)) != NULL){
				std::string tempFn = ent->d_name;
				if (tempFn.substr(tempFn.find_last_of(".") + 1) == fileFormat){
					texture_filenames.push_back(ent->d_name);//store just filename ignore extension
					printf("INFO::Loaded file: %s\n", ent->d_name);
				}
			}
			closedir(dir);
		}
		else{
			printf("ERROR::Local directory: \"%s\" does not exist or no files detected.\n", dirPath);
		}
	}
}
