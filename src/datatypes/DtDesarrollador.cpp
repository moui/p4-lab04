#include "../../lib/datatypes/DtDesarrollador.h"

DtDesarrollador::DtDesarrollador(string email, string empresa)
  : DtUsuario::DtUsuario(email)
{
  this->empresa = empresa;
}

// Constructor y destructor
DtDesarrollador::~DtDesarrollador()
{
}

// Funcion pura de DtJugador
void DtDesarrollador::abstracta() {}

// Getters
string DtDesarrollador::getEmpresa()
{
  return empresa;
}