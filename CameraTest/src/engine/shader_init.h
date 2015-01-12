#ifndef SHADER_H
#define SHADER_H

#include <vector>

#include <glew.h>

class ShaderInit
{
public:
	GLuint m_program;
	std::vector<GLuint> shader_list;
	//Shader program constructor
	ShaderInit();
	void Use();
private:
	std::string get_shader_src(const GLchar* file_path);
	GLuint CreateShader(GLenum, const GLchar*);
	GLuint CreateProgram(const std::vector<GLuint> &);

};
#endif