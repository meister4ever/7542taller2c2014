#include "json/json.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <Parser.h>

Parser::Parser() {
	Json::Value raiz;
	Json::Reader reader;
	std::ifstream prueba("prueba.json", std::ifstream::binary);
	bool parseoExitoso = reader.parse(prueba, raiz, false);
	if (!parseoExitoso) {

		std::cout << reader.getFormatedErrorMessages() << "\n";
	}

	std::string escenario;
	Json::Value un_Escenario;
	un_Escenario = raiz["escenario"];

	/* Busca imagen_fondo en el archivo json, si no lo encuentra crea un null
	 por defecto.*/
	std::string imagen_fondo =
			un_Escenario.get("imagen_fondo", "fondo1.png").asString();
	std::cout << imagen_fondo << "\n";

	int alto_px = un_Escenario.get("alto_px", 768).asInt();
	int ancho_px = un_Escenario.get("ancho_px", 1024).asInt();
	int alto_un = un_Escenario.get("alto_un", 100).asInt();
	int ancho_un = un_Escenario.get("ancho_un", 50).asInt();

	int personaje_x = un_Escenario["personaje"].get("x", 100).asInt();
	int personaje_y = un_Escenario["personaje"].get("y", 100).asInt();

	Json::Value objetos;
	objetos = un_Escenario["objetos"];

	//En esta parte parseamos todos los objetos que haya, y creamos los objetos correspondientes
	for (size_t i = 0; i < objetos.size(); i++) {
		std::string tipo = objetos[i].get("tipo", "rect").asString();
		int x = objetos[i].get("x", 5).asInt();
		int y = objetos[i].get("y", 90).asInt();
		int ancho = objetos[i].get("ancho", 2).asInt();
		int alto = objetos[i].get("alto", 1).asInt();
		int lados = objetos[i].get("lados", 2).asInt();
		std::string color = objetos[i].get("color", "#FF0000").asString();
		int rot = objetos[i].get("rot", 0).asInt();
		int masa = objetos[i].get("masa", 1).asInt();
		bool estatico = objetos[i].get("estatico", false).asBool();
		float escala = objetos[i].get("escala", 1).asFloat();
	}
}

Parser::~Parser() {
	// Destructor auto-generado
}
