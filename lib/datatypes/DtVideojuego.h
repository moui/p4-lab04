#ifndef DT_VIDEOJUEGO
#define DT_VIDEOJUEGO

#include <string>

class DtVideojuego
{
  private:
    std::string nombre;
    float totalHorasDeJuego;

  public:
    DtVideojuego();
    DtVideojuego(std::string, float);
    std::string getn();
    float getthj();
};

#endif
