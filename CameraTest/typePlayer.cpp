#include "typePlayer.h"

GLfloat typePlayer::procHealth(GLfloat currentHP, GLfloat dmgtaken, GLfloat absorptionfactor){
	GLfloat tempnum;
	tempnum = dmgtaken * absorptionfactor;
	return currentHP - tempnum;
};

int typePlayer::procStatus(){
	//handle status effects
};

void typePlayer::updateEntity(glm::vec3 position, GLfloat health, GLfloat status){
	this->p_entPosition = position;
	this->currentHealth = health;
	this->selfStatus = status;
}