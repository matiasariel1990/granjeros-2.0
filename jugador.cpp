#include "jugador.h"

using namespace std;


    void Jugador::ingresarNombre(){
    	std::cout << "Ingrese el nombre del jugador: "
    			<< endl;
    	cin >> nombre;
    }


    std::string Jugador::obtenerNombre(){
    	return this->nombre;
    }


    void Jugador::establecerCreditos(int creditos){
    	this->creditos = creditos;
    }

    void Jugador::sumarCreditos(int creditos){
    	this->creditos += creditos;
    }

    int Jugador::obtenerCreditos(){
    	return creditos;
    }


    void Jugador::comprarTerreno(Dificultad dificultad){
    	//resta creditos ACA!!!
    	int cantTerrenos = 0;
    	Parcela parcelita;
    	while(cantTerrenos < (dificultad.obtenerCol()*
    			dificultad.obtenerFil())){
    		miTerreno.agregar(&parcelita);
    		cantTerrenos++;
    	}

    }

    void Jugador::venderTerreno(Dificultad dificultad){
    	int cantTerrenos = 0;
    	while(cantTerrenos < (dificultad.obtenerCol()*
    			dificultad.obtenerFil())){
    	 	miTerreno.remover(miTerreno.contarElementos());
    	  	cantTerrenos++;
    	    }
    	//Sumas los creditos correspondientes.
    }


    int Jugador::obtenerCantidadTerrenos(Dificultad dificultad){
    	int cantTerrenos = 0;
    	int nxm = dificultad.obtenerCol()*dificultad.obtenerFil();
    	cantTerrenos = (miTerreno.contarElementos()/nxm);
    	return cantTerrenos;
    }

    void Jugador::establecerUnidadesRiego(int unidadesRiego){
    	miTanque.aumentarCapacidad(unidadesRiego);
    }


    int Jugador::obtenerUnidadesRiego(){
    	return miTanque.obtenerCantidadAgua();
    }


    void Jugador::cargarAtributos(Dificultad dificultad){
    	creditos = dificultad.obtenerCreditos();
    	miTanque.aumentarCapacidad(dificultad.obtenerCapacidadTanque());
    	miAlmacen.comprarCapacidad(dificultad.obtenerCapacidadAlmacen());
    	Parcela parcelita;
    	int cantTerrenos = 0;
    	while(cantTerrenos < (dificultad.obtenerCol()*
    	    	dificultad.obtenerFil())){
    	    	miTerreno.agregar(&parcelita);
    	    	cantTerrenos++;
    	}
    }

    Parcela* Jugador::obtenerParcela(int nTerreno, int fila,
    		int columna, Dificultad dificultad){

    	int posicion = 0;
    	int parcial = 0;

    	parcial = (nTerreno - 1)*(dificultad.obtenerFil() * dificultad.obtenerCol());
    		if(fila < 2){
    		posicion = (columna + parcial);
    		}else{
    		int parcial2 = 0;
    			parcial2 = (fila - 1) * (dificultad.obtenerCol())
    			posicion = (columna + parcial2 + parcial);
    		}
    	return miTerreno.obtener((unsigned int) posicion);
    }
