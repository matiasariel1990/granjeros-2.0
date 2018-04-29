/*
 * errores.h
 *
 *  Created on: 04/04/2018
 *      Author: algo2
 */

#ifndef ERROR_H_
#define ERROR_H_

#include <string>

		const std::string ER_ACCION_INVALIDA =
			"Ha seleccionado un valor invalido vuelva a intentarlo";
		const std::string ER_FONDOS_INSUFICIENTES =
			"No posee el dinero suficiente para comprar dichas semillas.";
		const std::string PARCELA_OCUPADA = "Esta parcela esta ocupada";
		const std::string SIN_SEMILLAS = "No posee semillas de ese cultivo";
		const std::string SIN_AGUA = "No posee agua disponible";
		const std::string PARCELA_INVALIDA = "Parcela invalida.";
		const std::string ER_CULTIVOS = "Cultivo invalido!!!!  (Respete mayusculas)";
		const std::string ER_PARCELA_VACIA = "Esa parcela esta vacia!!";
		const std::string ER_PARCELA_PODRIDA = "Esa parcela esta podrida!!";
		const std::string ER_PARCELA_SECA = "Esa parcela se te seco, ten cuidado!!";
		const std::string ER_FALTA_TIEMPO = "Todavia no puedes cosechar esto";

class Error{
	private:
		//Mensajes de error.

	public:
		std::string accionInvalida();
		std::string fondosInsuficientes();
		std::string parcelaOcupada();
		std::string sinSemillas();
		std::string sinAgua();
		std::string parcelaInvalida();
		std::string cultivoInvalido();
		std::string	parcelaPodrida();
		std::string parcelaSeca();
		std::string	parcelaVacia();
		std::string faltaTiempo();

};


#endif /* ERROR_H_ */
