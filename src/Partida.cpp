#include "../lib/Partida.h"

// Constructor y destructor
Partida::Partida(int id, float duracion, bool finalizada, DtFechaHora* fecha, Videojuego* videojuego)
{
  this->identificador = id;
  this->fecha = fecha;
  this->finalizada = finalizada;
  this->duracion = duracion;
  this->tiene = videojuego;
  return;
}

Partida::~Partida()
{
}

// Getters
int Partida::getId()
{
  return this->identificador;
}

float Partida::getDuracion()
{
  return this->duracion;
}

DtFechaHora* Partida::getFecha()
{
  return this->fecha;
}

bool Partida::getFinalizada()
{
  return this->finalizada;
}

Videojuego* Partida::getVideojuego()
{
  return this->tiene;
}

// Setters
void Partida::setId(int id)
{
  this->identificador = id;
}

void Partida::setFecha(DtFechaHora* fecha)
{
  this->fecha = fecha;
}

void Partida::setDuracion(float duracion)
{
  this->duracion = duracion;
}

void Partida::setFinalizada(bool finalizada)
{
  this->finalizada = finalizada;
}

void Partida::setVideojuego(Videojuego *videojuego)
{
  this->tiene = videojuego;
}
