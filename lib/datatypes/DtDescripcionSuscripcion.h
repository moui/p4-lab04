#ifndef DT_DESCRIPCIONSUSCRIPCION
#define DT_DESCRIPCIONSUSCRIPCION

#include <string>
#include "TipoPeriodo.h"
#include "TipoEstado.h"
#include "DtFechaHora.h"

using namespace std;


class DtDescripcionSuscripcion{
  private:
    string nombre;
    float costo;
    TipoPeriodo periodo;
  public:
    DtDescripcionSuscripcion(string nom, float costo, TipoPeriodo p);
    ~DtDescripcionSuscripcion();

//Getters
    string getNombre();
    float getCosto();
    TipoPago getPeriodo();
  };

#endif
