#include "../../lib/datatypes/DtVideojuego.h"

DtVideojuego::DtVideojuego(string nombre, string descripcion, float costo1, float costo3, float costo12, 
    float costoV, float* totalHorasDeJuego)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->costo1 = costo1;
    this->costo3 = costo3;
    this->costo12 = costo12;
    this->costoV = costoV;
    this->totalHorasDeJuego = totalHorasDeJuego;
}

DtVideojuego::~DtVideojuego()
{
    if (totalHorasDeJuego != NULL)
        delete totalHorasDeJuego;
}

string DtVideojuego::getNombre()
{
    return this->nombre;
}

string DtVideojuego::getDescripcion()
{
    return this->descripcion;
}

float DtVideojuego::getCosto1()
{
    return this->costo1;
}

float DtVideojuego::getCosto3()
{
    return this->costo3;
}

float DtVideojuego::getCosto12()
{
    return this->costo12;
}

float DtVideojuego::getCostoV()
{
    return this->costoV;
}

float* DtVideojuego::getTotalHorasDeJuego()
{
    return this->totalHorasDeJuego;
}

ostream& operator<<(ostream& out, const DtVideojuego& dt)
{
    out << "Nombre: " << dt.nombre << endl;
    out << "Descripcion: " << dt.nombre << endl;
    out << "Costo suscripcion 1 mes: " << dt.costo1 << endl;
    out << "Costo suscripcion 3 mes: " << dt.costo3 << endl;
    out << "Costo suscripcion 12 mes: " << dt.costo12 << endl;
    out << "Costo suscripcion vitalicia: " << dt.costoV << endl;

    if (dt.totalHorasDeJuego != NULL)
        out << "Total horas de juego: " << *(dt.totalHorasDeJuego) << endl;

    return out;
}
