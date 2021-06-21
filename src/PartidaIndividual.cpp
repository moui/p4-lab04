#include "../lib/PartidaIndividual.h"

// Constructor y destructor 
PartidaIndividual::PartidaIndividual(int id, float duracion, bool finalizada, DtFechaHora* fecha, DtFechaHora* fecha_fin, Videojuego* videojuego, PartidaIndividual* continuacion)
    : Partida(id, duracion, finalizada, fecha, fecha_fin, videojuego)
{
    this->continuacion = continuacion;
}

PartidaIndividual::~PartidaIndividual()
{
}

// Getters
bool PartidaIndividual::getContinuacion()
{
    return (this->continuacion != NULL);
}

PartidaIndividual* PartidaIndividual::getContinuada(){
    return this->continuacion;
}


// Setters
void PartidaIndividual::setContinuacion(PartidaIndividual* partida)
{
    this->continuacion = partida;
}

// Metodos
float PartidaIndividual::darTotalHorasParticipantes()
{
    return getDuracion();
}
 DtPartidaIndividual* PartidaIndividual::getDatos()
 {
      DtPartidaIndividual* res=NULL;

      int id=this->getId();
      DtFechaHora* f= new DtFechaHora(this->getFecha());
      string nomVJ=this->getVideojuego()->getNombreVJ();
      int* continua = NULL;
      if (this->getContinuada() != NULL)
        continua = new int(this->getContinuada()->getId());
      DtFechaHora* f_fin;
      if (this->getFechaFin() == NULL)
        f_fin = NULL;
      else
        f_fin = new DtFechaHora(this->getFechaFin());

	  res = new DtPartidaIndividual(id, 0, f, f_fin, nomVJ, continua);
	  if(res==NULL)
	  {
		throw invalid_argument("No hay datos de partida, partidaIndividual.CPP ");
	  }
	  return res;
 }