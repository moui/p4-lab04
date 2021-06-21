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
