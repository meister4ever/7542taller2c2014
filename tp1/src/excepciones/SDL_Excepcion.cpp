#include "SDL_Excepcion.h"

SDL_Excepcion::SDL_Excepcion() {
	msg = nullptr;
}

SDL_Excepcion::SDL_Excepcion(const char* desc) {
	msg = desc;
}

const char* SDL_Excepcion::what(){
	return msg;
}

SDL_Excepcion::~SDL_Excepcion() {
	// TODO Auto-generated destructor stub
}

