#ifndef CATEGORIA
#define CATEGORIA

#include "datatypes/TipoCat.h"
#include <string>
#include "datatypes/DtCategoria.h"

using namespace std;

class Categoria
{
  private:
    string nombre;
    string descripcion;
    TipoCat tipo;

  public:
    Categoria(string, string, TipoCat);
    ~Categoria();

    //getters
    string getNombre();
    string getDescripcion();
    TipoCat getTipoCat();

    //setters
    void setNombre(string);
    void setDescripcion(string);
    void setTipoCat(TipoCat);

    DtCategoria getDtCategoria(Categoria cat);
};

#endif