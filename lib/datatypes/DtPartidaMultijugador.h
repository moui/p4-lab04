#ifndef DT_PARTIDAMULTIJUGADOR
#define DT_PARTIDAMULTIJUGADOR

#include "DtPartida.h"
#include <string>
#include <iostream>

class DtPartidaMultijugador : public DtPartida
{
  private:
    bool transmitidaEnVivo;
    std::string* nicknameJugadoresUnidos;
    int cantidadJugadoresUnidos;

  public:
    DtPartidaMultijugador(DtFechaHora ,float ,bool ,std::string* ,int );
    // Getters
    bool getTransmitidaEnVivo();
    std::string* getNicknameJugadoresUnidos();
    int getCantidadJugadoresUnidos();

    friend std::ostream& operator<<(std::ostream& out, const DtPartidaMultijugador& dt);

};

#endif
