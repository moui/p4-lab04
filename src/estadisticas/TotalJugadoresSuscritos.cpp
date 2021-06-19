#include "../../lib/estadisticas/TotalJugadoresSuscritos.h"

TotalJugadoresSuscritos::TotalJugadoresSuscritos(string n, float v, string d)
{
    this->nomEstadistica=n;
    this->valor=v;
    this->descripcion=d;
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

DtEstadistica* TotalJugadoresSuscritos::calcular(Videojuego*v){
    DtEstadistica* res=NULL;
    int tjs= v->getSuscritos();
    float valor = static_cast<float>(tjs);
    res= new DtEstadistica("Total Jugadores Suscritos", valor);

    return res;
}
