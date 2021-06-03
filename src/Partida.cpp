#include "../lib/Partida.h"
#include <cstdlib>

Partida::Partida(DtFechaHora fecha, float duracion, Jugador* jugador, Videojuego* videojuego)
{
  this->fecha = fecha;
  this->duracion = duracion;
  this->tiene = videojuego;
  this->iniciada = jugador;
  return;
}

// Setters
void Partida::setFecha(DtFechaHora fecha)
{
  this->fecha = fecha;
}

void Partida::setDuracion(float duracion)
{
  this->duracion = duracion;
}

void Partida::setJugador(Jugador *jugador)
{
  this->iniciada = jugador;
}

void Partida::setVideojuego(Videojuego *videojuego)
{
  this->tiene = videojuego;
}

// Getters
float Partida::getDuracion()
{
  return this->duracion;
}

DtFechaHora Partida::getFecha()
{
  return this->fecha;
}

Jugador* Partida::getJugador()
{
  return this->iniciada;
}

Videojuego* Partida::getVideojuego()
{
  return this->tiene;
}

Partida::~Partida()
{
}