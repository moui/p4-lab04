#include "../../lib/datatypes/DtVideojuego.h"

DtVideojuego::DtVideojuego(std::string nombre, TipoJuego genero, float totalHoras)
{
  this->nombre = nombre;
  this->genero = genero;
  this->totalHorasDeJuego = totalHoras;
  return;
}

std::string DtVideojuego::getn()
{
  return this->nombre;
}

TipoJuego DtVideojuego::getg()
{
  return this->genero;
}

float DtVideojuego::getthj()
{
  return this->totalHorasDeJuego;
}
