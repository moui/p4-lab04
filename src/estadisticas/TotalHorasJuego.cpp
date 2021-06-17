#include "../../lib/estadisticas/TotalHorasJuego.h"

TotalHorasJuego::TotalHorasJuego(string n, float v)
{
    this->nomEstadistica=n;
    this->valor=v;
}

TotalHorasJuego::~TotalHorasJuego()
{

}

string TotalHorasJuego::getNombre()
{
    return this->nomEstadistica;
}

float TotalHorasJuego::getValor()
{
    return this->valor;
}

void TotalHorasJuego::setNombre(string n)
{
    this->nomEstadistica=n;
}
void TotalHorasJuego::setValor(float v)
{
    this->valor=v;
}
