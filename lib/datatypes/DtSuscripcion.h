#ifndef DT_SUSCRIPCION
#define DT_SUSCRIPCION

#include <string>
#include "TipoPago.h"
#include "TipoEstado.h"
#include "TipoPeriodo.h"
#include "DtFechaHora.h"

using namespace std;


class DtSuscripcion{
  private:
    string nombreVJ;
    DtFechaHora* fecha;
    float costo;
    TipoPago pago;
    TipoEstado estado;
    TipoPeriodo periodo;
  public:
    DtSuscripcion(string nomVJ, DtFechaHora* f, float costo, TipoPago p, TipoEstado e, TipoPeriodo periodo);
    ~DtSuscripcion();

//Getters
  string getnombreVJ();
  DtFechaHora* getFecha();
  float getCosto();
  TipoPago getTipoPago();
  TipoEstado getEstado();
  TipoPeriodo getPeriodo();
  };

#endif
