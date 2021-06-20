#include "../../lib/datatypes/DtSuscripcion.h"




DtSuscripcion::DtSuscripcion(string nomVJ, DtFechaHora* f, float costo, TipoPago p, TipoEstado e, TipoPeriodo periodo){
  this->nombreVJ = nomVJ;
  this->fecha = f;
  this->costo = costo;
  this->pago = p;
  this->estado = e;
  this->periodo=periodo;
  return;
}
DtSuscripcion::~DtSuscripcion()
{
  
}

string DtSuscripcion::getnombreVJ(){
  return this->nombreVJ;
}

DtFechaHora* DtSuscripcion::getFecha(){
  return this->fecha;
}

float DtSuscripcion::getCosto(){
  return this->costo;
}

TipoPago DtSuscripcion::getTipoPago(){
  return this->pago;
}

TipoEstado DtSuscripcion::getEstado(){
  return this->estado;
}
TipoPeriodo DtSuscripcion::getPeriodo(){
  return this->periodo;
}