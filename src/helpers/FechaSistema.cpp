#include "../../lib/helpers/FechaSistema.h"

FechaSistema* FechaSistema::instancia = NULL;

FechaSistema::FechaSistema()
{
    fecha = new DtFechaHora();
}

FechaSistema::~FechaSistema()
{
    delete fecha;
}

FechaSistema* FechaSistema::getInstancia()
{
    if (instancia == NULL)
        instancia = new FechaSistema();
    return instancia;
}

DtFechaHora* FechaSistema::getFecha()
{
    return fecha;
}

void FechaSistema::setFecha(DtFechaHora* nuevaFecha)
{
    delete fecha;
    this->fecha = nuevaFecha;
}