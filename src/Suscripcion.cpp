#include "../lib/Suscripcion.h"

Suscripcion::Suscripcion(string nomVJ, DtFechaHora f, float costo, TipoPago p, TipoEstado e)
{
  this->nombreVJ = nomVJ;
  this->fecha = f;
  this->costo = costo;
  this->pago = p;
  this->estado = e;
  return;
}

Suscripcion::~Suscripcion()
{
}

    //getters

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

    //Setters
    void Suscripcion::setNombreVJ(string n){
      this->nombreVJ=n;
    }

    void Suscripcion::setFecha(DtFechaHora f){
      this->fecha=f;
    }

    void Suscripcion::setCosto(float c){
      this->costo=c;
    }

    void Suscripcion::setTipoPago(TipoPago p){
      this->pago=p;
    }

    void Suscripcion::setTipoEstado(TipoEstado e){
      this->estado=e;
    }
