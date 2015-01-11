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
	void load_entity_db();

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
		player();
		player(int, int, int, int, int, int, glm::vec2);//initializer
		void playerUpdate();
	private:
		//special functions
	};
};
#endif
