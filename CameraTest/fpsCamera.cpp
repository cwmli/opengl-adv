#include "fpsCamera.h"
//default constructor
objCamera::objCamera(glm::vec3 camerapos, GLfloat yaw, GLfloat pitch):cameraDir(0.0f,0.0f,-1.0f),cameraUp(0.0f,1.0f,0.0f),cameraZoom(45.0f),cameraSpeed(0.05f){
	this->cameraPos = camerapos;
	this->Yaw = yaw;
	this->Pitch = pitch;
}

//process horizontal camera movement
void objCamera::hshiftCamera(CameraMovements keyvalue, GLfloat deltaTime){
	this->cameraSpeed = 0.005f * deltaTime;

	if (keyvalue == FORWARD)
		this->cameraPos += cameraDir*cameraSpeed;
	if (keyvalue == BACKWARD)
		this->cameraPos -= cameraDir*cameraSpeed;
	if (keyvalue == LEFT)
		this->cameraPos -= cameraRight*cameraSpeed;
	if (keyvalue == RIGHT)
		this->cameraPos += cameraRight*cameraSpeed;
}

void objCamera::dshiftCamera(double mouseX,double mouseY){
	GLfloat xoffset = mouseX;
	GLfloat yoffset = mouseY;

	this->cameraSensitivity = 0.25f;
	yoffset *= -cameraSensitivity;
	xoffset *= cameraSensitivity;

	this->Yaw += xoffset;
	this->Pitch += yoffset;

	if (Pitch > 89.0f)
		this->Pitch = 89.0f;
	if (Pitch < -89.0f)
		this->Pitch = -89.0f;

	updateCamera();
}

void objCamera::dzoomCamera(){}

glm::mat4 objCamera::getViewMatrix(){
	return (glm::lookAt(this->cameraPos, this->cameraPos + this->cameraDir, this->cameraUp));
}


/*Get camera direction after mouse input using trigonometry and
recalculate camera Up and Right vectors.*/
void objCamera::updateCamera(){
	glm::vec3 tempDir;

	tempDir.x = cos(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	tempDir.y = sin(glm::radians(Pitch));
	tempDir.z = sin(glm::radians(Yaw)) * cos(glm::radians(Pitch));
	this->cameraDir = glm::normalize(tempDir);

	this->cameraRight = glm::normalize(glm::cross(cameraDir, cameraUp));
	//this->cameraUp = glm::normalize(glm::cross(cameraDir, cameraRight));
}
