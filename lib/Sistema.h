#ifndef SISTEMA
#define SISTEMA

#include "Jugador.h"
#include "PartidaIndividual.h"
#include "PartidaMultijugador.h"
#include "Videojuego.h"
#include "datatypes/TipoJuego.h"
#include "datatypes/DtJugador.h"
#include "datatypes/DtFechaHora.h"
#include "datatypes/DtVideojuego.h"
#include "datatypes/DtPartidaIndividual.h"
#include "datatypes/DtPartidaMultijugador.h"

#include <stdexcept>

using namespace std;

const int MAX_JUGADORES=100;
const int MAX_VIDEOJUEGOS=100;
const int MAX_PARTIDAS=100;

class Sistema
{
    private:
        Jugador** arregloJugadores;
        Videojuego** arregloVideojuego;

        Partida** arregloPartidas;

    public:
        Sistema();
        ~Sistema();

        void agregarJugador(string, int, string);
        void agregarVideojuego(string, TipoJuego);

        DtJugador **obtenerJugadores(int&);
        DtVideojuego **obtenerVideojuegos(int&);
        DtPartida **obtenerPartidas(string, int&);

        void iniciarPartida(string, string, DtPartida*);

};

#endif
