#ifndef DT_JUGADOR
#define DT_JUGADOR

#include <string>

class DtJugador
{
  private:
    std::string nickname;
    int edad;

  public:
    DtJugador(std::string ,int );
    std::string getnick();
    int gete();
};

#endif
