/*
 * jugador.cpp
 *
 *  Created on: 24/03/2018
 *      Author: Matias Figueroa
 */

#include <string>
#include "jugador.h"
#include "pantalla.h"
#include "logica.h"
#include "validaciones.h"
#include "parcela.h"

using namespace std;
//Constructor
Jugador::Jugador(){

	setearNombre("");
	setearCredito(CREDITOS_INICIALES);
	turno = TURNOS;
	setearGalonesDeAgua(0);
	setearAguaTurno(0);

}

Jugador &Jugador::setearNombre(string nombreArg){
	nombre = nombreArg;
	return *this;
}

Jugador &Jugador::setearCredito(int creditoArg){
	credito = creditoArg;
	return *this;
}


Jugador &Jugador::setearAguaTurno(int aguaTurnoArg){
	aguaTurno = aguaTurnoArg;
	return *this;
}

Jugador &Jugador::setearGalonesDeAgua(int galonesDeAguaArg){
	galonesDeAgua = galonesDeAguaArg;
	return *this;
}

string Jugador::obtenerNombre(){
	return nombre;
}

int Jugador::obtenerCredito(){
	return credito;
}


int Jugador::obtenerAguaTurno(){
	return aguaTurno;
}

int Jugador::obtenerGalonesDeAgua(){
	return galonesDeAgua;
}

int Jugador::obtenerTurno(){
	return turno;
}

void Jugador::restarCredito(int creditoArg){
	if(credito >= creditoArg){
		credito -= creditoArg;
	}
}

void Jugador::sumarCredito(int creditoArg){
	credito += creditoArg;
}



void Jugador::descontarUnidadAgua(){
	if(obtenerAguaTurno() > 0){
		aguaTurno--;
	}else{
		if(obtenerGalonesDeAgua() > 0){
			galonesDeAgua--;
		}
	}
}

void Jugador::ahorrarAgua(){
	int sumaGalones;
	sumaGalones = obtenerGalonesDeAgua() + obtenerAguaTurno();
	if(sumaGalones > MAX_GALONES){
		setearGalonesDeAgua(MAX_GALONES);
	}else{
		setearGalonesDeAgua(sumaGalones);
	}
}

void Jugador::restarTurno(){
	turno--;
}

void Jugador::finTurno(){
	restarTurno();
	ahorrarAgua();
	//AGREGAR UNA SECUENCIA QUE RECORRA TODOS LOS TERRENOS
	for(int filas = 0; filas < (MAX_FILAS_TERRENO); filas++){
		for(int columnas = 0; columnas < (MAX_COLUMNAS_TERRENO); columnas++){
			//Convertir esto en un puntero y recorrer todos los punteros del jugador
			terreno[filas][columnas].pasoDeTurno();
		}
	}
	setearAguaTurno(0);
}

void Jugador::sacarTurnos(){
	turno = 0;
}

void Jugador::resultadoDados(int* dadosArg){
	aguaTurno = *dadosArg;
}

void Jugador::sembrar(Cultivo* cultivo, int* fila,
		int* columna, Parcela* terreno[MAXFIL][MAXCOL]){
	int tipo = 0;
	Parcela* parcelaPtr = terreno[*fila][*columna];
	tipo = (int)cultivo->obtenerTipo() - 65;
	parcelaPtr->cultivoParcela.cambiarCultivo(cultivo);
	parcelaPtr->ocuparParcela();
	parcelaPtr->bloquearParcela();
}

void Jugador::cosechar(int* filaArg, int* columnaArg){
	Parcela* parcelaPtr = &terreno[*filaArg][*columnaArg];
	int ganancias = 0;
	ganancias =
			parcelaPtr->cultivoParcela.obtenerRentabilidad();
	sumarCredito(ganancias);
	parcelaPtr->liberarParcela();

}

void Jugador::comprar(int tipoArg, int cantidadArg, int costoArg){
	restarCredito(costoArg);
}



void Jugador::regar(int *fila, int *columna){
	terreno[*fila][*columna].regarParcela();
	descontarUnidadAgua();
}

//Valida la ubicacion elegida y asigna los valores
void Jugador::solicitarUbicacionParcela(int* filaArg, int* columnaArg){
	Pantalla p;
	*filaArg = p.solicitarFilaParcela();
	*columnaArg = p.solicitarColumnaParcela();
}

int Jugador::maxDado(){
	return MAX_DADO;
}

int Jugador::multiplicadorDado(){
	return MULTIPLICADOR_DADO;
}

int Jugador::maxFilas(){
	return MAX_FILAS_TERRENO;
}

int Jugador::maxColumnas(){
	return MAX_COLUMNAS_TERRENO;
}

int Jugador::maxSemillas(){
	return MAX_TIPO_DE_SEMILLA;
}








