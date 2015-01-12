#ifndef ENTITYDB_H
#define ENTITYDB_H

#include <map>
#include <glm/glm.hpp>

#include "entity_base.h"

class EntityDB{
public:
	std::map<std::string, float*> plr_vertex_data_;
	std::map<std::string, int*> plr_index_data_;
	std::map<std::string, EntityType> entity_map_;

	void ProcessEntityCall(std::string);
	void get_quad_dimensions(std::string, int*, int*);
	/*Updates quad position based on input from user*/
	void UpdateQuadData(std::string, glm::vec2, int, int);

class Player:EntityBaseStat{
	public:
		Player();
		/*initializer for loading SAV*/
		Player(int, int, int, int, int, Status, glm::vec2);
		void PlayerUpdate();
	private:
		/*special functions related to player class*/
	};
};
#endif
