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
ManejadorPartida::~ManejadorPartida()
{
	partidasI.clear();
	partidasM.clear();
	delete instancia;
}

//Getters y Setters
PartidaIndividual* ManejadorPartida::getPI(float id)
{
	if (partidasI.find(id) == partidasI.end())
		return NULL;
	
	return (partidasI.find(id)->second);
}

PartidaMultijugador* ManejadorPartida::getPM(float id)
{
	if (partidasM.find(id) == partidasM.end())
		return NULL;
	
	return (partidasM.find(id)->second);
}

void ManejadorPartida::AgregarPartidaIndividual(float id, PartidaIndividual* pi)
{
	partidasI.insert( pair <float, PartidaIndividual*>(id,pi) );
}

void ManejadorPartida::AgregarPartidaMultijugador(float id, PartidaMultijugador* pm)
{
	partidasM.insert( pair <float,PartidaMultijugador*>(id,pm) );
}


