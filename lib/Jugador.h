#ifndef JUGADOR
#define JUGADOR

#include <string>
#include <set>
#include "Usuario.h"

class Partida;
class PartidaMultijugador;

using namespace std;

class Jugador : public Usuario
{
  private:
    string nickname;
    string descripcion;
    set<Partida*> iniciadas;
    set<InfoPartidaJugador*> unen;
    set<Suscripcion*> suscripto;
    set<Jugador*> sigue;

  public:
    Jugador(string, string, string);
    ~Jugador();
    void finPartida(float);
    set<DtPartidas*> partidasInSF();
    void iniciadaP(Partida);
    bool estaSuscritoA(std::string);
    set<DtPartidasIndividuales*> partidasIndF();
    set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesActivas();
    void AltaSuscripcion();
    void CancelarSuscripcion(std::string);

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
