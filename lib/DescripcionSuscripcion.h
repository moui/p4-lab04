#ifndef DESCRIPCIONSUSCRIPCION
#define DESCRIPCIONSUSCRIPCION

#include <string>
#include "DescripcionSuscripcion.h"
#include "Suscripcion.h"
#include "datatypes/TipoPeriodo.h"

#include <string>
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
  TipoPago getPeriodo();
  set<Suscripcion*> getSuscripciones();

//Setters
void setNombre(string n);
void setCosto(float c);
void setTipoPeriodo(TipoPeriodo p);
void setSuscripcion(Suscripcion* s);

};

#endif
