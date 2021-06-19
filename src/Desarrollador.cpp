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

void Desarrollador::publicarVJ(Videojuego* videojuego)
{
  publicados.insert(videojuego);
}

//seleccionar estadistica

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

Videojuego* Desarrollador::getVideojuego(string nomVJ)
{
    Videojuego* res=NULL;
    if(publicados.empty())
    {
      throw invalid_argument("Videjuegos publicados vacio. \n");
    }
    for(set<Videojuego*>::iterator i=publicados.begin(); i!=publicados.end(); i++)
    {
      if ((*i)->getNombreVJ()==nomVJ)
      {
        res=(*i);
      }
    }
    if(res==NULL)
    {
      throw invalid_argument("no se obtuvo el videojuego. ");
    }
    return res;
}

//CONSULTAR ESTADISTICA

set<string> Desarrollador::listarVideojuegosPublicados()
{
    set<string> res;
    if (publicados.empty())
    {
      throw invalid_argument("No hay videojuegos publicados para ese desarrollador. ");
    }
    for(set<Videojuego*>::iterator i=publicados.begin(); i!=publicados.end(); i++) 
    {
      res.insert((*i)->getNombreVJ());
    }
    return res;
}


set<DtEstadistica*> Desarrollador::CalcularEstadisticas(string nomVJ)
{
    set<DtEstadistica*> res;

      CtrlUsuario* ctrlusuario = CtrlUsuario::getInstancia();
      Usuario* user= ctrlusuario->getSesionActiva();
      Desarrollador * desarrollador={dynamic_cast<Desarrollador*>(user)};
      Videojuego* v= desarrollador->getVideojuego(nomVJ);

      for(set<IEstadistica*>::iterator i= seleccionadas.begin(); i!=seleccionadas.end(); i++)
      {
        res.insert((*i)->calcular(v));
      }
      if (res.empty())
      {
        throw invalid_argument("No se obtuvieron datos de estadisticas.");
      }
        return res;
}