#ifndef JUGADOR
#define JUGADOR

#include <string>
#include <map>

#include "Usuario.h"
#include "Partida.h"

using namespace std;

class Jugador : public Usuario
{
  private:
    string nickname;
    string descripcion;
    map<int,Partida*> inicio;

  public:
    // Constructor y destructor
    Jugador(string email, string contrasena, string nickname, string descripcion, map<int,Partida*> inicio);

    map<float, InfoPartidaJugador*> unen;
    set<Suscripcion*> suscripto;
    set<Jugador*> sigue;

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
    string getDescripcion();
    map<int, Partida*> getInicioPartidas();
    map<float, InfoPartidaJugador*> getPartidasMultijugador();
    set<DtJugadores*> getSeguidos;
    set<Suscripciones*> getSusAdquiridas;


    // Setters
    void setNickname(string nickname);
    void setDescripcion(string descripcion);

    void setInicioPartidas(map<int,Partida*> inicio);

    void setPartidaMultijugador(InfoPartidaJugador partidasMultijugador);
    void setSuscripcion(Suscripcion* s);
    void seguir(Jugador* j);

};

#endif
