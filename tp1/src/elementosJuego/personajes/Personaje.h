#ifndef PERSONAJE_H_
#define PERSONAJE_H_

#include "../ElementosJuego.h"
#include "../Pos.h"
#include <Box2D/Box2D.h>
#include "../objetos/Rectangulo.h"

class Personaje: public ElementosJuego {
public:
	enum E_PERFIL {
		DERECHA, IZQUIERDA
	};
	enum E_ACCION {
		QUIETO, DESPLAZANDO, SALTANDO, CAYENDO, EMPUJANDO
	};
	struct Estado {
		E_PERFIL perfil;
		E_ACCION accion;

		bool operator==(const Estado& e) {
			if (e.perfil == this->perfil && e.accion == this->accion)
				return true;
			return false;
		}
	};

//	std::string estado;

private:
	int ancho;
	int alto;
	Estado estado;
	void crearContorno();
//	Rectangulo *rectanguloPersonaje; //Solo para pruebas

public:
	Personaje(Pos posicion);

	/*
	 * Devuelve verdadero si el objeto no se puede mover
	 */
	bool esEstatico();

	/*
	 * Devuelve verdadero si el objeto es un circulo
	 */
	bool esCirculo();

	/*
	 * Getter para alto y ancho del personaje en unidades reales
	 */
	int getAlto();
	int getAncho();

	float getArea();

	// getter y setter de estado
	void setEstado(E_PERFIL p, E_ACCION a);
	void setEstado(Estado estado);
	Estado getEstado();

	~Personaje();

	/*
	 * Devuelve el rectangulo que representa al personaje
	 */
//	Rectangulo* getRectangulo();
	/*
	 * Getter y setter para el estado
	 */
//	void setEstado(std::string unEstado);
//	std::string getEstado();
};
#endif /* PERSONAJE_H_ */
