#include "../../lib/datatypes/DtEstadistica.h"

DtEstadistica::DtEstadistica(string n, float valor)
{
    this->nomEstadistica=n;
    this->valor=valor;
}

DtEstadistica::~DtEstadistica()
{

}

string DtEstadistica::getNombre() const
{
    return this->nomEstadistica;
}
float DtEstadistica::getValor() const
{
    return this->valor;
}

std::ostream& operator<<(std::ostream& out, const DtEstadistica& dt){
    out << "Nombre: " << dt.getNombre() << endl;
    out << "Valor: " << dt.getValor() << endl;
    return out;
}