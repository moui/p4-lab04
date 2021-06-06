#ifndef JUGADOR
#define JUGADOR

#include <string>
#include "Usuario.h"

class Partida;
class PartidaMultijugador;

using namespace std;

class Jugador : public Usuario
{
  private:
    string nickname;
    set<Partida*> iniciadas;
    set<InfoPartidaJugador*> unen;
    set<Suscripcion*> suscripto;
    set<Jugador*> sigue;

  public:
    Jugador(string, string, string, int, Partida** , PartidaMultijugador** );
    ~Jugador();

    // Getters
    string getNickname();
    set<Partida*> getPartidasIniciadas();
    set<InfoPartidaJugador*> getPartidasMultijugador();
    set<DtJugadores*> getSeguidos;
    set<Suscripciones*> getSusAdquiridas;

    // Setters
    void setNickname(string nickname);
    void setPartidasIniciadas(Partida** iniciadas);
    void setPartidasMultijugador(PartidaMultijugador** partidasMultijugador);
    void setSuscripcion(Suscripcion*);
    void seguir(Jugador*);

};

#endif
