*
 * pantalla.h
 *
 *  Created on: 24/03/2018
 *      Author: ahre-manga2
 */

#ifndef INTERFACES_PANTALLA_H_
#define INTERFACES_PANTALLA_H_

#include <string>
#include "jugador.h"

class Jugador;
class Parcela;


//Mensajes varios
const std::string TITULO = "Bienvenido a Granjeros V 1.0";
const std::string SOLICITAR_NOMBRE = "Ingrese el nombre del jugador ";
const std::string SOLICITAR_COLUMNA = "Ingese numero de columna";
const std::string SOLICITAR_FILA = "Ingese numero de fila";
const std::string SOLICITAR_ACCION = "Seleccione una accion:";
const std::string OP1 = "1.Regar //";
const std::string OP2 = "2.Comprar //";
const std::string OP3 = "3.Cosechar //";
const std::string OP4 = "4.Sembrar //";
const std::string OP5 = "5.Pasar turno //";
const std::string OP9 = "9.Salir //";
const std::string SEPARADOR = "------------------------";
const std::string CONFIRME_SALIDA = "Esta seguro que quiere salir? (s/n)";
const std::string SOLICITAR_TIPO_CULTIVO = "Ingrese un tipo de cultivo:: A B o C.";
const std::string SOLICITAR_CANTIDAD = "Cuantas unidades quiere comprar?";
const std::string MENSAJE_TIRAR_DADO = "Se tiro el dado----> Su numero es: ";
const std::string MENSAJE_GALONES_GANADOS =
	"Por ello ha recibido los siguientes galones de agua:";
std::string DESPEDIDA = "El juego a finalizado, su credito final es: ";
std::string CANTIDAD_JUGADORES = "Ingrese la cantidad de jugadores";


class Pantalla{

	public:
		void imprimirBienvenida();
		void imprimirPantallaTurno(Jugador* jugadorPtr, bool* estadoJuegoPtr);
		void imprimirMenu();
		void solicitarNombre(int jugN);
		void imprimirEstadoDelJugador(Jugador* jugadorPtr);
		void solicitarJugadores();
		void imprimirSeparador();
		void imprimirTerreno(Jugador* jugadorPtr);
		void separadorTerreno();
		int solicitarColumnaParcela();
		int solicitarFilaParcela();
		char menuComprar();
		void menuCosechar();
		void menuRegar();
		void menuSalir(Jugador* jugadorPtr);
		int cantidadAComprar();
		void saludoFinal(Jugador* jugadorPtr);
		char solicitarTipoCultivo();
		std::string msjTirarDado();
		std::string msjGalonesGanados();

};

#endif /* INTERFACES_PANTALLA_H_ */
