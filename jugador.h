/*
 * jugador.h
 *
 *  Created on: 24/03/2018
 *      Author: Matias Figueroa
 */

#ifndef JUGADOR_H_
#define JUGADOR_H_

#include <string>
#include "parcela.h"
#include "listaTerrenos.h"
#include "almacen.h"

class Parcela;
class Cultivo;
class Const;

using namespace std;

class Jugador{
	private:
		//Constantes del juego
		static const int MAX_TIPO_DE_SEMILLA = 3;
		static const int MULTIPLICADOR_DADO = 5;
		static const int MAX_DADO = 6;
		static const int MAX_GALONES = 25;
		static const int MAX_FILAS_TERRENO = 5;
		static const int MAX_COLUMNAS_TERRENO = 5;
		static const int CREDITOS_INICIALES = 50;
		static const int TURNOS = 10;

		std::string nombre;
		int credito;
		int turno;
		int aguaTurno;
		int galonesDeAgua;
		Almacen almacen;
		/*
		 	la lista de terrenos va a reemplzar al terrenos simple, va
			ser una lista doblemente enlazada y se eligira primero el terreno
			por su numero y despues la accion
		*/
		ListaTerrenos terrenos;

	public:

		Parcela terreno[MAX_FILAS_TERRENO][MAX_COLUMNAS_TERRENO];


		//Constructor
		Jugador();

		/*
		 * pre: El jugador debe haber sido creado
		 * nombreArg debe ser un string.
		 * post: cambia el nombre del jugador
		 */
		Jugador &setearNombre(std::string nombreArg);

		/*
		* pre: CreditoArg debe ser un numero entero positivo
		* post: cambia el credito del jugador
		*/
		Jugador &setearCredito(int creditoArg);

		/*
		* PRE: El jugador debe haber sido creado, creditoArg
		* debe ser un numero entero positivo. El tipoArg debe
		* ser un numero entre 0 y menor a la cantidad de cultivos
		* diferentes que tenga el juego
		* POST: asigna un string al nombre
		*/
		Jugador &setearCantidadSemillas(int tipoArg, int cantidadArg);

		/*
		* pre: El jugador debe haber sido creado, creditoArg
		* debe ser un numero entero positivo
		* post: asigna un string al nombre
		*/
		Jugador &setearAguaTurno(int aguaTurnoArg);

		/*
		* pre: El jugador debe haber sido creado, creditoArg
		* debe ser un numero entero positivo
		* post: asigna un string al nombre
		*/
		Jugador &setearGalonesDeAgua(int galonesDeAguaArg);
		Jugador &agregarAguaDeposito(int aguaSobranteArg);

		std::string obtenerNombre();
		int obtenerCredito();
		char obtenerTipoSemilla(int tipoArg);
		int obtenerCantidadSemillas(int tipoArg);
		int obtenerAguaTurno();
		int obtenerGalonesDeAgua();
		int obtenerTurno();
		static int maxDado();
		static int multiplicadorDado();
		static int maxFilas();
		static int maxColumnas();
		static int maxSemillas();

		void resultadoDados(int* resultadoArg);
		void restarCredito(int creditoArg);
		void sumarCredito(int creditoArg);
		void restarSemillas(int tipoArg, int cantidadSemillasArg);
		void restarSemillas(int tipoArg);
		void sumarSemillas(int tipoArg, int cantidadSemillasArg);
		void sumarSemillas(int tipoArg);
		void ahorrarAgua();
		void descontarUnidadAgua();
		void restarTurno();
		void finTurno();
		void sacarTurnos();

		void seleccionMenu(char accion, Jugador* jugadorPtr);
		void cosechar(int* filaArg, int* columnaArg);
		void sembrar(Cultivo* cultivo, int* fila, int* columna,
				Parcela* terreno[MAXFIL][MAXCOL]);
		void comprar(int tipoArg, int cantidadArg, int costoArg);
		void regar(int* fila, int* columna);
		void salir();
		void solicitarUbicacionParcela(int* filaArg, int* columnaArg);
};


#endif /* JUGADOR_H_ */
