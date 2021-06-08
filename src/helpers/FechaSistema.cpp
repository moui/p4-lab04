#include "../../lib/helpers/FechaSistema.h"

FechaSistema::FechaSistema()
{
    fecha = new DtFechaHora();
}

FechaSistema::~FechaSistema()
{
    delete fecha;
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