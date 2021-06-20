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
PartidaIndividual* ManejadorPartida::getPI(int id)
{
	if (partidasI.find(id) == partidasI.end())
		return NULL;
	
	return (partidasI.find(id)->second);
}

PartidaMultijugador* ManejadorPartida::getPM(int id)
{
	if (partidasM.find(id) == partidasM.end())
		return NULL;
	
	return (partidasM.find(id)->second);
}

void ManejadorPartida::AgregarPartidaIndividual(int id, PartidaIndividual* pi)
{
	partidasI.insert( pair <int, PartidaIndividual*>(id,pi) );
}

void ManejadorPartida::AgregarPartidaMultijugador(int id, PartidaMultijugador* pm)
{
	partidasM.insert( pair <int,PartidaMultijugador*>(id,pm) );
}

set<DtPartidaMultijugador*> ManejadorPartida::listarPartidasMultijugadorUnidas(string mailJugador)
{
	set<DtPartidaMultijugador*> res;	
 
	for (itPM=partidasM.begin(); itPM!=partidasM.end(); itPM++)
	{
		auto it=itPM->second->getParticipan().find(mailJugador);
		if ( it != itPM->second->getParticipan().end() && !(itPM->second->getFinalizada()) )
		{
			set<string> nicknameUnidos;
			for ( auto itUnidos = (itPM)->second->getParticipan().begin(); itUnidos!= (itPM)->second->getParticipan().end(); itUnidos++)
			{
				nicknameUnidos.insert((itUnidos)->second->getParticipa()->getNickname());
			}
			res.insert( new DtPartidaMultijugador((itPM)->first, (itPM)->second->getDuracion(), (itPM)->second->getFecha(),
			(itPM)->second->getVideojuego()->getNombreVJ(), (itPM)->second->getTransmitidaEnVivo(), nicknameUnidos, nicknameUnidos.size()) );
		}
	}
	return res;
}
 

