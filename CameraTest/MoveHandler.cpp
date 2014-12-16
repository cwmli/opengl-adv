#include "MoveHandler.h"

void MoveHandler::handleKeyboardEvent(SDL_Event event){
	SDL_Scancode keydetect = event.key.keysym.scancode;
	{
		switch (event.type){
		case SDL_KEYDOWN:
			keys[keydetect] = true;
			break;
		case SDL_KEYUP:
			keys[keydetect] = false;
			break;
		case SDL_MOUSEMOTION:
			SDL_GetRelativeMouseState(&mPosX, &mPosY);
			printf("Sent out mouse position at: %d, %d :::delay: %f\n", mPosX, mPosY, thiscall - lastcall);
			lastcall = thiscall;
			break;
		case SDL_MOUSEWHEEL:
			//send mousewheel data to 2dcamera to process zoom
			break;
		case SDL_MOUSEBUTTONDOWN:
			break;
		}
	}
}

//check key press
bool MoveHandler::isPressed(SDL_Scancode scancode){
	return (keys[scancode] == true);
}
//check key release
bool MoveHandler::isReleased(SDL_Scancode scancode){
	return(keys[scancode] == true);
}


