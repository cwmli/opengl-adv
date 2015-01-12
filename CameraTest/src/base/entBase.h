#ifndef ENTBASE_H
#define ENTBASE_H

enum Status{
	STATUS1,
	STATUS2,
	STATUS3
};

struct EntityBaseStat{
	//basic elements
	int entity_hp, entity_mp, entity_spd, entity_dmg, entity_def;
	Status entity_status;
	int entity_agr;
	static GLint quad_height, quad_width;
	GLuint* ogl_ID;
	int texture_depth;
	glm::vec2 entity_pos;
};

struct EntityType{
	EntityDB::Player plr;
};
#endif