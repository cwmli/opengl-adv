#ifndef PLAYER_ENT_H
#define PLAYER_ENT_H

#include "base_Entity.h"

class player_entity:base_entity{
public:
	player_entity(int, int, int, int, int, int);
private:
	GLuint setTextureData();
	void calcDEFnDMG();
	void checkStatus();
};
#endif