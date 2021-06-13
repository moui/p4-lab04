#include "../../lib/datatypes/DtDescripcionSuscripcion.h"

DtDescripcionSuscripcion::DtDescripcionSuscripcion(string nom, float costo, TipoPeriodo p)
{
  this->nombre = nom;
  this->costo = costo;
  this->periodo = p;
  return;
}

DtDescripcionSuscripcion::~DtDescripcionSuscripcion()
{

}

string DtDescripcionSuscripcion::getNombre()
{
  return this->nombre;
}

float DtDescripcionSuscripcion::getCosto()
{
  return this->costo;
}

TipoPeriodo DtDescripcionSuscripcion::getPeriodo()
{
  return this->periodo;
}
