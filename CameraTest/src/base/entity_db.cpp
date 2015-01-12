#include "entity_db.h"

#include "../engine/texture_loader.h"

/*--------------------
 *Entity setup methods
 *--------------------*/
void EntityDB::ProcessEntityCall(std::string entityname){
	if (entityname == "Player"){
		EntityDB::Player* plrID = new Player();
	}
}

void EntityDB::get_quad_dimensions(std::string texturename, int* quad_width, int* quad_height){
	*quad_width = std::get<0>(texture_loader::texture_width_height[texturename]);
	*quad_height = std::get<1>(texture_loader::texture_width_height[texturename]);
}

void EntityDB::UpdateQuadData(std::string entityname, glm::vec2 entity_pos, int quad_height, int quad_width){
	//GLuint plrBO, plrVA;
	//int location;

	float world_vertex_pos[] = {
		entity_pos.x, entity_pos.y + quad_height, //tl
		entity_pos.x, entity_pos.y, //bl
		entity_pos.x + quad_width, entity_pos.y, //br
		entity_pos.x + quad_width, entity_pos.y + quad_height, //tr
	};

	int indices[] = {
		0, 1, 4,
		1, 3, 4
	};
	//upload quad data
	plr_vertex_data_[entityname] = world_vertex_pos;
	plr_index_data_[entityname] = indices;

	/*Element buffer should be in graphics handler file*/
	//glGenBuffers(1, &plrVA);
	//glGenBuffers(1, &plrBO);
	//glBindBuffer(GL_VERTEX_ARRAY, plrVA);
	//glBufferData(GL_VERTEX_ARRAY, sizeof(world_vertex_pos), world_vertex_pos, GL_DYNAMIC_DRAW);
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
EntityDB::Player::Player(){
	/*Autoload the base standing sprite and fixed dimensions*/
	texture_loader::GetReferenceByID("entity", "plrbase.png", ogl_ID, texture_depth);
	this->quad_width = std::get<0>(texture_loader::texture_width_height["plrbase.png"]);
	this->quad_height = std::get<1>(texture_loader::texture_width_height["plrbase.png"]);

	this->entity_hp = 100;
	this->entity_mp = 0;
	this->entity_spd = 100;
	this->entity_dmg = 1;
	this->entity_def = 0;
	this->entity_status = STATUS1;
	this->entity_pos = glm::vec2(0,0);
}

/*Called when loading a previous state*/
EntityDB::Player::Player(int HP, int MP, int SPD, int DMG, int DEF, Status status, glm::vec2 pos){
	/*Autoload the base standing sprite and fixed dimensions*/
	texture_loader::GetReferenceByID("entity", "plrbase.png", ogl_ID, texture_depth);
	this->quad_width = std::get<0>(texture_loader::texture_width_height["plrbase.png"]);
	this->quad_height = std::get<1>(texture_loader::texture_width_height["plrbase.png"]);

	this->entity_hp = HP;
	this->entity_mp = MP;
	this->entity_spd = SPD;
	this->entity_dmg = DMG;
	this->entity_def = DEF;
	this->entity_status = STATUS1;
	this->entity_pos = pos;
}

void EntityDB::Player::PlayerUpdate(){

}

