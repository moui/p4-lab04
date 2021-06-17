#include "../../lib/estadisticas/TotalJugadoresSuscritos.h"

TotalJugadoresSuscritos::TotalJugadoresSuscritos(string n, float v)
{
    this->nomEstadistica=n;
    this->valor=v;
}

TotalJugadoresSuscritos::~TotalJugadoresSuscritos()
{

}

string TotalJugadoresSuscritos::getNombre()
{
    return this->nomEstadistica;
}

float TotalJugadoresSuscritos::getValor()
{
    return this->valor;
}

void TotalJugadoresSuscritos::setNombre(string n)
{
    this->nomEstadistica=n;
}
void TotalJugadoresSuscritos::setValor(float v)
{
    this->valor=v;
}
