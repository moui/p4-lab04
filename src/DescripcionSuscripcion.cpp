#include "../lib/DescripcionSuscripcion.h"

DescripcionSuscripcion::DescripcionSuscripcion(string nom, DtFechaHora f, float costo, TipoPago p, TipoEstado e)
{
  this->nombre = nom;
  this->costo = c;
  this->periodo = p;
  return;
}


    //getters

    string DescripcionSuscripcion::getnombreVJ(){
      return this->nombreVJ;
    }

    float DescripcionSuscripcion::getCosto(){
      return this->costo;
    }

    TipoPago DescripcionSuscripcion::getTipoPeriodo(){
      return this->periodo;
    }


    //Setters
    void DescripcionSuscripcion::setNombre(string n){
      this->nombre=n;
    }


    void DescripcionSuscripcion::setCosto(float c){
      this->costo=c;
    }

    void DescripcionSuscripcion::setTipoPeriodo(TipoPeriodo p){
      this->periodo=p;
    }
