#ifndef ENTITY_H
#define ENTITY_H

#include <glew.h>
#include <SOIL.h>
#include <SDL_opengl.h>
#include <dirent.h>
#include <glm/glm.hpp>
#include <map>
#include <vector>

#include "textureManager.h"

namespace entity{
	void process_entity_call();

	struct entbase{		
		//basic elements
		int entityHP, entityMP, entitySPD, entityDMG, entityDEF, entityStatus;
		int entityAGR;
		static GLint quadHeight, quadWidth;
		GLuint* ogl_ID;
		int tDepth;
		glm::vec2 entityPOS;
	};

class player:entbase{
	public:
		player();//initializer
		void playerUpdate();
	private:
		//special functions
	};
};
#endif
