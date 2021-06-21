#include "../lib/InfoPartidaMulti.h"

// Constructor y destructor
InfoPartidaMulti::InfoPartidaMulti(DtFechaHora* fecha, Jugador* jugador)
{
    this->abandonaEn = fecha;
    this->participa = jugador;
}

InfoPartidaMulti::~InfoPartidaMulti()
{
}

// Getters
DtFechaHora* InfoPartidaMulti::getAbandonaEn()
{
    return this->abandonaEn;
}

Jugador* InfoPartidaMulti::getParticipa()
{
    return this->participa;
}

// Setters
void InfoPartidaMulti::setAbandonaEn(DtFechaHora* fecha)
{
    this->abandonaEn = fecha;
}

void InfoPartidaMulti::setParticipa(Jugador* jugador)
{
    this->participa = jugador;
}