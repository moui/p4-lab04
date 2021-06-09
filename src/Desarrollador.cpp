#include "../lib/Desarrollador.h"

// Constructor y destructor

Desarrollador::Desarrollador(string email, string contrasena, string empresa): Usuario(email, contrasena)
{
  this->empresa = empresa;
  return;
}

Desarrollador::~Desarrollador()
{
  // Determinar como se va a destruir el map<int, Partida>
}

// Getters
string Desarrollador::getEmpresa()
{
  return this->empresa;
}

// Setters
void Desarrollador::setEmpresa(string empresa)
{
  this->empresa = empresa;
}
