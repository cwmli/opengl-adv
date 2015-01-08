#ifndef TEXTURE_H
#define TEXTURE_H

#include <glew.h>
#include <SOIL.h>
#include <SDL_opengl.h>
#include <dirent.h>
#include <glm/glm.hpp>
#include <map>
#include <vector>


namespace textureManager{
	/*----------------
	 *-Texture loading
	------------------*/
	extern std::map<std::string, GLuint*> texture_catg;
	extern std::map<std::string, int> textureid_layer;
	extern std::map<std::string, std::tuple<int, int>> textureid_wh;
	extern std::vector<std::string> texture_filenames;
	extern std::string texturePath;

	/*Returns the texture and layer values for a specific texture*/
	/*category, texturename, glID, depth*/
	void getRefbyID(std::string, std::string, GLuint*, int);
	/*generate a gl texture given the gltexture and the directory*/
	void genGLTexture(GLuint, std::string);

	void clearTextureCatg(std::string);
	void clearAllTextures();

	//ACCESSORS
	const char* getfilePath(int&);
	const char* getdirPath(std::string);
	std::string getTexName(int&);
	void getNFiles(const char*, const char*);

	/*----------------
	 *Texture handling
	 -----------------*/
	GLuint setTextureData();
};

#endif