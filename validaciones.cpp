/*
 * validaciones.cpp
 *
 *  Created on: 28/03/2018
 *      Author: algo2
 */

#include "jugador.h"
#include "pantalla.h"
#include "validaciones.h"
#include <iostream>
#include "error.h"


bool Validaciones::validarCompra(Jugador* jugadorPtr, int costo){
	Error e;
	if(jugadorPtr->obtenerCredito() >= costo){
		return true;
	}else{
		cout << e.fondosInsuficientes()
			<< endl;
		return false;
	}
}

bool Validaciones::sePuedeSembrar(int* fila,
		int* columna, Jugador* jugadorPtr){
	if(parcelaDisponible(fila, columna, jugadorPtr)){
		return true;
	}else{
		return false;
	}
}


bool Validaciones::parcelaDisponible(int* fila, int* columna, Jugador* jugadorPtr){
	Error e;
	if(jugadorPtr->terreno[*fila][*columna].estaDisponible()) {
		return true;
	}else{
		cout << e.parcelaOcupada()
			<< endl;
		return false;
	}
}

bool Validaciones::parcelaValida(int* fila, int* columna){
	Error e;
	if((*fila >= Jugador::maxFilas()) || (
			*columna >= Jugador::maxColumnas())){
		cout << e.parcelaInvalida()
			<< endl;
		return false;
	}else{
		return true;
	}
}

bool Validaciones::tieneAgua(Jugador* jugadorPtr){
	Error e;
	if(jugadorPtr->obtenerAguaTurno() > 0 ||
			jugadorPtr->obtenerGalonesDeAgua() > 0){
		return true;
	}else{
		cout << e.sinAgua()
			<< endl;
		return false;
	}
}

bool Validaciones::puedeCosechar(int* filaArg, int* columnaArg, Jugador* jugadorPtr){
	Parcela* parcelaPtr = &jugadorPtr->terreno[*filaArg][*columnaArg];
	Error e;
	if(parcelaPtr->estaOcupada()){
		if(parcelaPtr->estaPodrida()){
			cout << e.parcelaPodrida()
				<< endl;
			return false;
		}else{
			if(parcelaPtr->estaSeca()){
				cout << e.parcelaSeca()
					<< endl;
				return false;
			}else{
				if(parcelaPtr->cultivoParcela.obtenerTiempoCosecha() == 0){
					return true;
				}else{
					cout << e.faltaTiempo()
						<< endl;
					return false;
				}
			}
		}

	}else{
		cout << e.parcelaVacia()
			<< endl;
		return false;
	}

}


