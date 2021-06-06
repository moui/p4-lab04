#ifndef PARTIDAMULTIJUGADOR
#define PARTIDAMULTIJUGADOR

#include "Partida.h"
#include <string>

class PartidaMultijugador : public Partida
{
  private:
    bool transmitidaEnVivo;
    set<InfoPartiddaJugador*> unen;
    int unidos;
    set<Comentario*> chat;
    
  public:

    PartidaMultijugador(DtFechaHora, bool, bool, Jugador *, Videojuego *, Jugador **, int);
    //~PartidaMultijugador();

    float darTotalHorasParticipantes();
//getters
    set<infoPartidaJugador> getUnen();
    bool getEnVivo();
    int getUnidos();
    std::string* getNicknames();
    DtFechaHora* getHoraAbandono();
    set<Comentario*> getComentarios();


//setters
    void setEnVivo(bool);
    void setUnidos(int);
    void setNicknames(Jugadores*);
    void setHoraAbandono();
    void comentar(std::string);

};
#endif
