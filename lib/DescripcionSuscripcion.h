#ifndef DESCRIPCIONSUSCRIPCION
#define DESCRIPCIONSUSCRIPCION

#include <string>
#include "datatypes/DtFechaHora.h"
#include "DescripcionSuscripcion.h"
#include "Suscripcion.h"
#include "datatypes/TipoPeriodo.h"
#include "datatypes/TipoPago.h"

#include <string>
#include <set>
#include <map>

using namespace std;

class Suscripcion;

class DescripcionSuscripcion{
  private:
    string nombre;
    float costo;
    TipoPeriodo periodo;

    set<Suscripcion*> suscripciones;

  public:

    DescripcionSuscripcion(string nom, float costo, TipoPeriodo p);
    ~DescripcionSuscripcion();

//Getters
  string getNombre();
  float getCosto();
  TipoPeriodo getPeriodo();
  set<Suscripcion*> getSuscripciones();

//Setters
void setNombre(string n);
void setCosto(float c);
void setTipoPeriodo(TipoPeriodo p);
void setSuscripcion(Suscripcion* s);

};

#endif
