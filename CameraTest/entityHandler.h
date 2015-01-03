#ifndef ENTITY_HANDLER_H
#define ENTITY_HANDLER_H

#include "textureManager.h"

namespace entityHandler{
	std::map<std::string, float> plrVertexData;
	std::map<std::string, int> plrIndexData;
	void setupQuad(std::string, glm::vec2, int, int);
};
#endif