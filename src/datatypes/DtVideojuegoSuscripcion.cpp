#include "../../lib/datatypes/DtVideojuegoSuscripcion.h"

DtVideojuegoSuscripcion::DtVideojuegoSuscripcion(float c1, float c3, float c12, float cV)
{
this->costo1=c1;
this->costo3=c3;
this->costo12=c12;
this->costoV=cV;

}

DtVideojuegoSuscripcion::~DtVideojuegoSuscripcion()
{
    
}

string DtVideojuegoSuscripcion::getNombreVideojuego(){
    return this->nomVJ;

}
float DtVideojuegoSuscripcion::getCosto1(){
    return this->costo1;
}

float DtVideojuegoSuscripcion::getCosto3(){
    return this->costo3;
}
float DtVideojuegoSuscripcion::getCosto12(){
    return this-> costo12;
}
float DtVideojuegoSuscripcion::getCostoV(){
    return this->costoV;
} 