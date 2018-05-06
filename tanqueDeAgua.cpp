#include "tanqueDeAgua.h"

TanqueDeAgua::TanqueDeAgua(int capacidad){

	this->capacidadDelTanque = capacidad;
	this->cantidadDeAgua = 0;
}

void TanqueDeAgua::aumentarCapacidad(int aumento){

	this->capacidadDelTanque += aumento;

}

void TanqueDeAgua::llenarTanque(int masAgua){

	/*
	NO VALIDO HAY QUE REVISAR EN QUE INSTANCIA HACERMOS ESTO!!!!

	srand(time(NULL));

	int multiplicador = 1 + rand() % ((6+1) - 1);

	this->cantidadDeAgua += AGUA_POR_TURNO * multiplicador;

	if( this->cantidadDeAgua > this->capacidadDelTanque ){

		this->cantidadDeAgua = this->capacidadDelTanque;
	}*/

	cantidadDeAgua += masAgua;
}

int TanqueDeAgua::obtenerCapacidad(){
	return this->capacidadDelTanque;
}

int TanqueDeAgua::obtenerCantidadAgua(){
	return this->cantidadDeAgua;
}

bool TanqueDeAgua::disminuirAgua(int costoRiego){
	if(costoRiego > cantidadDeAgua){
		return false;
	}else{
		cantidadDeAgua -= costoRiego;
		return true;
	}
}