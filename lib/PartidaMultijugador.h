#ifndef PARTIDAMULTIJUGADOR
#define PARTIDAMULTIJUGADOR

#include "Partida.h"
#include <string>

class PartidaMultijugador : public Partida
{
  private:
    bool transmitidaEnVivo;
    set <InfoPartiddaJugador*> unen;
    int unidos;
    set <Comentario*> chat;
    
  public:

    PartidaMultijugador(DtFechaHora , float, bool, Jugador *, Videojuego *, Jugador **, std::string*, int);
    //~PartidaMultijugador();

    float darTotalHorasParticipantes();
//getters
    Jugador** getUnen();
    bool getEnVivo();
    int getUnidos();
    std::string* getNicknames();
    DtFechaHora* getHoraAbandono();
    Comentario* getComentario();


//setters
    void setEnVivo(bool);
    void setUnidos(int);
    void setNicknames(Jugadores*);
    void setHoraAbandono();
    void comentar();

};
#endif
