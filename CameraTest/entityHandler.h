#ifndef ENTITY_HANDLER_H
#define ENTITY_HANDLER_H

#include "textureManager.h"
#include "entity.h"

class entityHandler{
public:
	std::map<std::string, float*> plrVertexData;
	std::map<std::string, int*> plrIndexData;
	//std::map<std::string, entity > tEntityDB;
private:
	enum entityStatus{
		teststatus1,
		teststatus2,
		teststatus3
	};
	void getQuadDimensions(std::string, int*, int*);
	/*Updates quad position based on input from user*/
	void updateQuadData(std::string, glm::vec2&, int&, int&);

	void doAnimation(); 
	void calcDEFnDMG();
	void checkStatus();
};
#endif