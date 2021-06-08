#ifndef DT_SUSCRIPCION
#define DT_SUSCRIPCION

#include <string>
#include "TipoPago.h"
#include "TipoEstado.h"
#include "DtFechahora.h"

using namespace std;


class DtSuscripcion{
  private:
    string nombreVJ;
    TipoFecha fecha;
    float costo;
    TipoPago pago;
    TipoEstado estado;
  public:
    DtSuscripcion(string nomVJ, TipoFecha f, float costo, TipoPago p, TipoEstado e);
    ~DtSuscripcion();

//Getters
  string getnombreVJ();
  TipoFecha getFecha();
  float getCosto();
  TipoPago getTipoPago();
  TipoEstado getEstado();
  };

#endif
