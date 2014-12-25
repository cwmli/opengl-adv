#ifndef TEXTURE_H
#define TEXTURE_H

#include <glew.h>
#include <SOIL.h>
#include <SDL_opengl.h>
#include <vector>

class Texture{
public:
	Texture(const GLchar*);
private:
	//std::vector<std::string, GLint> texture_ids;
	//std::vector<std::string, int> textureid_layer;
	std::vector<std::string> texture_filenames;
	std::string texturePath;

	void genGLTexture(GLuint, std::string);
	GLuint getRefbyID();

	void clearTextures();
	void clearAllTextures();

	//ACCESSORS
	const char* getfilePath(int&);
	std::string getdirPath(std::string);
	std::string getTexName(int&);
	void getNFiles(std::string, std::string);
};

#endif