#include "Paralelogramo.h"
#include <math.h>

Paralelogramo::Paralelogramo(Pos posicion, int base, int ladoaltura, int alfa, int rotacion, std::string color, int masa, bool estatico) {
	this->base = base;
	this->altura = ladoaltura;
	this->alfa = alfa;
	this->initialice(estatico, color, posicion, rotacion, masa);
}

void Paralelogramo::crearContorno() {
	const double PI = 4.0 * atan(1.0);
	if ((this->alfa) < 90) {
		int x1 = -(base + (altura * cos(alfa * PI / 180.0))) / 2;
		int y1 = -altura * sin(alfa * PI / 180.0) / 2;
		int x2 = x1 + base;
		int y2 = y1;
		int x3 = x2 + ((this->altura) * cos(alfa * PI / 180.0));
		int y3 = y2 + ((this->altura) * sin(alfa * PI / 180.0));
		int x4 = x3 - (this->base);
		int y4 = y3;
		Pos posicion1 = Pos(x1, y1);
		Pos posicion2 = Pos(x2, y2);
		Pos posicion3 = Pos(x3, y3);
		Pos posicion4 = Pos(x4, y4);
		vertices.push_back(posicion1);
		vertices.push_back(posicion2);
		vertices.push_back(posicion3);
		vertices.push_back(posicion4);
	} else {
		int beta = 180 - alfa;
		int x1 = - ((base + altura * cos(beta * PI / 180.0)) / 2);
		int y1 = - altura * sin(beta * PI / 180.0) / 2;
		int x2 = x1 + base;
		int y2 = y1;
		int x3 = x2 - ((this->altura) * cos(beta * PI / 180.0));
		int y3 = y2 + ((this->altura) * sin(beta * PI / 180.0));
		int x4 = x3 - (this->base);
		int y4 = y3;
		Pos posicion1 = Pos(x1, y1);
		Pos posicion2 = Pos(x2, y2);
		Pos posicion3 = Pos(x3, y3);
		Pos posicion4 = Pos(x4, y4);
		vertices.push_back(posicion1);
		vertices.push_back(posicion2);
		vertices.push_back(posicion3);
		vertices.push_back(posicion4);
	}
}

void Paralelogramo::calcularArea() {
	const double PI = 4.0 * atan(1.0);
	if ((this->alfa) < 90) {
		area = ((this->base) * (this->altura * sin(alfa * PI / 180)));
	} else {
		int beta = 180 - alfa;
		area = ((this->base) * (this->altura * sin(beta * PI / 180)));
	}
}

Paralelogramo::~Paralelogramo() {
}
