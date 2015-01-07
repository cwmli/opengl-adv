#ifndef ENTITY_H
#define ENTITY_H

#include <glew.h>
#include <SOIL.h>
#include <SDL_opengl.h>
#include <dirent.h>
#include <glm/glm.hpp>
#include <map>
#include <vector>

class entity{
public:
	struct entbase{
		GLuint* texID = &ogl_ID;
		int* texDepth = &tDepth;
		//quad creation purposes
	private:
		GLint quadHeight, quadWidth;
		GLuint ogl_ID;
		int tDepth;
		glm::vec2 entityPOS;
		//basic elements
		int entityHP, entityMP, entitySPD, entityDMG, entityDEF, entityStatus;
		int entityAGR;
	};
	class base_ent:entbase{
		void updatestats();
	}
private:
	class player:entbase{
		player();//initializer
		//special functions
		void 
	};
};
#endif
