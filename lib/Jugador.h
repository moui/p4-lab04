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
    Jugador(string nickname, string descripcion);
    ~Jugador();
    void finPartida(float id);
    set<DtPartidas*> partidasInSF();
    void iniciadaP(Partida p);
    bool estaSuscritoA(std::string NombreVJ);
    set<DtPartidasIndividuales*> partidasIndF();
    set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesActivas();
    void AltaSuscripcion();
    void CancelarSuscripcion(std::string NombreVJ);

    // Getters
    string getNickname();
    string getDescripciondescripcion();
    set<Partida*> getPartidasIniciadas();
    set<InfoPartidaJugador*> getPartidasMultijugador();
    set<DtJugadores*> getSeguidos;
    set<Suscripciones*> getSusAdquiridas;

    // Setters
    void setNickname(string nickname);
    void setDescripcion(string descripcion);
    void setPartidasIniciadas(set<Partida*> iniciadas);
    void setPartidaIniciada(Partida* iniciada);
    void setPartidaMultijugador(InfoPartidaJugador partidasMultijugador);
    void setSuscripcion(Suscripcion*);
    void seguir(Jugador*);

};

#endif
