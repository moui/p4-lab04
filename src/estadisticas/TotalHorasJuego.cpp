#include "../../lib/estadisticas/TotalHorasJuego.h"

TotalHorasJuego::TotalHorasJuego(string n, float v, string d)
{
    this->nomEstadistica=n;
    this->valor=v;
    this->descripcion=d;
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

DtEstadistica* TotalHorasJuego::calcular(Videojuego* v){
    DtEstadistica* res=NULL;
    float thj = v->getTotalHorasJugadas();
    res = new DtEstadistica("Total Horas Jugadas: ", thj);
    return res;
}
