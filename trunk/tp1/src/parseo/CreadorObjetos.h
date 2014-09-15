#ifndef CREADOROBJETOS_H_
#define CREADOROBJETOS_H_
#include <string>
#include "../objetos/Rectangulo.h"
#include "../objetos/Poligono.h"
#include "../objetos/Circulo.h"
#include "../objetos/Paralelogramo.h"
#include "../objetos/Trapecio.h"

class CreadorObjetos {
public:
	static Rectangulo *CrearRectangulo(int x, int y, int ancho, int alto,int rotacion,std::string color,int masa,bool estatico);
	static Poligono *CrearPoligono(int x, int y, int lados, int escala, int rotacion,std::string color,int masa,bool estatico);
	static Circulo *CrearCirculo(int x, int y, int diametro,int rotacion,std::string color,int masa,bool estatico);
	static Paralelogramo *CrearParalelogramo(int x, int y, int base, int ladoaltura, int alfa,int rotacion,std::string color,int masa,bool estatico);
	static Trapecio *CrearTrapecio(int x, int y, int base, int altura, int alfa, int beta,int rotacion,std::string color,int masa,bool estatico);

	virtual ~CreadorObjetos();
};

#endif /* CREADOROBJETOS_H_ */
