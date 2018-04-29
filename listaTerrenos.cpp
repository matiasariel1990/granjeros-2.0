/*
 * listaTerrenos.cpp
 *
 *  Created on: 29/04/2018
 *      Author: algo2
 */

#include "listaTerrenos.h"

ListaTerrenos::ListaTerrenos(Parcela* terreno){
	crearPrimero(terreno);
}

void ListaTerrenos::crearPrimero(Parcela* terreno){
	this->tamanio = 1;
	this->primero = Nodo(terreno);
	this->primero->cambiarSiguiente(0);
	this->primero->cambiarAnterior(0);
	this->primero->setearPosicion(1);
	this->cursor = this->primero;
	this->ultimo = this->primero;
}
bool ListaTerrenos::estaVacia(){
	if(!tamanio == 0){
		return false;
	}
}

int ListaTerrenos::contarElementos(){
	return this->tamanio;
}

void ListaTerrenos::agregar(Parcela* terreno){
	if(estaVacia()){
		crearPrimero(terreno);
	}else{
		Nodo nuevo = Nodo(terreno);
		this->ultimo = &nuevo;
		ultimo->cambiarAnterior(cursor);
		ultimo->cambiarSiguiente(primero);
		cursor->cambiarSiguiente(ultimo);
		primero->cambiarAnterior(ultimo);
		tamanio++;
		ultimo->setearPosicion(tamanio);
		cursor = ultimo;
	}
}

void ListaTerrenos::agregar(Parcela* terreno, int posicion){
	//no se si lo vamos a usar
}

Parcela* ListaTerrenos::obtenerTereno(int posicion){
	if(posicion > tamanio){
		return NULL;
	}
	modificarCursor(posicion);
	Parcela* terreno = cursor->obtenerDato();
	cursor = ultimo;
	return terreno;
}

void ListaTerrenos::modificarCursor(int posicion){
	while(!(cursor->obtenerPosicion() == posicion)){
		avanzarCursor();
	}
}

void ListaTerrenos::remover(int posicion){
	modificarCursor(posicion);
	cursor->obtenerAnterior()->cambiarSiguiente(cursor->obtenerSiguiente());
	cursor->obtenerSiguiente()->cambiarSiguiente(cursor->obtenerAnterior());
	tamanio--;
	cursor->~Nodo();
	for(int i = posicion; i < tamanio; i++){
		avanzarCursor();
		cursor->setearPosicion(i);
	}
}

bool ListaTerrenos::avanzarCursor(){
	cursor = cursor->obtenerSiguiente();
	if(tamanio > 1){
		return true;
	}else{
		return false;
	}
}

Parcela* ListaTerrenos::obtenerCursor(){

}

ListaTerrenos::~ListaTerrenos(){
	while(tamanio != 0){
		remover(cursor->obtenerPosicion());

	}
}
