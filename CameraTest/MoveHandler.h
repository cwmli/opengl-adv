#ifndef MoveHandler_H
#define MoveHandler_H

#include <SDL.h>
#include <SDL_opengl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;

class MoveHandler{
public:
	const Uint8 *keystateCurrent;
	int mPosX, mPosY;
	bool keys[256]; //keybuffer
	void handleKeyboardEvent(SDL_Event);
	//check key press
	bool isPressed(SDL_Scancode);
	//check key release
	bool isReleased(SDL_Scancode);
};
#endif