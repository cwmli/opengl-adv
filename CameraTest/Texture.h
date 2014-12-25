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
	std::vector<GLchar*> texture_files;
	void genGLTexture(GLuint, std::string);
	//Return a reference of the texture array  given id
	GLuint getRef();
	//Unload and remove a specific texture in a texture list
	void clearTextures();
	//Unload and remove all current textures in all texture lists
	void clearAllTextures();
	GLchar* getfilePath(int&, int&);
	std::string getdirPath(std::string);
	//Returns the number of files in the directory
	void getNFiles(std::string, std::string);
};

#endif