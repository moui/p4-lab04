#include "../../lib/datatypes/DtDescripcionSuscripcion.h"




DtSuscripcion(string nom, float costo, TipoPeriodo p){
  this->nombre = nom;
  this->costo = c;
  this->periodo = p;
  return;
}
~DtDescripcionSuscripcion();

string DtDescripcionSuscripcion::getnombre(){
  return this->nombre;
}

float DtDescripcionSuscripcion::getCosto(){
  return this->costo;
}

TipoPago DtDescripcionSuscripcion::getTipoPeriodo(){
  return this->periodo;
}
