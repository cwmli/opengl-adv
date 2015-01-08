#include "entity.h"

entity::player::player(){
	/*Autoload the base standing sprite and fixed dimensions*/
	textureManager::getRefbyID("entity", "plrbase.png", ogl_ID, tDepth);
	this->quadWidth = std::get<0>(textureManager::textureid_wh["plrbase.png"]);
	this->quadHeight = std::get<1>(textureManager::textureid_wh["plrbase.png"]);
}