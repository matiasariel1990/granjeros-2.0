/*
 * logica.h
 *
 *  Created on: 24/03/2018
 *      Author: Matias Figueroa
 */

#ifndef LOGICA_H_
#define LOGICA_H_

class Jugador;

class Logica{
	public:

		/*
		 * post: Da la bienvenida
		 */
		static void inicio();

		/*
		* post: Asigna un nombre a cada jugador.
		*/
		static int solicitarCantidadJugadores();

		/*
		 * post: Asigna un nombre a cada jugador.
		 */
		static void asignarJugador(Jugador* jugadorPtr, int jugN);

		/*
		 * post: Logica del juego
		 */
		static void secuenciaDeJuego(Jugador* jugadorPtr,
				bool* finalizaJuegoPtr, int* turnoComparativoPtr,
				int pos, int cant);

		/*
		 * post: Asigna la seleccion de la accion a realizar
		 */
		static void seleccionAccion(Jugador* jugadorPtr);

		/*
		 * post: Actua segun la seleccion del jugador
		 */
		static void seleccionMenu(char accion, Jugador* jugadorPtr);

		/*
		 * post: Segun el azar le agrega los galones de agua al jugador.
		 */
		static void tirarDados(Jugador* jugadorPtr);

		/*
		 * post: Realiza la secuencia del inicio de turno
		 */
		static void inicioDeTurno(Jugador* jugadorPtr);

		/*
		 * post: Realiza la secuencia de fin de turno.
		 */
		static void finDeTurno(Jugador* jugadorPtr);

		/*
		 * post: Realiza la secuenca del fin del juego.
		 */
		static void finDelJuego();
};


#endif /* LOGICA_H_ */
