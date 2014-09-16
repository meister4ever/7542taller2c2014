#include <iostream>
#include <string>
#include "../Constantes.h"
#include "Pantalla.h"

Pantalla::Pantalla(int altoPx, int anchoPx, int alto, int ancho, const char* dirImg) {
	this->altoPx = altoPx;
	this->anchoPx = anchoPx;
	this->alto = alto;
	this->ancho = ancho;
	this->dirImg = dirImg;
	this->ventana = nullptr;
	this->renderer = nullptr;
}
/**
 * Se inicia SDL y se crea la pantalla principal.
 */
void Pantalla::inicializar() throw (SDL_Excepcion){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		loguer->loguear("No se pudo iniciar SDL",Log::LOG_ERR);
		const char* msg = ((std::string)"Error iniciando SDL: ").append(SDL_GetError()).c_str();
		throw new SDL_Excepcion(msg);
	}
	ventana = SDL_CreateWindow("SnowBross", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, anchoPx, altoPx, SDL_WINDOW_SHOWN);
	if (ventana == nullptr){
		loguer->loguear("No se pudo crear la ventana principal", Log::LOG_ERR);
		const char* msg = ((std::string)"Error creando ventana principal: ").append(SDL_GetError()).c_str();
		throw new SDL_Excepcion(msg);
	}
	renderer =  SDL_CreateRenderer(ventana, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == nullptr){
		loguer->loguear("No se pudo crear el renderer", Log::LOG_ERR);
		const char* msg = ((std::string)"Error creando el renderer: ").append(SDL_GetError()).c_str();
		throw new SDL_Excepcion(msg);
	}
}

void Pantalla::agregarObjeto(ObjetoMapaVista * o){

}


void Pantalla::update(){
	//Limpio la pantalla
	SDL_RenderClear(renderer);

	//Se carga el fondo de pantalla
	SDL_Texture* fondo = IMG_LoadTexture(renderer, dirImg);
	if (fondo == nullptr)
		loguer->loguear("No se encontr� imagen de fondo", Log::LOG_WAR);
	SDL_RenderCopy(renderer, fondo, NULL, NULL);
	SDL_DestroyTexture(fondo);
	//Se cargan los objetos
	for(int i = 0; i+1 < objetos->size(); i++ ){
		SDL_Texture* textura = objetos->at(i)->getVista();
		SDL_RenderCopy(renderer, textura, NULL, NULL);
		SDL_DestroyTexture(textura);
	}

	//Se actualiza la pantalla
	SDL_RenderPresent(renderer);
}

Pantalla::~Pantalla() {
	SDL_Quit();
}

