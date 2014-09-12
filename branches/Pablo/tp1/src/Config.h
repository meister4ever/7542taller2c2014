/*
 * Config.h
 *
 *  Created on: 6/9/2014
 *      Author: pablo_000
 */

#ifndef CONFIG_H_
#define CONFIG_H_

#include <string>
#include <vector>
#include "objetos/ObjetoMapa.h"
#include "personajes/Personaje.h"
#include "Pantalla.h"

class Config {

private:
	string dirArchivoConfiguracion;
	Pantalla *pantalla;
	vector<Personaje> *personajes;
	vector<ObjetoMapa> *objetos;

public:
	Config(string dirArchivoConfiguracion);
	/**
	 * Se encarga de setear los atributos de la instancia a partir
	 * 	del archivo de configuracion.
	 */
	void reset();
	Pantalla* getPantalla();
	vector<Personaje>* getPersonajes();
	vector<ObjetoMapa>* getObjetos();
	virtual ~Config();
};

#endif /* CONFIG_H_ */
