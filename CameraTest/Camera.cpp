#include "Camera.h"

twodcam::twodcam(glm::vec3 camerapos, GLfloat yaw, GLfloat pitch) :cameraDir(0.0f, 0.0f, -1.0f), cameraUp(0.0f, 1.0f, 0.0f), cameraZoom(45.0f){
	this->cameraPos = camerapos;
	this->Yaw = yaw;
	this->Pitch = pitch;
}