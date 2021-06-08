#ifndef JUGADOR
#define JUGADOR

#include <string>
#include <map>

#include "InfoPartidaMulti.h"
#include "Usuario.h"
#include "Partida.h"
#include "Suscripcion.h"
#include "datatypes/TipoPeriodo.h"
#include "datatypes/DtPartida.h"
#include "datatypes/DtSuscripcion.h"
#include "datatypes/DtJugador.h"

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

    map<float, InfoPartidaMulti*> unen;
    set<Suscripcion*> suscripto;
    set<Jugador*> sigue;

    ~Jugador();
    void finPartida(float id);
    set<DtPartida*> partidasInSF();
    void iniciadaP(Partida p);
    bool estaSuscritoA(std::string NombreVJ);
    set<DtPartidaIndividual*> partidasIndF();
    set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesActivas();
    void AltaSuscripcion();
    void CancelarSuscripcion(std::string NombreVJ);

    // Getters
    string getNickname();
    string getDescripcion();
    map<int, Partida*> getInicioPartidas();
    map<float, InfoPartidaMulti*> getPartidasMultijugador();
    set<DtJugador*> getSeguidos;
    set<DtSuscripcion*> getSusAdquiridas;


    // Setters
    void setNickname(string nickname);
    void setDescripcion(string descripcion);

    void setInicioPartidas(map<int,Partida*> inicio);

    void setPartidaMultijugador(InfoPartidaMulti partidasMultijugador);
    void setSuscripcion(Suscripcion* s);
    void seguir(Jugador* j);

};

#endif
