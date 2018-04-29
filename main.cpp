//============================================================================
// Name        : Granjeros.cpp
// Author      : Ahre-manga2
// Version     : 1.0
// Copyright   :
// Description : Trabajo Practino nº1
//============================================================================

#include "main.h"
#include "pantalla.h"
#include "logica.h"
#include "jugador.h"

int main() {

	//Variable ara terminar el programa
	bool finalizaJuego = false;
	//Variable arrancar secuencia de inicio de turno
	int turnoComparativo;

	int cantJugadores = 0;
	//Bienvenida
	Logica::inicio();
	//Solcita cantidad de jugadores;
	cantJugadores = Logica::solicitarCantidadJugadores();
	//****SOLICITAR DIFICULTAD ACA
	//Reservo una direccion de memoria para los jugadores
	Jugador* jugadoresPtr = new Jugador[cantJugadores];

	for(int i = 0; i < cantJugadores; i++){
		*(jugadoresPtr + i) = Jugador();
		Logica::asignarJugador((jugadoresPtr + i), i);
	}
    //Esto hay que arreglarlo, lo mismo que el contructor de jugadores
    //hay que hacer una asignacion de dificultad y asignar la cant de turnos
	turnoComparativo = 10;
	//(jugadoresPtr->obtenerTurno() + 1);

	Logica::inicioDeTurno(jugadoresPtr);
	Logica::secuenciaDeJuego(jugadoresPtr, &finalizaJuego,
			&turnoComparativo, 0, cantJugadores);

	//Libero memoria, aca hay que ajustar los cambios de memoria
	delete []jugadoresPtr;


	return 0;
}
