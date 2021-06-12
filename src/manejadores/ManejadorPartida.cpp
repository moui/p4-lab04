#include "../../lib/manejadores/ManejadorPartida.h"

// Singleton
ManejadorPartida* ManejadorPartida::instancia = NULL;

// GetInstance
ManejadorPartida* ManejadorPartida::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new ManejadorPartida();
    }
    return instancia;
}

// Constructor
ManejadorPartida::ManejadorPartida(){}

// Destructor
ManejadorPartida::~ManejadorPartida(){
	partidasI.clear();
	partidasM.clear();
	delete instancia;
}

//Getters y Setters
PartidaIndividual* ManejadorPartida::getPI(float id){ 
	PartidaIndividual* p = & this->partidasI[id]; 
	return p;
}

PartidaMultijugador* ManejadorPartida::getPM(float id){
	PartidaMultijugador* p = & this->partidasM[id]; 
	return p;
}

void ManejadorPartida::AgregarPartidaIndividual(float id, PartidaIndividual pi){
	this->partidasI[id] = pi;
}

void ManejadorPartida::AgregarPartidaMultijugador(float id, PartidaMultijugador pm){
	this->partidasM[id] = pm;
}


