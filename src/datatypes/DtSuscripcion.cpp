#include "../../lib/datatypes/DtSuscripcion.h"




DtSuscripcion(string nomVJ, TipoFecha f, float costo, TipoPago p, TipoEstado e){
  this->nombreVJ = nomVJ;
  this->fecha = f;
  this->costo = c;
  this->pago = p;
  this->estado = e;
  return;
}
~DtSuscripcion();

string Suscripcion::getnombreVJ(){
  return this->nombreVJ;
}

DtFechaHora Suscripcion::getFecha(){
  return this->fecha;
}

float Suscripcion::getCosto(){
  return this->costo;
}

TipoPago Suscripcion::getTipoPago(){
  return this->pago;
}

TipoEstado Suscripcion::getEstado(){
  return this->estado;
}
