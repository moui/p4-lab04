#include "../../lib/controllers/CtrlPartida.h"

using namespace std;

CtrlPartida* CtrlPartida::instancia = NULL;

// CONSTRUCTOR
CtrlPartida::CtrlPartida()
{
	manejadorPartida = ManejadorPartida::getInstancia();
}

// DESTRUCTOR
CtrlPartida::~CtrlPartida()
{
	delete manejadorPartida;
}

// getInstance()
CtrlPartida* CtrlPartida::getCtrlPartida()
{
    if (instancia == NULL)
	{
        instancia = new CtrlPartida();
    }
    return instancia;
}

// OPERACIONES MANEJADOR
ManejadorPartida* CtrlPartida::getManejadorPatida()
{
	return manejadorPartida;
}


// INICIAR PARTIDA

set<DtPartidaIndividual*> CtrlPartida::partidasIndFinalizadas(string nombreVideojuego)
{
	// Checkear que el videojuego exista en el catalogo
	if (CtrlVideojuego::getCtrlVideojuego()->getVJ(nombreVideojuego) == NULL)
		throw invalid_argument("No existe videojuego " + nombreVideojuego);

	set<DtPartidaIndividual*> partidas;
	// Get usuario loggeado
	Usuario* usuario =  CtrlUsuario::getInstancia()->getSesionActiva();
	if (dynamic_cast<Jugador*>(usuario) == NULL)
		throw invalid_argument("Usuario loggeado debe ser jugador.");
	Jugador* jugador = dynamic_cast<Jugador*>(usuario);
	// Iterar en partidas iniciadas por jugador
	map<int, Partida*> partidasJugador = jugador->getInicioPartidas();
	
	if (partidasJugador.empty())
		return partidas; // Si no existen partidasJugador retorna el set vacio
	else
	{
		for (auto it = partidasJugador.begin(); it != partidasJugador.end(); ++it)
		{
			if ( dynamic_cast<PartidaIndividual*>(it->second) == NULL )
				continue;
			// Castear a partida individual, checkear si esta finalizada
			// y si es el videojuego que se pide
			auto partidaInd = dynamic_cast<PartidaIndividual*>(it->second);
			string nombreVid = partidaInd->getVideojuego()->getNombreVJ();
			if ( !partidaInd->getFinalizada() || nombreVid != nombreVideojuego )
				continue;
			// Agregar data 'partidaInd' a 'partidas'	
			bool continuacion = partidaInd->getContinuada() == NULL ? false : true;
			partidas.insert(new DtPartidaIndividual(partidaInd->getId(), partidaInd->getDuracion(),
				partidaInd->getFecha(), NULL, nombreVid, continuacion)
				);
		}
	}
	return partidas;
}


void CtrlPartida::altaPartida(DtPartida* datosPartida)
{
	Jugador* jugador = dynamic_cast<Jugador*>(CtrlUsuario::getInstancia()->getSesionActiva());
	map<int, Partida*> partidasJugador = jugador->getInicioPartidas();
	// Determinar tipo partida
	if ( dynamic_cast<DtPartidaIndividual*>(datosPartida) != NULL )
	{
		// ALTA PARTIDA INDIVIDUAL
		auto datosPartidaInd = dynamic_cast<DtPartidaIndividual*>(datosPartida);
		if (datosPartidaInd->getContinuacion())
		{
			// CONTINUA PARTIDA ANTERIOR
		}
		else
		{
			// NO CONTINUA PARTIDA ANTERIOR
			int id = manejadorPartida->getTotalPartidasInd();
			Videojuego* videojueo = CtrlVideojuego::getCtrlVideojuego()->getVJ(datosPartidaInd->getNombreVJ());
			DtFechaHora* fechaInicio = new DtFechaHora(datosPartidaInd->getFecha());
			PartidaIndividual* partida = new PartidaIndividual(id, 0, false, fechaInicio, NULL, videojueo, NULL);
			// Actualizar colecciones
			partidasJugador.insert(pair<int, Partida*>(id, partida));
			manejadorPartida->AgregarPartidaIndividual(id, partida);
		}
	}
	else
	{
		// ALTA PARTIDA MULTIJUGADOR

	}
}

/*

void CtrlPartida::crearPartida(string nombreVJ){
	this->nomVJ = nombreVJ;
}

void CtrlPartida::partidaAContinuar(float id){
	this->f = id;
}
void CtrlPartida::listaJugUnidos(set<string> Mails){
	this->mails = Mails;
}

set<string> listaJugSuscriptos(){
    set<string> a;
    CtrlUsuario* ctrlUsuario;
    ctrlUsuario = CtrlUsuario::getInstancia();
    Jugador* j = dynamic_cast<Jugador*> (ctrlUsuario->getSesionActiva());
    a = ctrlUsuario->listaJugadoresSus(j->getNickname());
    return a;
}
void CtrlPartida::confirmarIniciarPartida(DtFechaHora inicio){
	CtrlVideojuego* ctrlvideojuego;
        ctrlvideojuego = CtrlVideojuego::getCtrlVideojuego();
	Videojuego* v = ctrlvideojuego->getVJ(nomVJ);
	CtrlUsuario* ctrlUsuario;
    	ctrlUsuario = CtrlUsuario::getInstancia();
	map<string, InfoPartidaMulti*> mapInfoPM = ctrlUsuario->getInfoJugadores(inicio, mails);	
	if (this->enVivo != NULL) {
		PartidaMultijugador* p = new PartidaMultijugador(cantP, 0, false, inicio, v, enVivo, mapInfoPM);
		ctrlvideojuego->iniciadaP(dynamic_cast<Partida*>(p));
		ctrlUsuario->iniciadaP(dynamic_cast<Partida*>(p));
		manejadorPartida->AgregarPartidaMultijugador(cantP, *p);
	} else {
		PartidaIndividual pi = manejadorPartida->getPI(f);
		PartidaIndividual* i = & pi;
		PartidaIndividual* p = new PartidaIndividual(cantP, 0, false, inicio, v, i);
		ctrlvideojuego->iniciadaP(dynamic_cast<Partida*>(p));
		ctrlUsuario->iniciadaP(dynamic_cast<Partida*>(p));
		manejadorPartida->AgregarPartidaIndividual(cantP, *p);
	}
	cantP = cantP + 1;	
}


set<DtPartidaIndividual*> listaPartidasIndTer(){
    set<DtPartidaIndividual*> a;
    CtrlUsuario* ctrlUsuario;
    ctrlUsuario = CtrlUsuario::getInstancia();
    a = ctrlUsuario->listaPartidasIndividualesTerminadas();
    return a;
}

void CtrlPartida::ENVivo(bool EnVivo){
	this->enVivo = & EnVivo;
}
void CtrlPartida::cancelarIniciarPartida(){

}

set<DtPartida*> CtrlPartida::listaPartidasIniciadas(){
    set<DtPartida*> a;
    CtrlUsuario* ctrlUsuario;
    ctrlUsuario = CtrlUsuario::getInstancia();
    a = ctrlUsuario->listaPartidasIniciadas();
    return a;
}

}*/

void CtrlPartida::finalizarPartida(DtFechaHora* fin, int id){
	Partida* par = manejadorPartida->getPI(id);
	par->setFechaFin(fin);
	//calcular duracion y setearla tambien
}

void cancelarFinalizarPartida(){

}



// ABANDONAR PARTIDA MULTIJUGADOR
set<DtPartidaMultijugador*> CtrlPartida::listarPartidasMultijugadorUnidas(string mailJugador)
{
	set<DtPartidaMultijugador*> res = manejadorPartida->listarPartidasMultijugadorUnidas(mailJugador);
	return res;
}

 void CtrlPartida::ConfirmarAbandonarPartida(string mail, int partidaMJ)
 {
	 manejadorPartida->ConfirmarAbandonarPartida(mail,partidaMJ);
 }

    set<DtPartida*> CtrlPartida::listaPartidasIniciadasSinFinalizar()
	{
		set<DtPartida*> res;
		CtrlUsuario* ctrlusuario = CtrlUsuario::getInstancia();
		res = ctrlusuario->listaPartidasIniciadasSinFinalizar();
		if (res.empty())
		{
			throw invalid_argument("No se obtuvieron datos del controlador usuario. ");
		}
		return res;
	}