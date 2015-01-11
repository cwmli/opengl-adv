#include "entity.h"

void entity::load_entity_db(){
	textureManager::genGLTexture("entities","player");
}

/*Called upon new game*/
entity::player::player(){
	/*Autoload the base standing sprite and fixed dimensions*/
	textureManager::getRefbyID("entity", "plrbase.png", ogl_ID, tDepth);
	this->quadWidth = std::get<0>(textureManager::textureid_wh["plrbase.png"]);
	this->quadHeight = std::get<1>(textureManager::textureid_wh["plrbase.png"]);

	this->entityHP = 100;
	this->entityMP = 0;
	this->entitySPD = 100;
	this->entityDMG = 1;
	this->entityDEF = 0;
	this->entityStatus = 0;
	this->entityPOS = glm::vec2(0,0);
}

/*Called when loading a previous state*/
entity::player::player(int HP, int MP, int SPD, int DMG, int DEF, int Status, glm::vec2 pos){
	/*Autoload the base standing sprite and fixed dimensions*/
	textureManager::getRefbyID("entity", "plrbase.png", ogl_ID, tDepth);
	this->quadWidth = std::get<0>(textureManager::textureid_wh["plrbase.png"]);
	this->quadHeight = std::get<1>(textureManager::textureid_wh["plrbase.png"]);

	this->entityHP = HP;
	this->entityMP = MP;
	this->entitySPD = SPD;
	this->entityDMG = DMG;
	this->entityDEF = DEF;
	this->entityStatus = Status;
	this->entityPOS = pos;
}

void playerUpdate(){
	entityha
}

