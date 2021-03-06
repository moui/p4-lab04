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
#include "datatypes/TipoPago.h"
#include "datatypes/TipoEstado.h"
#include "datatypes/TipoPeriodo.h"
#include "datatypes/DtPartidaIndividual.h"
#include "datatypes/DtPartidaMultijugador.h"
#include "datatypes/DtDescripcionSuscripcion.h"
#include "datatypes/DtVideojuegoSuscripcion.h"
#include "datatypes/DtFechaHora.h"
#include "helpers/FechaSistema.h"
#include "controllers/CtrlUsuario.h"
#include "controllers/CtrlVideojuego.h"
#include "controllers/CtrlPartida.h"

using namespace std;

class InfoPartidaMulti;

class Jugador : public Usuario
{
  private:
    string nickname;
    string descripcion;
    map<int,Partida*> inicio;
    set<Suscripcion*> suscripto;
    set<Jugador*> sigue;

  public:
    // Constructor y destructor
    Jugador(string email, string contrasena, string nickname, string descripcion);

    ~Jugador();

    void abstracta() {}

    // Getters
    string getNickname();
    string getDescripcion();
    map<int, Partida*> getInicioPartidas();

    // Setters
    void setNickname(string nickname);
    void setDescripcion(string descripcion);
    void agregarPartida(int id, Partida* partida);

    void seguir(Jugador* j);

    // Caso de uso Suscribirse a videojuego
    Suscripcion* getSuscripcion(string nomVJ);
    DtSuscripcion* getDatosSuscripcion(string nomVJ);
    void CancelarSuscripcion(string nomVJ);
    void AltaSuscripcion(DtSuscripcion* dtSus);
    map<string, DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesActivas();

    //ABANDONA PARTIDA MJ
    set<DtPartidaMultijugador*> listarPartidasMultijugadorUnidas();

    void removerSuscripcion(string);

    //FINALIZAR PARTIDA

    set<DtPartida*> listaPartidasIniciadasSinFinalizar();
};
#endif
