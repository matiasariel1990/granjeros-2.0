/*
 * validaciones.h
 *
 *  Created on: 25/03/2018
 *      Author: algo2
 */

#ifndef VALIDACIONES_H_
#define VALIDACIONES_H_

class Errores;

class Validaciones{

	public:
		static bool validarCompra(Jugador* jugadorPtr, int costo);
		static bool sePuedeSembrar( int* fila, int* columna, Jugador* jugadorPtr);
		static bool tieneSemillas(char tipoCultivo, Jugador* jugadorPtr);
		static bool parcelaDisponible(int* fila, int* columna, Jugador* jugadorPtr);
		static bool parcelaValida(int* fila, int* columna);
		static bool tieneAgua(Jugador* jugadorPtr);
		static bool puedeCosechar(int* fila, int* columna, Jugador* jugadorPtr);
};


#endif /* VALIDACIONES_H_ */
