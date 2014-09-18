#include "CreadorObjetos.h"
#include "../objetos/ObjetoMapa.h"
#include "../objetos/Pos.h"
#include "../objetos/Rectangulo.h"
#include "../objetos/Circulo.h"

Rectangulo * CreadorObjetos::CrearRectangulo(int x, int y, int ancho, int alto,int rotacion,std::string color,int masa,bool estatico) {
	Pos *posicion = new Pos(x,y);
	Rectangulo * unRectangulo = new Rectangulo(estatico, color, posicion, rotacion, masa, alto, ancho);
	return unRectangulo;
}

Poligono * CreadorObjetos::CrearPoligono(int x, int y, int lados, int escala, int rotacion,std::string color,int masa,bool estatico) {
	Pos *posicion = new Pos(x,y);
	return new Poligono(posicion, lados, escala, rotacion, color, masa, estatico);

}

Circulo * CreadorObjetos::CrearCirculo(int x, int y, int diametro,int rotacion,std::string color,int masa,bool estatico) {
	Pos *posicion = new Pos(x,y);
	return new Circulo(posicion, diametro, rotacion, color, masa, estatico);

}

Paralelogramo * CreadorObjetos::CrearParalelogramo(int x, int y, int base, int ladoaltura, int alfa,int rotacion,std::string color,int masa,bool estatico) {
	Pos *posicion = new Pos(x,y);
	return new Paralelogramo(posicion,base,ladoaltura,alfa,rotacion,color,masa, estatico);
}

Trapecio * CreadorObjetos::CrearTrapecio(int x, int y, int base, int altura, int alfa, int beta,int rotacion,std::string color,int masa,bool estatico) {
	Pos *posicion = new Pos(x,y);
	return new Trapecio(posicion,base,altura,alfa,beta,rotacion,color,masa, estatico);

}

