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
    map<float, Partida*> iniciadas;
    map<float, InfoPartidaJugador*> unen;
    set<Suscripcion*> suscripto;
    set<Jugador*> sigue;

  public:
    Jugador(string nickname, string descripcion, map<float, Partida*> iniciadas, map<float, InfoPartidaJugador*> unen, set<Suscripcion*> suscripto, set<Jugador*> sigue);
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
    map<float, Partida*> getPartidasIniciadas();
    map<float, InfoPartidaJugador*> getPartidasMultijugador();
    set<DtJugadores*> getSeguidos;
    set<Suscripciones*> getSusAdquiridas;

    // Setters
    void setNickname(string nickname);
    void setDescripcion(string descripcion);
    void setPartidasIniciadas(map<float, Partida*> iniciadas);
    void setPartidaMultijugador(InfoPartidaJugador partidasMultijugador);
    void setSuscripcion(Suscripcion*);
    void seguir(Jugador*);

};

#endif
