/*
 * pantalla.cpp
 *
 *  Created on: 24/04/2018
 *      Author: ahre-manga2
 */

#include "pantalla.h"
#include "jugador.h"
#include "error.h"
#include <iostream>

void Pantalla::imprimirBienvenida(){
	cout << TITULO
			<< endl;
}

void Pantalla::solicitarJugadores(){
	cout << CANTIDAD_JUGADORES
			<< endl;
}

void Pantalla::solicitarNombre(int jugN){
	cout << SOLICITAR_NOMBRE
			<< jugN
			<< endl;
}

void Pantalla::imprimirMenu(){
	cout << SOLICITAR_ACCION
			<< endl
			<< OP1
			<< OP2
			<< OP3
			<< OP4
			<< OP5
			<< OP9
			<< endl;
}

void Pantalla::imprimirEstadoDelJugador(Jugador* jugadorPtr){
	int turnosRestantes = (jugadorPtr->obtenerTurno() - 1);
	cout << "Nombre: "
			<< jugadorPtr->obtenerNombre()
			<< endl
			<< "Creditos: "
			<< jugadorPtr->obtenerCredito()
			<< endl
			<< "Galones de agua: "
			<< jugadorPtr->obtenerGalonesDeAgua()
			<< endl
			<< "Agua de turno: "
			<< jugadorPtr->obtenerAguaTurno()
			<< endl
			<< "Turnos restantes: "
			<< turnosRestantes
			<< endl;
}

void Pantalla::imprimirSeparador(){
	cout << SEPARADOR
			<< SEPARADOR
			<< endl;
}

//Esto lo podemos hacer con todos los terrenos lo tenemos que pensar!!
void Pantalla::imprimirTerreno(Jugador* jugadorPtr){
	separadorTerreno();
	for( int i = 0; i < Jugador::maxFilas(); i++){

		for( int j = 0; j < Jugador::maxColumnas(); j++){
			cout << "| "
				<< jugadorPtr->terreno[i][j].imagenRepresentativa()
				<< jugadorPtr->terreno[i][j].infoParcela();
		}
		cout << "|"
				<< endl;
	}
	separadorTerreno();
	cout << endl;


}

void Pantalla::separadorTerreno(){

	for( int i = 0; i < Jugador::maxColumnas(); i++){
			cout << " ___";
		}

	cout << endl;
}


int Pantalla::solicitarColumnaParcela(){
	cout << SOLICITAR_COLUMNA
			<< endl;
	int numeroColumna;
	cin >> numeroColumna;
	numeroColumna--;
	return numeroColumna;
}

int Pantalla::solicitarFilaParcela(){
	cout << SOLICITAR_FILA
				<< endl;
	int numeroFila;
	cin >> numeroFila;
	numeroFila--;
	return numeroFila;
}

void Pantalla::menuSalir(Jugador* jugadorPtr){
	char eleccion;
	cout << CONFIRME_SALIDA
			<< endl;
		cin >> eleccion;
		if(eleccion == 's'){

		}
}


char Pantalla::solicitarTipoCultivo(){
	char tipoCultivo;
	Error e;
	cout << SOLICITAR_TIPO_CULTIVO
				<< endl;
	cin >> tipoCultivo;
	while(((tipoCultivo < 'A')||
			(tipoCultivo > 'C'))){
		cout << e.cultivoInvalido()
				<< endl;
		cin >> tipoCultivo;
	};
	return tipoCultivo;
}

int Pantalla::cantidadAComprar(){
	int cantidad;
	cout << SOLICITAR_CANTIDAD
		<< endl;
	cin >> cantidad;
	return cantidad;
}

void Pantalla::saludoFinal(Jugador* jugadorPtr){
	cout << DESPEDIDA
			<< jugadorPtr->obtenerCredito()
			<< endl;
	imprimirSeparador();
	cout << endl;
}

void Pantalla::imprimirPantallaTurno(Jugador* jugadorPtr, bool* estadoJuegoPtr){
	if(jugadorPtr->obtenerTurno() == 1){
		*estadoJuegoPtr = false;
	}
	imprimirSeparador();
	imprimirEstadoDelJugador(jugadorPtr);
	imprimirTerreno(jugadorPtr);
	imprimirMenu();
	imprimirSeparador();
}

string Pantalla::msjTirarDado(){
	return MENSAJE_TIRAR_DADO;
}

string Pantalla::msjGalonesGanados(){
	return MENSAJE_GALONES_GANADOS;
}
