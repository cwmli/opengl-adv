#define GLEW_STATIC
#include <glew.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
// GLM Math
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

//function prototypes
#include "Shader.h"
#include "MoveHandler.h"
#include "Camera.h"

objCamera Camera;
MoveHandler keyHandler;
void sdlerr(const char* msg)
{
	printf("%s: %s\n", msg, SDL_GetError());
	SDL_Quit();
	exit(1);
}

int main(int argc, char *argv[])
{
	//handles
	SDL_Window *window;
	SDL_GLContext context;
	SDL_Event windowEvent;
	//attempt to initialize sdl
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		sdlerr("ERROR::Unable to initialize SDL\n");
	//forward compatibility with opengl 3.x
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	//setup opengl window and context
	window = SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_INPUT_GRABBED);
	if (!window)
		sdlerr("ERROR::Unable to create window\n");
	context = SDL_GL_CreateContext(window);
	SDL_WarpMouseInWindow(window, 400, 300);
	SDL_SetRelativeMouseMode(SDL_TRUE);
	//modern glew initialize attempt
	glewExperimental = GL_TRUE;
	if (glewInit() < 0)
		printf("ERROR::Unable to initialize GLEW\n");
	glEnable(GL_DEPTH_TEST);
	//current opengl and glsl versions
	printf("OpenGL Version: %s, GLSL Version: %s\n", glGetString(GL_VERSION), glGetString(GL_SHADING_LANGUAGE_VERSION));
	/*TRIANGLE EXAMPLE*/
	Shader gShader("content/default.vs","content/default.frag");
	GLfloat vertices[] = {
		-0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f, 
		0.5f, 0.5f, -0.5f, 
		0.5f, 0.5f, -0.5f, 
		-0.5f, 0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,

		-0.5f, -0.5f, 0.5f,
		0.5f, -0.5f, 0.5f,
		0.5f, 0.5f, 0.5f, 
		0.5f, 0.5f, 0.5f, 
		-0.5f, 0.5f, 0.5f, 
		-0.5f, -0.5f, 0.5f,

		-0.5f, 0.5f, 0.5f, 
		-0.5f, 0.5f, -0.5f, 
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, -0.5f,
		-0.5f, -0.5f, 0.5f,
		-0.5f, 0.5f, 0.5f,

		0.5f, 0.5f, 0.5f, 
		0.5f, 0.5f, -0.5f, 
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, -0.5f,
		0.5f, -0.5f, 0.5f,
		0.5f, 0.5f, 0.5f,

		-0.5f, -0.5f, -0.5f, 
		0.5f, -0.5f, -0.5f, 
		0.5f, -0.5f, 0.5f, 
		0.5f, -0.5f, 0.5f,
		-0.5f, -0.5f, 0.5f,
		-0.5f, -0.5f, -0.5f, 

		-0.5f, 0.5f, -0.5f, 
		0.5f, 0.5f, -0.5f, 
		0.5f, 0.5f, 0.5f, 
		0.5f, 0.5f, 0.5f, 
		-0.5f, 0.5f, 0.5f,
		-0.5f, 0.5f, -0.5f
	};
	GLuint bufferobj, vertexobj;
	glGenVertexArrays(1, &vertexobj);
	glGenBuffers(1, &bufferobj);

	glBindVertexArray(vertexobj);
	//object buffer
	glBindBuffer(GL_ARRAY_BUFFER, bufferobj);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	//position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,3*sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	//colors attri

	glBindVertexArray(0);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	while (true)
	{
		while (SDL_PollEvent(&windowEvent))
		{
			if (windowEvent.type == SDL_QUIT) break;
			keyHandler.handleKeyboardEvent(windowEvent);//report the peripheral event
			keyHandler.thiscall++;
			//do if sdl_pollevent for mouse events ONLY
		}

		
		if (keyHandler.isPressed(SDL_SCANCODE_W))Camera.hshiftCamera(FORWARD, Camera.deltaTime);
		if (keyHandler.isPressed(SDL_SCANCODE_S))Camera.hshiftCamera(BACKWARD, Camera.deltaTime);
		if (keyHandler.isPressed(SDL_SCANCODE_A))Camera.hshiftCamera(LEFT, Camera.deltaTime);
		if (keyHandler.isPressed(SDL_SCANCODE_D))Camera.hshiftCamera(RIGHT, Camera.deltaTime);		
		Camera.dshiftCamera(keyHandler.mPosX, keyHandler.mPosY);

		//------------------------------------------------------------------------------------------//

		GLfloat currentFrame = SDL_GetTicks();
		Camera.deltaTime = currentFrame - Camera.lastFrame;
		Camera.lastFrame = currentFrame;

		glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		gShader.Use();

		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		model = glm::rotate(model, (float)SDL_GetTicks()*0.1f, glm::vec3(0.5f, 1.0f, 0.0f));
		view = Camera.getViewMatrix();
		/*Uncomment to see if the object is being rendered using the default view*/
		//view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		projection = glm::perspective(45.0f, (float)800/600, 0.1f, 1000.0f);

		GLint modelLoc = glGetUniformLocation(gShader.theProgram, "model");
		GLint viewLoc = glGetUniformLocation(gShader.theProgram, "view");
		GLint projLoc = glGetUniformLocation(gShader.theProgram, "projection");

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		glBindVertexArray(vertexobj);
		glDrawArrays(GL_TRIANGLES, 0, 36);
		glBindVertexArray(0);
		//swap buffers
		SDL_GL_SwapWindow(window);



	}
	SDL_GL_DeleteContext(context);
	SDL_Quit();
	return 0;
}