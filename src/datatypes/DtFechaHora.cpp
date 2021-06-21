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

DtFechaHora::DtFechaHora(DtFechaHora* fecha)
{
  this->dia = fecha->getDia();
  this->mes = fecha->getMes();
  this->ano = fecha->getAno();
  this->hora = fecha->getHora();
  this->minuto = fecha->getMinuto();
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

float DtFechaHora::Meses(DtFechaHora* fechaFin, DtFechaHora* fechaInicio)
{
    tm fechaFin_tm, fechaInicio_tm;

    fechaFin_tm.tm_year = fechaFin->getAno() - 1900;
    fechaFin_tm.tm_mon = fechaFin->getMes() - 1;
    fechaFin_tm.tm_mday = fechaFin->getDia();
    fechaFin_tm.tm_hour = fechaFin->getHora();
    fechaFin_tm.tm_min = fechaFin->getMinuto();
    fechaFin_tm.tm_sec = 0;
    fechaFin_tm.tm_isdst = -1;

    fechaInicio_tm.tm_year = fechaInicio->getAno()- 1900;
    fechaInicio_tm.tm_mon = fechaInicio->getMes() - 1;
    fechaInicio_tm.tm_mday = fechaInicio->getDia();
    fechaInicio_tm.tm_hour = fechaInicio->getHora();
    fechaInicio_tm.tm_min = fechaInicio->getMinuto();
    fechaInicio_tm.tm_sec = 0;
    fechaInicio_tm.tm_isdst = -1;

    time_t fechaFin__time_t = mktime(&fechaFin_tm);
    time_t fechaInicio__time_t = mktime(&fechaInicio_tm);

    if (fechaFin__time_t != (time_t)(-1) && fechaInicio__time_t != (time_t)(-1))
    {
        double dias = difftime(fechaFin__time_t, fechaInicio__time_t) / (60*60*24);
        return (float)dias / (30.417);
    }
    else
        throw invalid_argument("Error al calcular meses");
}

float DtFechaHora::Dias(DtFechaHora* fechaFin, DtFechaHora* fechaInicio)
{
    tm fechaFin_tm, fechaInicio_tm;

    fechaFin_tm.tm_year = fechaFin->getAno() - 1900;
    fechaFin_tm.tm_mon = fechaFin->getMes() - 1;
    fechaFin_tm.tm_mday = fechaFin->getDia();
    fechaFin_tm.tm_hour = fechaFin->getHora();
    fechaFin_tm.tm_min = fechaFin->getMinuto();
    fechaFin_tm.tm_sec = 0;
    fechaFin_tm.tm_isdst = -1;

    fechaInicio_tm.tm_year = fechaInicio->getAno()- 1900;
    fechaInicio_tm.tm_mon = fechaInicio->getMes() - 1;
    fechaInicio_tm.tm_mday = fechaInicio->getDia();
    fechaInicio_tm.tm_hour = fechaInicio->getHora();
    fechaInicio_tm.tm_min = fechaInicio->getMinuto();
    fechaInicio_tm.tm_sec = 0;
    fechaInicio_tm.tm_isdst = -1;

    time_t fechaFin__time_t = mktime(&fechaFin_tm);
    time_t fechaInicio__time_t = mktime(&fechaInicio_tm);

    if (fechaFin__time_t != (time_t)(-1) && fechaInicio__time_t != (time_t)(-1))
    {
        double dias = difftime(fechaFin__time_t, fechaInicio__time_t) / (60*60*24);
        return (float)dias;
    }
    else
        throw invalid_argument("Error al calcular meses");
}