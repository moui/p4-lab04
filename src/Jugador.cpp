#include "../lib/Jugador.h"

// Constructor y destructor
Jugador::Jugador(string email, string contrasena, string nickname, string descripcion): Usuario(email, contrasena)
{
    this->nickname = nickname;
    this->descripcion = descripcion;
    return;
}

Jugador::~Jugador()
{
    // Determinar como se va a destruir el map<float, Partida>
    for (auto it = suscripto.begin(); it != suscripto.end(); ++it)
    { 
        if (*it != NULL)
            delete *it;
    }
}

// Getters
string Jugador::getNickname()
{
  return this->nickname;
}

string Jugador::getDescripcion()
{
  return this->descripcion;
}

map<float, Partida*> Jugador::getInicioPartidas()
{
  return this->inicio;
}

// Setters
void Jugador::setNickname(string nickname)
{
  this->nickname = nickname;
}

void Jugador::setDescripcion(string descripcion)
{
  this->descripcion = descripcion;
}

void Jugador::setInicioPartidas(map<float,Partida*> inicio)
{
  this->inicio = inicio;
}

void Jugador::seguir(Jugador* j)
{
  /* sigue->insert(j); */
}

// BEGIN: OPERACIONES SUSCRIBIRSE A VJ

Suscripcion* Jugador::getSuscripcion(string nomVJ)
{
    set<Suscripcion*>::iterator it = suscripto.begin();
    Suscripcion* res = NULL;
    while (it != suscripto.end()) 
    {
        Suscripcion* s= *it;
	    if (s->getnombreVJ() == nomVJ)
        {
		    res = s;
            break;
	    }
	++it;
    }
    return res;
}

DtSuscripcion* Jugador::getDatosSuscripcion(string nomVJ)
{
    DtSuscripcion* res = NULL;
    Suscripcion* s = this->getSuscripcion(nomVJ);

    if (s != NULL)
    {
        // Datos
        string n = s->getnombreVJ();
        DtFechaHora* f= s->getFecha();
        float c = s->getCosto();
        TipoPago tp = s->getTipoPago();
        TipoEstado te = s->getEstado();
        TipoPeriodo pe = s->getPeriodo();

        res = new DtSuscripcion(n, f, c, tp, te, pe);
    }
    return res;
}

void Jugador::CancelarSuscripcion(string nomVJ) //se repite codigo para no recorrer dos veces la coleccion
{
    set<Suscripcion*>::iterator it = suscripto.begin();
    Suscripcion* res = NULL;
    while (it != suscripto.end()) 
    {
        Suscripcion* s= *it;
	    if (s->getnombreVJ() == nomVJ){
		    res=s;
        break;
	    }
	    ++it;
    }
    if (res == NULL)
    { //Para identificar si se llama incorrectamente la funcion
      throw invalid_argument( "No existe suscripcion. " );
    }
    else 
    {
      res->setCancelada(true);
    }
}

map<string, DtVideojuegoSuscripcion*> Jugador::listarVideojuegoSuscripcionesActivas()
{
    CtrlVideojuego* ctrlVideojuego = CtrlVideojuego::getCtrlVideojuego();

    map<string, DtVideojuegoSuscripcion*> suscripcionesActivas;

    for (auto it = suscripto.begin(); it != suscripto.end(); ++it)
    {
        Suscripcion* suscripcion = *it;
        if (suscripcion->getEstado() == TipoEstado::activa)
        {
            // Agregar descripcion suscripcion al set
            string nombreVideojuego = suscripcion->getnombreVJ();
            suscripcionesActivas.insert(pair<string, DtVideojuegoSuscripcion*>(
                nombreVideojuego, ctrlVideojuego->getDataSuscripciones(nombreVideojuego))
                );
        }
    }
    
    return suscripcionesActivas;
}

void Jugador::AltaSuscripcion(DtSuscripcion* dtSus)
{
    suscripto.insert(new Suscripcion(dtSus->getnombreVJ(), dtSus->getFecha(), 
        dtSus->getCosto(), dtSus->getTipoPago(), dtSus->getPeriodo(), false));
}


  //ABANDONA PARTIDA MJ
  set<DtPartidaMultijugador*> Jugador::listarPartidasMultijugadorUnidas()
  {
    set<DtPartidaMultijugador*> res;
    CtrlPartida* ctrlpartida;
    ctrlpartida = CtrlPartida::getCtrlPartida();
    CtrlUsuario* ctrlUsuario;
    ctrlUsuario = CtrlUsuario::getInstancia();
    Usuario* user= ctrlUsuario->getSesionActiva();
    Jugador * jugador={dynamic_cast<Jugador*>(user)};

    res= ctrlpartida->listarPartidasMultijugadorUnidas(jugador->getMail());

    return res;

  }

void Jugador::removerSuscripcion(string nombrevj){
  for (auto it = suscripto.begin(); it != suscripto.end(); ++it){ 
    if ( (*it)->getnombreVJ() == nombrevj ){
      suscripto.erase(*it);
      delete *it;
    }
  }
}