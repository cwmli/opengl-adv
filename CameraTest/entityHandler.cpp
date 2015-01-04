#include "entityHandler.h"
void entityHandler::getQuadDimensions(std::string texturename, int* quadWidth, int* quadHeight){
	*quadWidth = std::get<0>(textureManager::textureid_wh[texturename]);
	*quadHeight = std::get<1>(textureManager::textureid_wh[texturename]);
}

void entityHandler::updateQuadData(std::string texturename, glm::vec2& entityPOS, int& quadHeight, int& quadWidth){
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
	plrVertexData[texturename] = worldvertexposition;
	plrIndexData[texturename] = indices;

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
