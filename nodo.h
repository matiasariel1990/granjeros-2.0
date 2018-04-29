/*
 * nodo.h
 *
 *  Created on: 27/04/2018
 *      Author: algo2
 */

#ifndef NODO_H_
#define NODO_H_

#ifndef NULL
#define NULL 0
#endif
#include "parcela.h";

int const MAXCOL = 5;
int const MAXFIL = 5;

class Nodo{

	private:

		Parcela* terreno;

		Nodo* siguiente;

		Nodo* anterior;

		int posicion;


	public:

		//
		Nodo(Parcela* terreno);

		/*
		 *
		 */

		Parcela* obtenerDato();
		Nodo* obtenerSiguiente();
		Nodo* obtenerAnterior();
		void cambiarSiguiente(Nodo* nuevoSiguiente);
		void cambiarAnterior(Nodo* nuevoSiguiente);
		int obtenerPosicion();
		void setearPosicion(int posicion);

};


#endif /* NODO_H_ */
