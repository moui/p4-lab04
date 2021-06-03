#ifndef PARTIDAMULTIJUGADOR
#define PARTIDAMULTIJUGADOR

#include "Partida.h"
#include <string>

class PartidaMultijugador : public Partida
{
  private:
    std::string* nicknameJ;
    bool transmitidaEnVivo;
    Jugador **unen;
    int unidos;
  public:

    PartidaMultijugador(DtFechaHora , float, bool, Jugador *, Videojuego *, Jugador **, std::string*, int);
    //~PartidaMultijugador();

    float darTotalHorasParticipantes();
//getters
    Jugador** getUnen();
    bool getEnVivo();
    int getUnidos();
    std::string* getNicknames();


//setters
    void setEnVivo(bool);
    void setUnidos(int);
    void setNicknames(std::string*);

};
#endif
