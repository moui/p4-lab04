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
string DtCategoria::getNombre() const {
    return this->nombre;
}

string DtCategoria::getDescripcion() const{
    return this->descripcion;
}

TipoCat DtCategoria::getTipo() const {
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

std::ostream& operator<<(std::ostream& out,const DtCategoria& dt){
    out << "Nombre: " << dt.getNombre() << endl;
    out << "Descripcion: " << dt.getDescripcion() << endl;
    out << "Tipo: ";
    switch (dt.getTipo()) {
        case TipoCat::Plataforma:
            out << "Plataforma" << endl;
            break;
        case TipoCat::Genero:
            out << "Genero" << endl;
            break;
        case TipoCat::Otro:
            out << "Otro" << endl;
            break;
    }
    return out;
}