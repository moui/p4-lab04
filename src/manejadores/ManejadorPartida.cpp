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
ManejadorPartida::ManejadorPartida() {}

// Destructor
ManejadorPartida::~ManejadorPartida()
{
	for (itPI = partidasI.begin(); itPI != partidasI.end(); ++itPI)
    {
        if (itPI->second != NULL)
            delete itPI->second;
    }
    partidasI.clear();

	for (itPM = partidasM.begin(); itPM != partidasM.end(); ++itPM)
    {
        if (itPM->second != NULL)
            delete itPM->second;
    }
    partidasM.clear();
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

int ManejadorPartida::generarIdPartidaMulti()
{
	if (partidasM.empty())
		return 2;

	return 4*static_cast<int>(partidasM.size());
}

int ManejadorPartida::generarIdPartidaInd()
{
	if (partidasI.empty())
		return 1;

	return 2*static_cast<int>(partidasI.size()) + 1;
}

set<DtPartidaMultijugador*> ManejadorPartida::listarPartidasMultijugadorUnidas(string mailJugador)
{
	set<DtPartidaMultijugador*> res;	
	if(partidasM.empty())
	{
		throw invalid_argument("No hay partidas Multijugador en el sistema. ");
	} else 
	{
		for (itPM=partidasM.begin(); itPM!=partidasM.end(); itPM++)
		{
			if (itPM->second->participa(mailJugador) && itPM->second->getFinalizada())
				res.insert(itPM->second->getDatos());
	 	}
	}
	return res;
}

void ManejadorPartida::ConfirmarAbandonarPartida(string mail, int partidaMJ)
{
	 itPM=partidasM.find(partidaMJ);
	 auto itInfoPartida = (itPM->second->getParticipan()).find(mail);
	 DtFechaHora* fechaSistema = FechaSistema::getInstancia()->getFecha();
	 itInfoPartida->second->setAbandonaEn(fechaSistema);
}
 
void ManejadorPartida::finalizarPartida(DtFechaHora* fecha_fin, int id){
	if ( partidasI.find(id) != partidasI.end() ){
		this->getPI(id)->setFechaFin(fecha_fin);
		this->getPI(id)->setFinalizada(true);
		this->getPI(id)->setDuracion(DtFechaHora::Dias(fecha_fin, this->getPI(id)->getFecha()) * 24);
		this->getPI(id)->getVideojuego()->setTotalHorasJugadas(this->getPI(id)->getDuracion());
	}
	else if ( partidasM.find(id) != partidasM.end() ){
		this->getPM(id)->setFechaFin(fecha_fin);
		this->getPM(id)->setFinalizada(true);
		this->getPM(id)->setDuracion(DtFechaHora::Dias(fecha_fin, this->getPM(id)->getFecha()));
		this->getPM(id)->getVideojuego()->setTotalHorasJugadas(calculaTotalHorasJugadasMulti(id));
	}
	else{
		throw invalid_argument("No hay partida con ese ID en el sistema. ");
	}
}

float ManejadorPartida::calculaTotalHorasJugadasMulti(int id){
	float ret;
	map<string, InfoPartidaMulti*> participantes = this->getPM(id)->getParticipan();

	return ret;
}
