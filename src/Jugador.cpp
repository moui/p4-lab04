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
  // Determinar como se va a destruir el map<int, Partida>
  for (auto it = suscripto.begin(); it != suscripto.end(); ++it)
  {
    if (*it != NULL)
      delete *it;
  }
  suscripto.clear();
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

map<int, Partida*> Jugador::getInicioPartidas()
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

void Jugador::setInicioPartidas(map<int,Partida*> inicio)
{
  this->inicio = inicio;
}

void Jugador::finPartida(float id, DtFechaHora f){
   this->inicio[id]->setFinalizada(true);
   PartidaMultijugador* p = dynamic_cast<PartidaMultijugador*>(this->inicio[id]);
   if(p != NULL){
     p->forzarAbandono(f);
   }
}

void Jugador::seguir(Jugador* j){
  /* sigue->insert(j); */
}

set<DtPartida*> Jugador::partidasIniciadasSinFinalizar()
{
   map<int, Partida*>::iterator i = this->inicio.begin();
   set<DtPartida*> isf;
   while(i != this->inicio.end()){
      if(!i->second->getFinalizada()){	
        if(dynamic_cast<PartidaIndividual*>(i->second) != NULL){
	 PartidaIndividual* pi = dynamic_cast<PartidaIndividual*>(i->second);
	 float* f = new float (pi->getContinuada()->getId());
         DtPartidaIndividual* p = new DtPartidaIndividual(pi->getId(), pi->getDuracion(), pi->getFecha(), f);
         DtPartida* p2 = dynamic_cast<DtPartida*>(p);
         isf.insert(p2);
        } else {
	PartidaMultijugador* pm = dynamic_cast<PartidaMultijugador*>(i->second);
        map<string, InfoPartidaMulti*> part = pm->getParticipan();
        map<string, InfoPartidaMulti*>::iterator it = part.begin();
        set<string> s;
        while (it != part.end()){
          s.insert(it->second->getParticipa()->getNickname());
          ++it;
        }
        DtPartidaMultijugador* p = new DtPartidaMultijugador(pm->getId(), pm->getDuracion(), pm->getFecha(), pm->getTransmitidaEnVivo(), s, s.size());
	DtPartida* p2 = dynamic_cast<DtPartida*>(p);
        isf.insert(p2);
        }
      }
      ++i;
   }
   return isf; 
}

void Jugador::iniciadaP(Partida* p){
   this->inicio[p->getId()] = p; 
}

bool Jugador::estaSuscritoA(std::string NombreVJ)
{
  bool b = false;
  set<Suscripcion*>::iterator it = suscripto.begin();
  Suscripcion* s = NULL;
  while (!b && (it != suscripto.end())) {
	s = *it;
	if (s->getnombreVJ() == NombreVJ){
		b = true;
	}
	++it;
  }
  s->~Suscripcion();
  return b;
}

Suscripcion* Jugador::getSuscripcion(string nomVJ){
  set<Suscripcion*>::iterator it = suscripto.begin();
  Suscripcion* res = NULL;
  while (it != suscripto.end()) {
    Suscripcion* s= *it;
	  if (s->getnombreVJ() == nomVJ){
		  res=s;
      break;
	}
	++it;
  }
  return res;
}

DtSuscripcion* Jugador::getDatosSuscripcion(string nomVJ){
  DtSuscripcion* res=NULL;
  CtrlUsuario* ctrlusuario = CtrlUsuario::getInstancia();
  Usuario* user= ctrlusuario->getSesionActiva();
  Jugador * jugador={dynamic_cast<Jugador*>(user)};
  Suscripcion* s= jugador->getSuscripcion(nomVJ);

  s = jugador->getSuscripcion(nomVJ);
  if (s!=NULL){
    //datos
    string n = s->getnombreVJ();
    DtFechaHora* f=s->getFecha();
    float c = s->getCosto();
    TipoPago tp = s->getTipoPago();
    TipoEstado te=s->getEstado();
    TipoPeriodo pe = s->getPeriodo();
    //(n,f,c,tp,te,v) datos

    res = new DtSuscripcion(n,f,c,tp,te,pe);
  }
  return res;
}

void Jugador::CancelarSuscripcion(string nomVJ) //se repite codigo para no recorrer dos veces la coleccion
{
    set<Suscripcion*>::iterator it = suscripto.begin();
    Suscripcion* res = NULL;
     while (it != suscripto.end()) {
      Suscripcion* s= *it;
	    if (s->getnombreVJ() == nomVJ){
		    res=s;
        break;
	    }
	    ++it;
    }
    if (res==NULL){ //Para identificar si se llama incorrectamente la funcion
      throw invalid_argument( "No existe suscripcion. " );
    }
    else {
      res->setCancelada(true);
    }
}

set<DtPartidaIndividual*> Jugador::partidasIndividualesFinalizadas()
{
   map<int, Partida*>::iterator i = this->inicio.begin();
   set<DtPartidaIndividual*> isf;
   while(i != this->inicio.end()){
      if(i->second->getFinalizada()){	
        if(dynamic_cast<PartidaIndividual*>(i->second) != NULL){
	 PartidaIndividual* pi = dynamic_cast<PartidaIndividual*>(i->second);
	 float* f = new float (pi->getContinuada()->getId());
         DtPartidaIndividual* p = new DtPartidaIndividual(pi->getId(), pi->getDuracion(), pi->getFecha(), f);
	 isf.insert(p);
	}
      }
    ++i;
    }
    return isf;
}

//Suscribirse a videojuego

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

void Jugador::mostrarUsuario(){ cout << "jug"; }


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

