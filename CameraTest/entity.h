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

class entity{
	std::map<entity, float*> plrVertexData;
	std::map<entity, int*> plrIndexData;

	void process_entity_call(std::string);

	enum Status{
		teststatus1,
		teststatus2,
		teststatus3
	};

	void getQuadDimensions(std::string, int*, int*);
	/*Updates quad position based on input from user*/
	void updateQuadData(entity, glm::vec2, int, int);

	void calcDEFnDMG();
	void checkStatus();


	struct entbase{		
		//basic elements
		int entityHP, entityMP, entitySPD, entityDMG, entityDEF;
		Status entityStatus;
		int entityAGR;
		static GLint quadHeight, quadWidth;
		GLuint* ogl_ID;
		int tDepth;
		glm::vec2 entityPOS;
	};

class player:entbase{
	public:
		player();
		player(int, int, int, int, int, Status, glm::vec2);//initializer
		void playerUpdate();
	private:
		//special functions
	};
struct entity_types{
	entity::player plr;
};
std::map<std::string, entity_types> Entities;
};
#endif
