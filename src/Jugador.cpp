#include "../lib/Jugador.h"

// Constructor y destructor

Jugador::Jugador(string email, string contrasena, string nickname, string descripcion, map<int, Partida> inicio)
  : Usuario(email, contrasena)
{
  this->nickname = nickname;
  this->descripcion = descripcion;
  this->inicio = inicio;
  return;
}

Jugador::~Jugador()
{
  // Determinar como se va a destruir el map<int, Partida>
}

// Getters
string Jugador::getNickname()
{
  return this->nickname;
}

string Jugador::getDescripcion()
{
  return this->getDescripcion;
}

map<int, Partida> getInicioPartidas()
{
  return this->inicio;
}

// Setters
void Jugador::setNickname(string nickname)
{
  this->nickname = nickname;
}

void Jugador::setDescripcion(string descripcion)
{
  this->descripcion = descripcion;
}

void Jugador::setPartidasIniciadas(map<int,Partida> inicio)
{
  this->inicio = inicio;
}
