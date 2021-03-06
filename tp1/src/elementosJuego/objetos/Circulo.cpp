#include "Circulo.h"

Circulo::Circulo(Pos posicion, int diametro, int rotacion, std::string color, int masa, bool estatico) {
	this->diametro = diametro;
	this->initialice(estatico, color, posicion, rotacion, masa);
}

/*
 * @return Devuelve un vector con una sola posici�n (p). De esta manera, se puede calcular
 * 			su radio, haciendo | getPos() - p |
 */
void Circulo::crearContorno() {
	int x = diametro / 2;
	int y = 0;
	vertices.push_back(Pos(x, y));
}

void Circulo::calcularArea() {
	const double PI = 4.0 * atan(1.0);
	area = PI * (diametro * diametro) / 4;
}

bool Circulo::esCirculo() {
	return true;
}

Circulo::~Circulo() {
}
