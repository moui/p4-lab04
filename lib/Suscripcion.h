#ifndef SUSCRIPCION
#define SUSCRIPCION

#include "DescripcionSuscripcion.h"
#include "datatypes/TipoEstado.h"
#include "datatypes/TipoPago.h"
#include <string>
#include <map>
//#include "Jugador.h"

class DescripcionSuscripcion;
//class Jugador;

using namespace std;


class Suscripcion{
  private:
    string nombreVJ;
    DtFechaHora fecha;
    float costo;
    TipoPago pago;
    TipoEstado estado;
    bool vitalicia;
  public:
    Suscripcion(string nomVJ, DtFechaHora f, float costo, TipoPago p, TipoEstado e);
    ~Suscripcion();

//Getters
  string getnombreVJ();
  DtFechaHora getFecha();
  float getCosto();
  TipoPago getTipoPago();
  TipoEstado getEstado();
  bool getVitalicia();

//Setters
void setNombreVJ(string n);
void setFecha(DtFechaHora f);
void setCosto(float c);
void setTipoPago(TipoPago p);
void setTipoEstado(TipoEstado e);
void setVitalicia(bool v);

};

#endif
