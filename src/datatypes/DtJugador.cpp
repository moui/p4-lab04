#include "../../lib/datatypes/DtJugador.h"

DtJugador::DtJugador(std::string nickname, int edad)
{
  this->nickname = nickname;
  this->edad = edad;
  return;
}

std::string DtJugador::getnick()
{
  return this->nickname;
}

int DtJugador::gete()
{
  return this->edad;
}
