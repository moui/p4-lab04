#include "../lib/Categoria.h"

Categoria::Categoria(string nombre, string descripcion, TipoCat TipoCat)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipo = tipo;
}

Categoria::~Categoria()
{

}

string Categoria::getDescripcion()
{
    return this->descripcion;
}

string Categoria::getNombre()
{
    return this->nombre;
}

TipoCat Categoria::getTipoCat()
{
    return this->tipo;
}

void Categoria::setNombre(string nombre)
{
    this->nombre = nombre;
}

void Categoria::setDescripcion(string descripcion)
{
    this->descripcion = descripcion;
}

void Categoria::setTipoCat(TipoCat tipo)
{
    this->tipo = tipo;
}

DtCategoria* Categoria::getDtCategoria()
{
    return new DtCategoria(this->nombre, this->descripcion, this->tipo);
}