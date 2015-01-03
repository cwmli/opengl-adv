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
#include "shaderInit.h"
#include "MoveHandler.h"
#include "Camera.h"
#include "textureManager.h"
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
	window = SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL | SDL_WINDOW_INPUT_GRABBED);
	if (!window)
		sdlerr("ERROR::Unable to create window\n");
	context = SDL_GL_CreateContext(window);
	//modern glew initialize attempt
	glewExperimental = GL_TRUE;
	if (glewInit() < 0)
		printf("ERROR::Unable to initialize GLEW\n");
	shaderInit gShader;

	while (true)
	{
		while (SDL_PollEvent(&windowEvent))
		{
			if (windowEvent.type == SDL_QUIT) break;
			keyHandler.handleKeyboardEvent(windowEvent);//report the peripheral event
			//do if sdl_pollevent for mouse events ONLY
		}

		//------------------------------------------------------------------------------------------//

		glClearColor(0.7f, 0.7f, 0.7f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		gShader.Use();

		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		model = glm::rotate(model, (float)SDL_GetTicks()*0.1f, glm::vec3(0.5f, 1.0f, 0.0f));
		//view = Camera.getViewMatrix();
		/*Uncomment to see if the object is being rendered using the default view*/
		//view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
		projection = glm::ortho(0, 800, 600, 0);

		GLint modelLoc = glGetUniformLocation(gShader.theProgram, "model");
		GLint viewLoc = glGetUniformLocation(gShader.theProgram, "view");
		GLint projLoc = glGetUniformLocation(gShader.theProgram, "projection");

		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));

		//swap buffers
		SDL_GL_SwapWindow(window);
	}
	SDL_GL_DeleteContext(context);
	SDL_Quit();
	return 0;
}