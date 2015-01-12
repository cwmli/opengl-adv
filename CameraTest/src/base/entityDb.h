#ifndef EntityDB_H
#define EntityDB_H

#include <glew.h>
#include <SOIL.h>
#include <SDL_opengl.h>
#include <dirent.h>
#include <glm/glm.hpp>
#include <map>
#include <vector>

#include "texture_loader.h"
#include "entBase.h"


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
		Player(int, int, int, int, int, Status, glm::vec2);//initializer
		void PlayerUpdate();
	private:
		//special functions
	};
};
#endif
