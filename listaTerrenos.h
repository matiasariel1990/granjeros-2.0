/*
 * listaTerrenos.h
 *
 *  Created on: 27/04/2018
 *      Author: algo2
 */

#ifndef LISTATERRENOS_H_
#define LISTATERRENOS_H_


#include "nodo.h"

class ListaTerrenos{
	private:
		int tamanio;

		Nodo* primero;

		Nodo* cursor;

		Nodo* ultimo;

	public:
		//Constructor lista vacia
		ListaTerrenos(Parcela* terreno);

		void crearPrimero(Parcela* terreno);

		bool estaVacia();

		int contarElementos();

		void agregar(Parcela* terreno);

		void agregar(Parcela* terreno, int posicion);

		Parcela* obtenerTereno(int posicion);

		void remover(int posicion);

		bool avanzarCursor();

		Parcela* obtenerCursor();


};


#endif /* LISTATERRENOS_H_ */
