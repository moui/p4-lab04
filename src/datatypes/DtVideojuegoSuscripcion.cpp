#include "../../lib/datatypes/DtVideojuegoSuscripcion.h"

DtVideojuegoSuscripcion::DtVideojuegoSuscripcion(string n, float c1, float c3, float c12, float cV)
{
this->nomVJ=n;    
this->costo1=c1;
this->costo3=c3;
this->costo12=c12;
this->costoV=cV;

}

DtVideojuegoSuscripcion::~DtVideojuegoSuscripcion()
{
    
}

string DtVideojuegoSuscripcion::getNombreVideojuego() const {
    return this->nomVJ;

}
float DtVideojuegoSuscripcion::getCosto1() const {
    return this->costo1;
}

float DtVideojuegoSuscripcion::getCosto3() const {
    return this->costo3;
}
float DtVideojuegoSuscripcion::getCosto12() const {
    return this-> costo12;
}
float DtVideojuegoSuscripcion::getCostoV() const {
    return this->costoV;
}
std::ostream& operator<<(std::ostream& os, const DtVideojuegoSuscripcion& dt){

    os<<"Nombre del videojuego: " << dt.getNombreVideojuego() <<"\n";
    os<<"COSTO SUSCRIPCION MENSUAL: $" << dt.getCosto1() << "\n";  
    os<<"COSTO SUSCRIPCION TRIMESTRAL: $" << dt.getCosto3() << "\n";
    os<<"COSTO SUSCRIPCION ANUAL: $" << dt.getCosto12() << "\n";
    os<<"COSTO SUSCRIPCION VITALICIA: $" << dt.getCostoV() << "\n";
    return os;
    }