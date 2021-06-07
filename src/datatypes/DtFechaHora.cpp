#include "../../lib/datatypes/DtFechaHora.h"

DtFechaHora::DtFechaHora()
{
  this->dia = this->mes = this->ano = 0;
  this->hora = this->minuto = 0;
  return;
}

DtFechaHora::DtFechaHora(int dia, int mes, int ano)
{
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
    this->hora = 0;
    this->minuto = 0;
    return;
}

DtFechaHora::DtFechaHora(int dia, int mes, int ano, int hora, int minuto)
{
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
    this->hora = hora;
    this->minuto = minuto;
    return;
}

DtFechaHora::~DtFechaHora()
{
  
}

// Getters
int DtFechaHora::getDia()
{
  return dia;
}

int DtFechaHora::getMes()
{
  return mes;
}

int DtFechaHora::getAno()
{
  return ano;
}

int DtFechaHora::getHora()
{
  return hora;
}

int DtFechaHora::getMinuto()
{
  return minuto;
}

// Sobrecarga del operador de insercion <<
std::ostream& operator<<(std::ostream& os, const DtFechaHora& dtFecha)
{
  os  << std::setfill('0') << std::setw(2) << dtFecha.dia << "/" 
      << std::setfill('0') << std::setw(2) << dtFecha.mes << "/" 
      << dtFecha.ano << " @ " 
      << std::setfill('0') << std::setw(2) << dtFecha.hora << ":" 
      << std::setfill('0') << std::setw(2) << dtFecha.minuto << std::endl;
  return os;
}
