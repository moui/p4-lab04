#include "../lib/PartidaMultijugador.h"

// Constructor y destructor
PartidaMultijugador::PartidaMultijugador(int id, float duracion, bool finalizada, DtFechaHora* fecha, DtFechaHora* fecha_fin, Videojuego* videojuego,
    bool enVivo, map<string, InfoPartidaMulti*> mapInfoPM) : Partida(id, duracion, finalizada, fecha, fecha_fin, videojuego)
{
    this->transmitidaEnVivo = enVivo;
    this->participan = mapInfoPM;
}

PartidaMultijugador::~PartidaMultijugador()
{
	if (!participan.empty())
	{
		for (auto it = participan.begin(); it != participan.end(); ++it)
		{
			delete it->second;
		}
	}
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


void PartidaMultijugador::setHoraAbandono(DtFechaHora* f, string clave){
	InfoPartidaMulti* info = participan.find(clave)->second;
	info->setAbandonaEn(f);
}

void PartidaMultijugador::abandonarTodos(DtFechaHora* f)
{
	for (auto it = participan.begin(); it != participan.end(); ++it)
	{
		it->second->setAbandonaEn(f);
	}
}

void PartidaMultijugador::forzarAbandono(DtFechaHora* f){
	map<string, InfoPartidaMulti*>::iterator it = participan.begin();
	while(it != participan.end()){
		if(it->second->getAbandonaEn()->getHora() == this->getFecha()->getHora()) {
			it->second->getAbandonaEn();
		}
		++it;
	}
	this->setDuracion(this->getFecha()->getHora() - f->getHora());
}

bool PartidaMultijugador::participa(string email)
{
	if (participan.empty())
		return false;
	
	if (participan.find(email) == participan.end())
		return false;
	
	return true;
}

   DtPartidaMultijugador* PartidaMultijugador::getDatos()
  {   
      DtPartidaMultijugador* res=NULL;

      int id=this->getId();
      DtFechaHora* f=new DtFechaHora(this->getFecha());
      string nomVJ=this->getVideojuego()->getNombreVJ();
	  bool vivo=this->getTransmitidaEnVivo();

	  set<string> nicknameUnidos;
	  for (auto it=participan.begin(); it!=participan.end(); it++)
	  {
		  nicknameUnidos.insert(it->second->getParticipa()->getNickname());
	  }
	  res = new DtPartidaMultijugador(id, f, nomVJ, vivo, nicknameUnidos);
	  if(res==NULL)
	  {
		throw invalid_argument("No hay datos de partida, partidamultijugador.cpp. ");
	  }
	  return res;

  }