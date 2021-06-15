#ifndef DT_SUSCRIPCION
#define DT_SUSCRIPCION

#include <string>
#include "TipoPago.h"
#include "TipoEstado.h"
#include "DtFechaHora.h"

using namespace std;


class DtSuscripcion{
  private:
    string nombreVJ;
    DtFechaHora fecha;
    float costo;
    TipoPago pago;
    TipoEstado estado;
    bool vitalicia;
  public:
    DtSuscripcion(string nomVJ, DtFechaHora f, float costo, TipoPago p, TipoEstado e);
    ~DtSuscripcion();

//Getters
  string getnombreVJ();
  DtFechaHora getFecha();
  float getCosto();
  TipoPago getTipoPago();
  TipoEstado getEstado();
  bool getVitalicia();
  };

#endif
