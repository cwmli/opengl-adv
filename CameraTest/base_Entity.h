#ifndef BASE_ENT_H
#define BASE_ENT_H

#include "entityHandler.h"

struct base_entity{
	GLuint* texID = &ogl_ID;
	int* texDepth = &tDepth;

	//quad creation purposes
	GLint quadHeight, quadWidth;
	GLuint ogl_ID;
	int tDepth;
	glm::vec2 entityPOS;
	//basic elements
	int entityHP, entityMP, entitySPD, entityDMG, entityDEF, entityStatus;
	int entityAGR;
}; 
#endif