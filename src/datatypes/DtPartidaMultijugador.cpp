#include "../../lib/datatypes/DtPartidaMultijugador.h"
#include "../../lib/datatypes/DtFechaHora.h"

DtPartidaMultijugador::DtPartidaMultijugador(DtFechaHora fecha, float duracion, bool transmitida, std::string* jugadores, int cantJugadores):
    DtPartida(fecha, duracion)
{

  this->transmitidaEnVivo = transmitida;
  this->nicknameJugadoresUnidos = jugadores;
  this->cantidadJugadoresUnidos = cantJugadores;
}

// Getters
bool DtPartidaMultijugador::getTransmitidaEnVivo()
{
  return this->transmitidaEnVivo;
}

std::string* DtPartidaMultijugador::getNicknameJugadoresUnidos()
{
  return this->nicknameJugadoresUnidos;
}

int DtPartidaMultijugador::getCantidadJugadoresUnidos()
{
  return this->cantidadJugadoresUnidos;
}

std::ostream& operator<<(std::ostream& out, const DtPartidaMultijugador& dt){

    out << "Tipo de partida: Multijugador.\n";
    out << "Fecha partida: " << dt.getFecha().getd()<< "/" << dt.getFecha().getmes()<<"/"<< dt.getFecha().geta()<<"\n";
    out << dt.getDuracion() << "\n";
    out << "Transmitida en vivo: "<< ((dt.transmitidaEnVivo) ? "Si.\n" : "No.\n");
    out << "Cantidad de jugadores unidos a la partida: " << dt.cantidadJugadoresUnidos << ".\n";
    out << "Jugadores unidos a la partida: ";
    for (int i = 0; i < dt.cantidadJugadoresUnidos; i++) {
      out << dt.nicknameJugadoresUnidos[i] << " ";
    }
    out << std::endl;
    return out;
    }
