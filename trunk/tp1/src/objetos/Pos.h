/*
 * Pos.h
 *
 *  Created on: 9/9/2014
 *      Author: pablo_000
 */

#ifndef POS_H_
#define POS_H_

class Pos {
public:
	Pos();
	Pos(const Pos *p);
	// Devuelve verdadero si la posicion es la misma
	bool esIgual(Pos posicion);
	//hay que definir el operador =
	virtual ~Pos();
};

#endif /* POS_H_ */