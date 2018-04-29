/*
 * nodo.cpp
 *
 *  Created on: 29/04/2018
 *      Author: algo2
 */
const int NULL = 0;

#include "nodo.h"

Nodo::Nodo(Parcela* terreno){
	//Inicializo todas las parcelas del terreno
	this->posicion = 1;
	this->terreno = terreno;
	this->siguiente = NULL;
	this->anterior = NULL;
}

Parcela* Nodo::obtenerDato(){
	return this->terreno;
}

Nodo* Nodo::obtenerSiguiente(){
	return this->siguiente;
}

Nodo* Nodo::obtenerAnterior(){
	return this->anterior;
}

int Nodo::obtenerPosicion(){
	return this->posicion;
}

void Nodo::setearPosicion(int posicion){
	this->posicion = posicion;
}

void Nodo::cambiarSiguiente(Nodo* nuevoSiguiente){
	this->siguiente = nuevoSiguiente;
}

void Nodo::cambiarAnterior(Nodo* nuevoAnterior){
	this->anterior = nuevoAnterior;
}
