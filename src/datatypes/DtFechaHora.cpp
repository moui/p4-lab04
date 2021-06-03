#include "../../lib/datatypes/DtFechaHora.h"
#include <stdexcept>

DtFechaHora::DtFechaHora()
{
  this->dia = this->mes = this->ano = 0;
  this->hora = this->minuto = 0;
  return;
}

DtFechaHora::DtFechaHora(int dia, int mes, int ano, int hora, int minuto)
{
  try
  {
    if (dia < 1 || dia > 31 || mes < 1 || mes > 12 || ano < 1900)
      throw std::invalid_argument("Parametros invalidos.");
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
    this->hora = hora;
    this->minuto = minuto;
    return;
  }
  catch (const std::exception& e)
  {
    this->dia = this->mes = this->ano = 0;
    this->hora = this->minuto = 0;
    return;
  }
}

int DtFechaHora::getd()
{
  return this->dia;
}

int DtFechaHora::getmes()
{
  return this->mes;
}

int DtFechaHora::geta()
{
  return this->ano;
}

int DtFechaHora::geth()
{
  return this->hora;
}

int DtFechaHora::getm()
{
  return this->minuto;
}
