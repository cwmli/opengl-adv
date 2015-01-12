#include "entity.h"
/*--------------------
 *Entity setup methods
 *--------------------*/
void entity::process_entity_call(std::string entityname){
	if (entityname == "player"){
		entity::player* plrID = new player();
	}
}

void entity::getQuadDimensions(std::string texturename, int* quadWidth, int* quadHeight){
	*quadWidth = std::get<0>(textureManager::textureid_wh[texturename]);
	*quadHeight = std::get<1>(textureManager::textureid_wh[texturename]);
}

void entity::updateQuadData(entity entityname, glm::vec2 entityPOS, int quadHeight, int quadWidth){
	//GLuint plrBO, plrVA;
	//int location;

	float worldvertexposition[] = {
		entityPOS.x, entityPOS.y + quadHeight, //tl
		entityPOS.x, entityPOS.y, //bl
		entityPOS.x + quadWidth, entityPOS.y, //br
		entityPOS.x + quadWidth, entityPOS.y + quadHeight, //tr
	};

	int indices[] = {
		0, 1, 4,
		1, 3, 4
	};
	//upload quad data
	plrVertexData[entityname] = worldvertexposition;
	plrIndexData[entityname] = indices;

	/*Element buffer should be in graphics handler file*/
	//glGenBuffers(1, &plrVA);
	//glGenBuffers(1, &plrBO);
	//glBindBuffer(GL_VERTEX_ARRAY, plrVA);
	//glBufferData(GL_VERTEX_ARRAY, sizeof(worldvertexposition), worldvertexposition, GL_DYNAMIC_DRAW);
	//glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, plrBO);
	//glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_DYNAMIC_DRAW);
	//glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 0, (GLvoid*)0);
	//glEnableVertexAttribArray(location);
	//glBindBuffer(GL_VERTEX_ARRAY, 0);
}
/*--------------------
 *Entity spawn classes
 *--------------------*/
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
	this->entityStatus = teststatus1;
	this->entityPOS = glm::vec2(0,0);
}

/*Called when loading a previous state*/
entity::player::player(int HP, int MP, int SPD, int DMG, int DEF, Status status, glm::vec2 pos){
	/*Autoload the base standing sprite and fixed dimensions*/
	textureManager::getRefbyID("entity", "plrbase.png", ogl_ID, tDepth);
	this->quadWidth = std::get<0>(textureManager::textureid_wh["plrbase.png"]);
	this->quadHeight = std::get<1>(textureManager::textureid_wh["plrbase.png"]);

	this->entityHP = HP;
	this->entityMP = MP;
	this->entitySPD = SPD;
	this->entityDMG = DMG;
	this->entityDEF = DEF;
	this->entityStatus = teststatus1;
	this->entityPOS = pos;
}

void playerUpdate(){

}

