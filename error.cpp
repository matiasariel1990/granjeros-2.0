/*
 * error.cpp
 *
 *  Created on: 04/04/2018
 *      Author: Matias Figueroa
 */
#include "error.h"

using namespace std;

string Error::accionInvalida(){
	return ER_ACCION_INVALIDA;
}

string Error::fondosInsuficientes(){
	return ER_FONDOS_INSUFICIENTES;
}

string Error::parcelaOcupada(){
	return PARCELA_OCUPADA;
}

string Error::sinSemillas(){
	return SIN_SEMILLAS;
}

string Error::sinAgua(){
	return SIN_AGUA;
}

string Error::parcelaInvalida(){
	return PARCELA_INVALIDA;
}

string Error::cultivoInvalido(){
	return ER_CULTIVOS;
}

string Error::parcelaPodrida(){
	return ER_PARCELA_PODRIDA;
}

string Error::parcelaSeca(){
	return ER_PARCELA_SECA;
}
string Error::parcelaVacia(){
	return ER_PARCELA_VACIA;
}

string Error::faltaTiempo(){
	return ER_FALTA_TIEMPO;
}


