#ifndef TEXTURE_H
#define TEXTURE_H

#include <glew.h>
#include <SOIL.h>
#include <SDL_opengl.h>
#include <dirent.h>
#include <glm/glm.hpp>
#include <map>
#include <vector>


namespace texture_loader{
	/*----------------
	 *-Texture loading
	------------------*/
	extern std::map<std::string, GLuint> texture_category;
	extern std::map<std::string, int> texture_layer;
	extern std::map<std::string, std::tuple<int, int>> texture_width_height;
	extern std::vector<std::string> texture_filenames;
	extern std::string texture_path;

	/*generate a gl texture given the gltexture and the directory*/
	void GenerateOGLTexture(std::string, std::string);

	/*Returns the texture and layer values for a specific texture*/
	/*category, texturename, glID, depth*/
	inline void GetReferenceByID(std::string category, std::string texName, GLuint* glID, int lDepth){
		glID = &texture_category[category];
		lDepth = texture_layer[texName];
	};

	inline void ClearTextureCategory(std::string catgName){
		texture_category.erase(catgName);
		texture_layer.erase(catgName);
		glDeleteTextures(1, &texture_category[catgName]);
	};

	inline void ClearAllTextures(){
		texture_category.clear();
		texture_layer.clear();
	};

	//ACCESSORS
	inline const char* get_file_path(int& listc_Index){
		std::string file_path = texture_path + texture_filenames[listc_Index];
		return file_path.c_str();
	};

	inline const char* get_texture_path(std::string dirName){
		return texture_path.c_str();
	};

	inline std::string get_texture_filename(int& listc_Index){
		return texture_filenames[listc_Index];
	};
	void GetNumOfFiles(const char*, const char*);

	/*----------------
	 *Texture handling
	 -----------------*/
	GLuint SetTextureData();
};

#endif