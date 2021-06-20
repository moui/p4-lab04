#include "../lib/PartidaMultijugador.h"

// Constructor y destructor
PartidaMultijugador::PartidaMultijugador(float id, float duracion, bool finalizada, DtFechaHora* fecha, Videojuego* videojuego,
    bool enVivo, map<string, InfoPartidaMulti*> mapInfoPM) : Partida(id, duracion, finalizada, fecha, videojuego)
{
    this->transmitidaEnVivo = enVivo;
    this->participan = mapInfoPM;
}

PartidaMultijugador::~PartidaMultijugador()
{
};

// Getters
bool PartidaMultijugador::getTransmitidaEnVivo()
{
    return this->transmitidaEnVivo;
}

map<string, InfoPartidaMulti*> PartidaMultijugador::getParticipan()
{
   return this->participan;
}

// Setters
void PartidaMultijugador::setTransmitidaEnVivo (bool enVivo)
{
    this->transmitidaEnVivo = enVivo;
}

void PartidaMultijugador::setParticipan(map<string, InfoPartidaMulti*> mapInfoPM)
{
    this->participan = mapInfoPM;
}

// Operaciones
float PartidaMultijugador::darTotalHorasParticipantes()
{
    return 0;
}


void PartidaMultijugador::setHoraAbandono(DtFechaHora f, string clave){
	participan[clave]->setAbandonaEn(f);
}

void PartidaMultijugador::forzarAbandono(DtFechaHora f){
	map<string, InfoPartidaMulti*>::iterator it = participan.begin();
	while(it != participan.end()){
		if(it->second->getAbandonaEn().getHora() == this->getFecha()->getHora()) {
			it->second->getAbandonaEn();
		}
		++it;
	}
	this->setDuracion(this->getFecha()->getHora() - f.getHora());
}
