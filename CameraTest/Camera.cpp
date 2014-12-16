#include "Camera.h"
/*PUBLIC FUNCTIONS*/
//default constructor
twodcam::twodcam(glm::vec3 camerapos, GLfloat yaw, GLfloat pitch) :cameraDir(0.0f, 0.0f, -1.0f), cameraUp(0.0f, 1.0f, 0.0f), cameraZoom(45.0f){
	this->cameraPos = camerapos;
	this->Yaw = yaw;
	this->Pitch = pitch;
};

void twodcam::procTWODCAM(SDL_Event event){
	//call private functions
};
/*PRIVATE FUNCTIONS*/
void twodcam::zoomCamera(){

};

void twodcam::focusoncenterCamera(GLfloat entx, GLfloat entz){
	//change GLfloat to playerobject
	GLfloat xoffset, zoffset;
	xoffset = cameraPos.x - entx;
	zoffset = cameraPos.z - entz;

	cameraPos.x += xoffset;
	cameraPos.z += zoffset;
};

glm::mat4 twodcam::getViewMatrix(){
	//keep camera locked on player
	//return (glm::lookAt(cameraPos, player, cameraUp));
};

void twodcam::updateCamVectors(){

};