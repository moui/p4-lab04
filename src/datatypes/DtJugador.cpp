#include "../../lib/datatypes/DtJugador.h"

DtJugador::DtJugador(string email, string nickname, string descripcion)
  : DtUsuario::DtUsuario(email)
{
  this->nickname = nickname;
  this->descripcion = descripcion;
}

// Constructor y destructor
DtJugador::~DtJugador()
{
}

// Funcion pura de DtJugador
void DtJugador::abstracta() {}

// Getters
string DtJugador::getNickname()
{
  return nickname;
}

string DtJugador::getDescripcion()
{
  return descripcion;
}