#include "shaderInit.h"

shaderInit::shaderInit()
{
	this->shaderList.push_back(CreateShader(GL_VERTEX_SHADER, "content/glsl/default.vs"));
	//shaderList.push_back(CreateShader(GL_GEOMETRY_SHADER, geometryPath));
	this->shaderList.push_back(CreateShader(GL_FRAGMENT_SHADER, "content/glsl/default.frag"));

	this->theProgram = CreateProgram(this->shaderList);
	//remove shaders 
	std::for_each(this->shaderList.begin(), this->shaderList.end(), glDeleteShader);
}

std::string shaderInit::GetShaderSrc(const GLchar* filePath)
{
	std::string ShaderSrc;
	try
	{
		std::ifstream ShaderFile(filePath);
		std::stringstream ShaderStream;
		//read file contents
		ShaderStream << ShaderFile.rdbuf();
		ShaderFile.close();
		//convert stream into string format
		ShaderSrc = ShaderStream.str();
	}
	catch (std::exception e)
	{
		std::cout << "ERROR::Shader file read unsuccessful\n" << std::endl;
	}
	return ShaderSrc;
}

GLuint shaderInit::CreateShader(GLenum ShaderType, const GLchar* filePath)
{
	GLuint shader = glCreateShader(ShaderType);
	std::string ShaderSrc = GetShaderSrc(filePath);
	const char *strShaderSrc = ShaderSrc.c_str();
	glShaderSource(shader, 1, &strShaderSrc, NULL);

	glCompileShader(shader);

	//status log
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	if (status != GL_TRUE)
	{
		GLint infoLogLength;
		glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetShaderInfoLog(shader, infoLogLength, NULL, strInfoLog);

		const char *strShaderType = NULL;
		switch (ShaderType)
		{
		case GL_VERTEX_SHADER: strShaderType = "vertex"; break;
		case GL_GEOMETRY_SHADER: strShaderType = "geometry"; break;
		case GL_FRAGMENT_SHADER: strShaderType = "fragment"; break;
		}

		fprintf(stderr, "ERROR::Compile failure in %s shader:\n%s\n", strShaderType, strInfoLog);
		delete[] strInfoLog;
	}

	return shader;
}

GLuint shaderInit::CreateProgram(const std::vector<GLuint> &shaderList)
{
	GLuint program = glCreateProgram();
	//attach each shader to program in shaderlist
	for (size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
		glAttachShader(program, shaderList[iLoop]);

	glLinkProgram(program);

	GLint status;
	glGetProgramiv(program, GL_LINK_STATUS, &status);
	if (status == GL_FALSE)
	{
		GLint infoLogLength;
		glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLength);

		GLchar *strInfoLog = new GLchar[infoLogLength + 1];
		glGetProgramInfoLog(program, infoLogLength, NULL, strInfoLog);
		fprintf(stderr, "Linker failure: %s\n", strInfoLog);
		delete[] strInfoLog;
	}
	//dissociate with program
	for (size_t iLoop = 0; iLoop < shaderList.size(); iLoop++)
		glDetachShader(program, shaderList[iLoop]);

	return program;
}

void shaderInit::Use() { glUseProgram(this->theProgram); }