#ifndef CAMERA_OBJ
#define CAMERA_OBJ

#include <glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SDL.h>

enum CameraMovements{
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT
};

class objCamera{
public:
	//camera attribute
	glm::vec3 cameraPos, cameraDir, cameraRight, cameraUp;
	//euler attribute
	GLfloat Yaw, Pitch;
	//camera option attribute
	GLfloat cameraSpeed, cameraSensitivity, cameraZoom;
	//move normalize
	GLfloat deltaTime = 0.0f, lastFrame = 0.0f;
	
	objCamera(glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 2.0f), 
		GLfloat yaw = -90.0f, GLfloat pitch = 0.0f);
	void hshiftCamera(CameraMovements, GLfloat);
	void dzoomCamera();
	void dshiftCamera(double, double);
	glm::mat4 getViewMatrix();
private:
	void updateCamera();
};



#endif