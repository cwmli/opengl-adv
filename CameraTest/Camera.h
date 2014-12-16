#ifndef TWODCAMERA_OBJ
#define TWODCAMERA_OBJ

#include <glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SDL.h>

class twodcam{
public:
	twodcam(glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 2.0f),
		GLfloat yaw = -90.0f, GLfloat pitch = 0.0f);
	void procTWODCAM(SDL_Event);
private:
	//camera attribute
	glm::vec3 cameraPos, cameraDir, cameraRight, cameraUp;
	//euler attribute
	GLfloat Yaw, Pitch, cameraZoom;

	void focusoncenterCamera(GLfloat, GLfloat);
	void zoomCamera();
	glm::mat4 getViewMatrix();
	void updateCamVectors();
};
#endif