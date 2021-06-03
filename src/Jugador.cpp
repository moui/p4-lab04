#include "../lib/Jugador.h"

Jugador::Jugador(string nickname, string contrasena, int edad, Partida** iniciada, PartidaMultijugador** unen)
{
  this->nickname = nickname;
  this->contrasena = contrasena;
  this->edad = edad;
  this->iniciada = iniciada;
  this->unen = unen;
  return;
}

// Getters
string Jugador::getNickname()
{
  return this->nickname;
}

string Jugador::getContrasena()
{
  return this->contrasena;
}

int Jugador::getEdad()
{
  return this->edad;
}

Partida** Jugador::getPartidasIniciadas()
{
  return this->iniciada;
}

PartidaMultijugador** Jugador::getPartidasMultijugador()
{
  return this->unen;
}

// Setters
void Jugador::setNickname(string nickname)
{
  this->nickname = nickname;
}

void Jugador::setContrasena(string contrasena)
{
  this->contrasena = contrasena;
}

void Jugador::setEdad(int edad)
{
  this->edad = edad;
}

void Jugador::setPartidasIniciadas(Partida** iniciadas)
{
  this->iniciada = iniciadas;
}

void Jugador::setPartidasMultijugador(PartidaMultijugador** partidasMultijugador)
{
  this->unen = partidasMultijugador;
}

Jugador::~Jugador()
{
  delete[] this->iniciada;
  delete[] this->unen;
}