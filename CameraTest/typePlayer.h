#ifndef TYPEPLAYER_H
#define TYPEPLAYER_H

#include <glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <SDL.h>

class typePlayer{
public:
	glm::vec3 p_entPosition;
	GLfloat
		//base stats
		maxHealth, currentHealth, regSpeed, runSpeed,
		//other stat
		aggroRadius, selfStatus;
	void updateEntity(glm::vec3, GLfloat, GLfloat);
private:
	virtual GLfloat procHealth(GLfloat, GLfloat, GLfloat);
	virtual int procStatus();
};
#endif