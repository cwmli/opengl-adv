#include "shader_init.h"

ShaderInit::ShaderInit()
{
	this->shader_list.push_back(CreateShader(GL_VERTEX_SHADER, "content/glsl/default.vs"));
	//shader_list.push_back(CreateShader(GL_GEOMETRY_SHADER, geometryPath));
	this->shader_list.push_back(CreateShader(GL_FRAGMENT_SHADER, "content/glsl/default.frag"));

	this->m_program = CreateProgram(this->shader_list);
	//remove shaders 
	std::for_each(this->shader_list.begin(), this->shader_list.end(), glDeleteShader);
}

std::string ShaderInit::get_shader_src(const GLchar* file_path)
{
	std::string shader_src;
	try
	{
		std::ifstream shader_file(file_path);
		std::stringstream shader_stream;
		//read file contents
		shader_stream << shader_file.rdbuf();
		shader_file.close();
		//convert stream into string format
		shader_src = shader_stream.str();
	}
	catch (std::exception e)
	{
		std::cout << "ERROR::Shader file read unsuccessful\n" << std::endl;
	}
	return shader_src;
}

GLuint ShaderInit::CreateShader(GLenum ShaderType, const GLchar* file_path)
{
	GLuint shader = glCreateShader(ShaderType);
	std::string shader_src = get_shader_src(file_path);
	const char *strshader_src = shader_src.c_str();
	glShaderSource(shader, 1, &strshader_src, NULL);

	glCompileShader(shader);

	//status log
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		GLint info_log_length;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &info_log_length);

		GLchar *str_info_log = new GLchar[info_log_length + 1];
		glGetShaderInfoLog(shader, info_log_length, NULL, str_info_log);

		const char *str_shader_type = NULL;
		switch (ShaderType)
		{
		case GL_VERTEX_SHADER: str_shader_type = "vertex"; break;
		case GL_GEOMETRY_SHADER: str_shader_type = "geometry"; break;
		case GL_FRAGMENT_SHADER: str_shader_type = "fragment"; break;
		}

		fprintf(stderr, "ERROR::Compile failure in %s shader:\n%s\n", str_shader_type, str_info_log);
		delete[] str_info_log;
	}

	return shader;
}

GLuint ShaderInit::CreateProgram(const std::vector<GLuint> &shader_list)
{
	GLuint program = glCreateProgram();
	//attach each shader to program in shader_list
	for (size_t loop = 0; loop < shader_list.size(); loop++)
		glAttachShader(program, shader_list[loop]);

	glLinkProgram(program);

	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint info_log_length;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &info_log_length);

		GLchar *str_info_log = new GLchar[info_log_length + 1];
		glGetProgramInfoLog(program, info_log_length, NULL, str_info_log);
		fprintf(stderr, "Linker failure: %s\n", str_info_log);
		delete[] str_info_log;
	}
	//dissociate with program
	for (size_t loop = 0; loop < shader_list.size(); loop++)
		glDetachShader(program, shader_list[loop]);

	return program;
}

void ShaderInit::Use() { glUseProgram(this->m_program); }
