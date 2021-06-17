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

void Desarrollador::mostrarUsuario(){ cout << "des"; }


void Desarrollador::agregarEstadistica(int stat)
{
  switch(stat)
  {
    case 1:
    {
      IEstadistica* thj= new TotalHorasJuego("Total Horas de Juego", 0, "Calcula el total de horas de juego, en todas las partidas para un juego determinado.");
      seleccionadas.insert(thj);
      break;
    }
    case 2:
    {
      IEstadistica* tjs= new TotalJugadoresSuscritos("Total Jugadores Suscritos", 0, "Calcula el total de jugadores suscritos a determinado. ");
      seleccionadas.insert(tjs);
      break;
    }
    default: throw invalid_argument("No existe estadistica cargada en el sistema. ");
    break;
  }
  
}