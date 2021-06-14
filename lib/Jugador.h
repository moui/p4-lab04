#ifndef JUGADOR
#define JUGADOR

#include <string>
#include <map>
#include <set>

#include "InfoPartidaMulti.h"
#include "Usuario.h"
#include "Partida.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "Suscripcion.h"
#include "datatypes/TipoPeriodo.h"
#include "datatypes/DtPartida.h"
#include "datatypes/DtSuscripcion.h"
#include "datatypes/DtJugador.h"
#include "datatypes/DtPartidaIndividual.h"
#include "datatypes/DtPartidaMultijugador.h"
#include "datatypes/DtVideojuegoSuscripcion.h"

using namespace std;

class InfoPartidaMulti;

class Jugador : public Usuario
{
  private:
    string nickname;
    string descripcion;
    map<int,Partida*> inicio;

  public:
    // Constructor y destructor
    Jugador(string email, string contrasena, string nickname, string descripcion);

    map<float, InfoPartidaMulti*> unen;

    set<Suscripcion*> suscripto;

    set<Jugador*> sigue;

    ~Jugador();
    void finPartida(float id);
    set<DtPartida*> partidasIniciadasSinFinalizar();
    void iniciadaP(Partida* p);
    bool estaSuscritoA(std::string NombreVJ);
    set<DtPartidaIndividual*> partidasIndividualesFinalizadas();
    set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesActivas(map<string, DtVideojuegoSuscripcion*> Dcatalogo);
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

    void mostrarUsuario();
};

#endif
