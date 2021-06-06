#include "../../lib/datatypes/DtVideojuego.h"

DtVideojuego::DtVideojuego(std::string nombre, float totalHoras)
{
  this->nombre = nombre;
  this->totalHorasDeJuego = totalHoras;
  return;
}

std::string DtVideojuego::getn()
{
  return this->nombre;
}

float DtVideojuego::getthj()
{
  return this->totalHorasDeJuego;
}
