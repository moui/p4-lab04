#include "../lib/Suscripcion.h"
// falta agregar el tiposuscripcion y ponerselo para saber que tipo de suscripcion es para siempre.

Suscripcion::Suscripcion(string nomVJ, DtFechaHora* f, float costo, TipoPago pago, TipoPeriodo periodo, bool cancelada)
{
  this->nombreVJ = nomVJ;
  this->fecha = f;
  this->costo = costo;
  this->pago = pago;
  this->periodo = periodo;
  this->cancelada = cancelada;
}

Suscripcion::~Suscripcion()
{
    if (fecha != NULL)
        delete fecha;
}

//Getters
string Suscripcion::getnombreVJ()
{
    return this->nombreVJ;
}

DtFechaHora* Suscripcion::getFecha()
{
    return this->fecha;
}

float Suscripcion::getCosto()
{
    return this->costo;
}

TipoPago Suscripcion::getTipoPago()
{
    return this->pago;
}

TipoEstado Suscripcion::getEstado()
{
    if (periodo == TipoPeriodo::Vitalicia)
        return TipoEstado::activa;

    if (cancelada == true)
        return TipoEstado::cancelada;
    
    DtFechaHora* fechaSistema = FechaSistema::getInstancia()->getFecha();
    float meses = DtFechaHora::Meses(fechaSistema, this->fecha);
    
    switch (this->periodo)
    {
        case TipoPeriodo::Mensual:
            if (meses > 1)
                return TipoEstado::expirada;
            else
                return TipoEstado::activa;

        case TipoPeriodo::Trimestral:
            if (meses > 3)
                return TipoEstado::expirada;
            else
                return TipoEstado::activa;

        case TipoPeriodo::Anual:
            if (meses > 12)
                return TipoEstado::expirada;
            else
                return TipoEstado::activa;

        default:
            throw 0;
    }
}

TipoPeriodo Suscripcion::getPeriodo()
{
    return this->periodo;
}

bool Suscripcion::getCanceleda()
{
    return this->cancelada;
}

//Setters
void Suscripcion::setNombreVJ(string n)
{
    this->nombreVJ=n;
}

void Suscripcion::setFecha(DtFechaHora* f)
{
    this->fecha=f;
}

void Suscripcion::setCosto(float c)
{
    this->costo=c;
}

void Suscripcion::setTipoPago(TipoPago p)
{
    this->pago=p;
}

void Suscripcion::setPeriodo(TipoPeriodo periodo)
{
    this->periodo = periodo;
}

void Suscripcion::setCancelada(bool cancelada)
{
    this->cancelada = cancelada;
}
