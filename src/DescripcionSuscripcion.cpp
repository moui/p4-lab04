#include "../lib/DescripcionSuscripcion.h"

DescripcionSuscripcion::DescripcionSuscripcion(string nom, float costo, TipoPeriodo p)
{
  this->nombre = nom;
  this->costo = costo;
  this->periodo = p;
  return;
}


    //getters

    string DescripcionSuscripcion::getNombre(){
      return this->nombre;
    }

    float DescripcionSuscripcion::getCosto(){
      return this->costo;
    }

    TipoPeriodo DescripcionSuscripcion::getPeriodo(){
      return this->periodo;
    }

    set<Suscripcion*> DescripcionSuscripcion::getSuscripciones()
    {
      return this->suscripciones;
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
