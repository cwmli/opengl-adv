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
	std::map<std::string, GLuint> texture_catg;
	std::map<std::string, int> textureid_layer;
	std::map<std::string, std::tuple<int,int>> textureid_wh;

	void getRefbyID(std::string, std::string, GLuint*, int*);

	std::vector<std::string> texture_filenames;
	std::string texturePath;
	void genGLTexture(GLuint, std::string);

	void clearTextureCatg(std::string);
	void clearAllTextures();

	//ACCESSORS
	const char* getfilePath(int&);
	const char* getdirPath(std::string);
	std::string getTexName(int&);
	void getNFiles(const char*, const char*);
};

#endif