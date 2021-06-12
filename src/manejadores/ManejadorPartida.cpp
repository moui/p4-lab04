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
ManejadorUsuario::ManejadorUsuario(){}

// Destructor
ManejadorUsuario::~ManejadorUsuario(){
	partidasI.clear();
	partidasM.clear();
	delete instancia;
}

//Getters y Setters
PartidaIndividual* getPI(float id){ 
	PartidaIndividual* p = new partidasI[id]; 
	return p;
}

PartidaMultijugador* getPM(float id){
	PartidaMultijugador* p = new partidasM[id]; 
	return p;
}

void AgregarPartidaIndividual(float id, PartidaIndividual pi){
	partidasI[id] = pi;
}

void AgregarPartidaMultijugador(float id, PartidaMultijugador pm){
	partidasM[id] = pm;
}

