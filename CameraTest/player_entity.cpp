#include "player_entity.h"

player_entity::player_entity(int HP = 100, int MP = 0, int SPD = 100, int DMG = 1, int DEF = 0, int STAT = 0){
	//setTextureData();
	this->entityHP = HP;
	this->entityMP = MP;
	this->entitySPD = SPD;
	this->entityStatus = STAT;

	//calcDEFnDMG();
	//checkStatus();
}


