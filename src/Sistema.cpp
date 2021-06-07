#include "../lib/Sistema.h"

// Singleton
Sistema* Sistema::instancia = NULL;

// Constructor
Sistema::Sistema()
{
    fechaSistema = new FechaSistema();
}

// Destructor
Sistema::~Sistema()
{
    delete fechaSistema;
}

// GetInstance
Sistema* Sistema::getInstancia()
{
    if (instancia == NULL)
        instancia = new Sistema();

    return instancia;
}

// Getters
DtFechaHora* Sistema::getFecha()
{
    this->fechaSistema->actualizarFechaActual();
    return this->fechaSistema->getFechaActual();
}

// Setters
void Sistema::setFecha(DtFechaHora* fechaSistema)
{
    this->fechaSistema->setFechaInicial(fechaSistema);
}