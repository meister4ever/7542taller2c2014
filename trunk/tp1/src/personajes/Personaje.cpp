#include "Personaje.h"

Personaje::Personaje(Pos* posicion) {
	pos = posicion;
	rot = 0;
	linkAMundo = nullptr;
}

// getter y setter de la posicion
void Personaje::setPosicion(Pos* posicion) {
	pos = posicion;
}
Pos* Personaje::getPosicion(){
	return pos;
}

void Personaje::setRotacion(float rotacion){
	rot = rotacion;
}

// devuelve verdadero si esta en esa posicion
bool Personaje::estaEnPos(Pos* posicion) {
	return pos->esIgual(posicion);
}

Personaje::~Personaje() {
	// TODO Auto-generated destructor stub
}

// getter y setter de link a mundo
void Personaje::setLinkAMundo(b2Body* link){
	linkAMundo = link;
}

b2Body* Personaje::getLinkAMundo(){
	return linkAMundo;
}