#include "../../lib/datatypes/DtCategoria.h"

DtCategoria::DtCategoria(string nombre, string descripcion, TipoCat tipo)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->tipo = tipo;
}

DtCategoria::~DtCategoria()
{
    
}

//getters
string DtCategoria::getNombre(){
    return this->nombre;
}

string DtCategoria::getDescripcion(){
    return this->descripcion;
}

TipoCat DtCategoria::getTipo(){
    return this->tipo;
}

//setters
void DtCategoria::setNombre(string nombre){
    this->nombre = nombre;
}
void DtCategoria::setDescripcion(string descripcion){
    this->descripcion = descripcion;
}
void DtCategoria::setTipo(TipoCat tipo){
    this->tipo = tipo;
}