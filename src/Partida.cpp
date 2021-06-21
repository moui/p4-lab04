#include "../lib/Partida.h"

// Constructor y destructor
Partida::Partida(int id, float duracion, bool finalizada, DtFechaHora* fecha, DtFechaHora* fecha_fin, Videojuego* videojuego)
{
  this->identificador = id;
  this->fecha = fecha;
  this->fecha_fin = fecha_fin;
  this->finalizada = finalizada;
  this->duracion = duracion;
  this->tiene = videojuego;
  return;
}

Partida::~Partida()
{
  if (fecha != NULL)
    delete fecha;
  
  if (fecha_fin != NULL)
    delete fecha_fin; 
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

DtFechaHora* Partida::getFechaFin()
{
  return this->fecha_fin;
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

void Partida::setFechaFin(DtFechaHora* fecha_fin)
{
  this->fecha_fin = fecha_fin;
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
