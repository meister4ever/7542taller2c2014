#ifndef PANTALLA_H_
#define PANTALLA_H_

#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../excepciones/SDL_Excepcion.h"
#include "ObjetoMapaVista.h"

class Pantalla {
private:
	int altoPx;
	int anchoPx;
	int alto;
	int ancho;
	const char* dirImg;
	SDL_Window* ventana;
	SDL_Renderer* renderer;
	std::vector<Vista*>* vistas;
public:
	Pantalla(int altoPx, int anchoPx, int alto, int ancho, const char* dirImg);
	void inicializar() throw (SDL_Excepcion);
	void update();
	void agregarVista(Vista* v);

	int getAlto();
	int getAncho();

	virtual ~Pantalla();
};

#endif /* PANTALLA_H_ */