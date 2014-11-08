#include "Config.h"
#include "CreadorObjetos.h"
#include "ValidadorObjetos.h"
#include "../Constantes.h"

#include <json/json.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <exception>

Config::Config(std::string nombreArchivo) throw (Config_Excepcion){

	objetosMapa = std::vector<ObjetoMapa*>();
	personajes = std::vector<Personaje*>();

	Json::Value raiz;
	Json::Reader reader(Json::Features::strictMode());

	std::ifstream prueba(nombreArchivo, std::ifstream::binary);
	bool parseoExitoso = reader.parse(prueba, raiz, true);


	if (!parseoExitoso) {
		std::string mensaje = "Fallo el parseo"	+ reader.getFormatedErrorMessages();
		const char * c = mensaje.c_str();
		loguer->loguear(c, Log::LOG_TIPO::LOG_ERR);
		throw Config_Excepcion("No se pudo parsear exitosamente el archivo \n");
	}

	std::string escenario;
	Json::Value un_Escenario;

	// Se asume que todos los archivos json para el juego deben comenzar con la palabra escenario,
	// sino el archivo es inv�lido.
	un_Escenario = raiz["escenario"];

	if (un_Escenario.isNull()) {
		std::string mensajeError = "No hay escenario, fallo el parseo del archivo ";
//		Log::Loguear(mensajeError, nombreArchivo);

		std::cout << mensajeError << "\n";
	} else {

		altoPx = un_Escenario.get("alto_px", 768).asInt();
		anchoPx = un_Escenario.get("ancho_px", 1024).asInt();
		alto_un = un_Escenario.get("alto_un", 100).asInt();
		ancho_un = un_Escenario.get("ancho_un", 50).asInt();

		int personaje_x, personaje_y;

		personaje_x = un_Escenario["personaje"].get("x", 0).asInt();
		personaje_y = un_Escenario["personaje"].get("y", -100).asInt();
		ValidadorObjetos::ValidarPersonaje(&personaje_x, &personaje_y, ancho_un, alto_un);
		personajes.push_back(CreadorObjetos::CrearPersonaje(personaje_x, personaje_y));
		Json::Value objetos;
		objetos = un_Escenario["objetos"];

		//En esta parte parseamos todos los objetos que haya, y creamos los objetos correspondientes
		for (size_t i = 0; i < objetos.size(); i++) {
			std::string tipo = objetos[i].get("tipo", "rectangulo").asString();
			int x, y, diametro, ancho, alto, base, altura, alfa, beta, lados, rotacion, masa;
			bool estatico;
			float escala;

			x = objetos[i].get("x", 5).asInt();
			y = objetos[i].get("y", 90).asInt();
			diametro = objetos[i].get("diametro", 1).asInt();
			ancho = objetos[i].get("ancho", 2).asInt();
			alto = objetos[i].get("alto", 1).asInt();

			base = objetos[i].get("base", 1).asInt();
			altura = objetos[i].get("altura", 1).asInt();
			alfa = objetos[i].get("alfa", 25).asInt();
			beta = objetos[i].get("beta", 1).asInt();

			lados = objetos[i].get("lados", 0).asInt();

			std::string color = objetos[i].get("color", "#FF0000").asString();

			rotacion = objetos[i].get("rot", 0).asInt();
			masa = objetos[i].get("masa", 1).asInt();
			estatico = objetos[i].get("estatico", false).asBool();
			escala = objetos[i].get("escala", 1).asFloat();
			ValidadorObjetos::ValidarBasicos(&tipo, &x, &y, &color, &rotacion, &masa, estatico, ancho_un, alto_un);

			if (tipo == "rectangulo") {
				this->objetosMapa.push_back(CreadorObjetos::CrearRectangulo(x, y, ancho, alto,	rotacion, color, masa, estatico));
			} else if (tipo == "poligono") {
				ValidadorObjetos::ValidarPoligono(&lados, &escala);
				this->objetosMapa.push_back(CreadorObjetos::CrearPoligono(x, y, lados, escala,	rotacion, color, masa, estatico));
			} else if (tipo == "circulo") {
				ValidadorObjetos::ValidarCirculo(&diametro);
				this->objetosMapa.push_back(CreadorObjetos::CrearCirculo(x, y, diametro, rotacion,	color, masa, estatico));
			} else if (tipo == "paralelogramo") {
				ValidadorObjetos::ValidarParalelogramo(&alfa);
				this->objetosMapa.push_back(CreadorObjetos::CrearParalelogramo(x, y, base, altura,	alfa, rotacion, color, masa, estatico));
			} else if (tipo == "trapecio") {
				ValidadorObjetos::ValidarTrapecio(alfa, beta);
				this->objetosMapa.push_back(CreadorObjetos::CrearTrapecio(x, y, base, altura, alfa, beta, rotacion, color, masa, estatico));
			}
		}
	}
}

std::vector<ObjetoMapa*> Config::getObjetos() {
	return objetosMapa;
}

std::vector<Personaje*> Config::getPersonajes() {
	return personajes;
}

int Config::getAltoPx() {
	return altoPx;
}

int Config::getAnchoPx() {
	return anchoPx;
}

int Config::getAlto() {
	return alto_un;
}

int Config::getAncho() {
	return ancho_un;
}

PaqueteACliente Config::crearPaqueteInicial(){
	PaqueteACliente paquete;
	PaqueteInicial p;

	p.alto = alto_un;
	p.ancho = ancho_un;
	p.altoPx = altoPx;
	p.anchoPx = anchoPx;
/*
	Personaje* personaje = personajes.at(0);

	p.personajePrincipal.id = personaje->getID();
	p.personajePrincipal.x = personaje->getPos().getX();
	p.personajePrincipal.y = personaje->getPos().getY();
	p.personajePrincipal.estado = personaje->getEstado();

	paquete.paqueteInicial = p;
	paquete.tipoPaquete = TipoPaquete::CONEXION_INICIAL;
*/
	return paquete;
}

Config::~Config() {
	for (unsigned i = 0; i < objetosMapa.size(); i++){
		delete objetosMapa.at(i);
	}
	for (unsigned i = 0; i < personajes.size(); i++){
		delete personajes.at(i);
	}
}

