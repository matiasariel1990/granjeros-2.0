/*
 * logica.cpp
 *
 *  Created on: 24/03/2018
 *      Author: Matias Figueroa
 */

#include "logica.h"
#include "pantalla.h"
#include "jugador.h"
#include "validaciones.h"
#include <cstdlib>
#include <iostream>

using namespace std;

void Logica::inicio(){
	Pantalla p;
	p.imprimirBienvenida();
	p.imprimirSeparador();
}

int Logica::solicitarCantidadJugadores(){
	Pantalla p;
	int cant = 1;
	do{
		p.solicitarJugadores();
		//ACA TENEMOS UN PROBLEMA!!!!! SI PONES LETRAS ENTRA EN BUCLE
		cin >> cant;
		p.imprimirSeparador();
	}while((int)cant < 0 || (int)cant > 5);
	if((int)cant > 0 && (int)cant < 5){
		return cant;
	}else{

		return 1;
	}
}

void Logica::asignarJugador(Jugador* jugadorPtr, int jugN){
	string nombre;
	Pantalla p;
	p.solicitarNombre(jugN);
	cin >> nombre;
	jugadorPtr->setearNombre(nombre);
}

/* Funcion recursiva, sale cuando el jugador desee salir
o se le acaben los turnos */
void Logica::secuenciaDeJuego(Jugador* jugadorPtr,
		bool* finalizaJuegoPtr, int* turnoComparativoPtr, int pos,
		int cant){
	Pantalla p;

	//Detecta si hay un paso de turno
	if(*turnoComparativoPtr > (jugadorPtr + pos)->obtenerTurno()){
		pos++;
		inicioDeTurno(jugadorPtr + pos);
		if(pos == cant){
			(*turnoComparativoPtr)--;
			pos = 0;
		}
	}

	//Se imprimen las opciones y se espera la respuesta del jugador
	p.imprimirPantallaTurno((jugadorPtr + pos), finalizaJuegoPtr);
	seleccionAccion(jugadorPtr + pos);

	//Analiza si le quedan turnos por jugar y termina el juego en caso de que no
	//solo analiza si es el ultimo jugador
	if(pos == (cant - 1)){
		if((jugadorPtr + pos)->obtenerTurno() == 0){
				*finalizaJuegoPtr = true;
				}
	}


	//Si no esta la orden de finalizar el juego vuelve a la secuencia anterior
	if(!(*finalizaJuegoPtr)){
		Logica::secuenciaDeJuego(jugadorPtr, finalizaJuegoPtr,
				turnoComparativoPtr, pos, cant);
	}
}


void Logica::seleccionAccion(Jugador* jugadorPtr){
	char seleccion;
	cin >> seleccion;
	seleccionMenu(seleccion, jugadorPtr);
}

void Logica::tirarDados(Jugador* jugadorPtr){
	Pantalla p;
	int dado, resultado;
	srand(time(0));
	dado = (rand() % Jugador::maxDado()) + 1;
	resultado = dado * Jugador::multiplicadorDado();
	cout << p.msjTirarDado()
			<< dado
			<< endl
			<< p.msjGalonesGanados()
			<< resultado
			<< endl;
	jugadorPtr->resultadoDados(&resultado);
}

void Logica::inicioDeTurno(Jugador* jugadorPtr){
	tirarDados(jugadorPtr);
}

void Logica::finDeTurno(Jugador* jugadorPtr){
	jugadorPtr->finTurno();
}

void Logica::seleccionMenu(char accion, Jugador* jugadorPtr){
	Pantalla p;
	int fila = 0;
	int columna = 0;
	char tipoCultivo;
	switch(accion){
		case '1':
			/*ACA CODIGO PARA REGAR
			 * jugadorPtr->solicitarUbicacionParcela(&fila, &columna);
			if(Validaciones::tieneAgua(jugadorPtr)){
				if(Validaciones::parcelaValida(&fila, &columna)){
					jugadorPtr->regar(&fila, &columna);
				}
			}*/
			break;
		case '2':
			{
				/*CODIGO PARA COMPRAR TERRENO

				*/

			}
			break;
		case '3':
			/*
			 * CODIGO PARA VENDER TERRENO
			 */
			break;
		case '4':
			{
				/*
				CODIGO PARA SEMBRAR
				*/

			}

			break;
		case '6':
				/*
				 * Cosechar
				 */
			break;
		case '7':
				/*
				 * comprar canti agua
				*/
			break;
		case '8':
						/*
						 * comprar almacen
						*/
			break;
		case '9':
			Logica::finDeTurno(jugadorPtr);
			break;
		case '10':
			p.menuSalir(jugadorPtr);
			jugadorPtr->sacarTurnos();
			break;
		default:
			cout << "Accion invalida";
	}
}


