#include "../../lib/datatypes/DtPartidaMultijugador.h"
#include "../../lib/datatypes/DtFechaHora.h"

// Constructor.
DtPartidaMultijugador::DtPartidaMultijugador(float id, float duracion, DtFechaHora fecha, string n,
    bool enVivo, set<string> jugadoresUnidos, int cantidadUnidos): DtPartida::DtPartida(id, duracion, fecha, nomVJ)
{
    transmitidaEnVivo = enVivo;
    nicknameJugadoresUnidos = jugadoresUnidos;
    cantidadJugadoresUnidos = cantidadUnidos;
}

// Destructor
DtPartidaMultijugador::~DtPartidaMultijugador()
{
  //  delete nicknameJugadoresUnidos; no es la manera de vaciar un set
}

// Implementacion funcion pura de DtPartida
void DtPartidaMultijugador::abstracta() {}

// Getters
bool DtPartidaMultijugador::getTransmitidaEnVivo()
{
    return transmitidaEnVivo;
}

set<string> DtPartidaMultijugador::getNicknameJugadoresUnidos()
{
    return nicknameJugadoresUnidos;
}

int DtPartidaMultijugador::getCantidadJugadoresUnidos()
{
    return cantidadJugadoresUnidos;
}

// Sobrecarga del operador de insercion <<
std::ostream& operator<<(std::ostream& os, const DtPartidaMultijugador& dtPartidaMulti)
{
    os << "Tipo partida: Multijugador" << endl;
    os << "ID partida: " << static_cast<float>(dtPartidaMulti.identificador) << endl;
    os << "Fecha partida: " << dtPartidaMulti.fecha << endl;
    os << "Duracion partida: " << static_cast<int>(dtPartidaMulti.duracion) << " hs" << endl;
    if (dtPartidaMulti.transmitidaEnVivo)
        os << "Transmitida en vivo: Si" << endl;
    else
        os << "Transmitida en vivo: No" << endl;
    os << "Cantidad de jugadores unidos a la partida: " << dtPartidaMulti.cantidadJugadoresUnidos << endl;
    os << "Jugadores unidos a la partida: ";
    for (int i = 0; i < dtPartidaMulti.cantidadJugadoresUnidos; i++)
    {
     //   os << dtPartidaMulti.nicknameJugadoresUnidos[i] << " "; no es la manera de usar set
    }
    os << endl;
    return os;
}
