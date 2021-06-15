#include "../../lib/datatypes/DtSuscripcion.h"




DtSuscripcion::DtSuscripcion(string nomVJ, DtFechaHora f, float costo, TipoPago p, TipoEstado e){
  this->nombreVJ = nomVJ;
  this->fecha = f;
  this->costo = costo;
  this->pago = p;
  this->estado = e;
  return;
}
DtSuscripcion::~DtSuscripcion()
{
  
}

string DtSuscripcion::getnombreVJ(){
  return this->nombreVJ;
}

DtFechaHora DtSuscripcion::getFecha(){
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
bool DtSuscripcion::getVitalicia(){
  return this->vitalicia;
}