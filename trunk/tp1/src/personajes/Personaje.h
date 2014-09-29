#ifndef PERSONAJE_H_
#define PERSONAJE_H_

#include "../objetos/Pos.h"
#include <Box2D/Box2D.h>
#include "../objetos/Rectangulo.h"

class Personaje {
public:
	enum E_PERFIL {DERECHA, IZQUIERDA};
	enum E_MOVIMIENTO {QUIETO, MOVIMIENTO, SALTANDO_SUBIENDO, SALTANDO_BAJANDO};
	enum E_ACCION {NINGUNA, EMPUJANDO};

private:
	int ancho;
	int alto;
	Pos* pos;
	float rot;
	b2Body* linkAMundo;
	E_PERFIL estadoPerfil;
	E_MOVIMIENTO estadoMovimiento;
	E_ACCION estadoAccion;

	Rectangulo *rectanguloPersonaje; //Solo para pruebas

public:
	Personaje(Pos* posicion);

	// getters de dimensiones
	int getAlto();
	int getAncho();

	// getter y setter de la posicion
	void setPosicion(Pos* posicion);
	Pos* getPosicion();

	// devuelve verdadero si esta en esa posicion
	bool estaEnPos(Pos* posicion);

	std::vector<Pos*>* getContorno();
	Rectangulo* getRectangulo();

	// getter y setter de estado
	void setEstado(E_PERFIL p, E_MOVIMIENTO m, E_ACCION a);
	void setEstado(E_PERFIL p, E_MOVIMIENTO m);
	E_PERFIL getPerfil();
	E_MOVIMIENTO getMovimiento();
	E_ACCION getAccion();

	// getter y setter de link a mundo
	void setLinkAMundo(b2Body* link);
	b2Body* getLinkAMundo();

	virtual ~Personaje();
};

#endif /* PERSONAJE_H_ */
