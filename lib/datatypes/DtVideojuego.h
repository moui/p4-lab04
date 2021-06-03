#ifndef DT_VIDEOJUEGO
#define DT_VIDEOJUEGO

#include "TipoJuego.h"
#include <string>

class DtVideojuego
{
  private:
    std::string nombre;
    TipoJuego genero;
    float totalHorasDeJuego;

  public:
    DtVideojuego(std::string, TipoJuego, float);
    std::string getn();
    TipoJuego getg();
    float getthj();
};

#endif
