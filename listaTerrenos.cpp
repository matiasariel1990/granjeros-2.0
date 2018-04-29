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
		crearPrimero(terreno)
	}else{
		this->ultimo = Nodo(terreno);
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

}

Parcela* ListaTerrenos::obtenerTereno(int posicion){

}

void ListaTerrenos::remover(int posicion){

}

bool ListaTerrenos::avanzarCursor(){

}

Parcela* ListaTerrenos::obtenerCursor(){

}

