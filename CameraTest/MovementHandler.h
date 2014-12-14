#pragma once

#include <SDL.h>
#include <SDL_opengl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class MovementHandler{
public:
	void ProcessData(SDL_Scancode scancode){
		if (scancode = SDL_SCANCODE_W)
			camera.hshiftCamera(FORWARD);
	}

	string CheckKeyControl(){

	}
};