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
			int* continuacion;
			if (partidaInd->getContinuada() == NULL)
				continuacion = NULL;
			else
				continuacion = new int(partidaInd->getContinuada()->getId());

			partidas.insert(new DtPartidaIndividual(partidaInd->getId(), partidaInd->getDuracion(),
				partidaInd->getFecha(), partidaInd->getFechaFin(), nombreVid, continuacion)
				);
		}
	}
	return partidas;
}


void CtrlPartida::altaPartida(DtPartida* datosPartida)
{
	Jugador* jugador = dynamic_cast<Jugador*>(CtrlUsuario::getInstancia()->getSesionActiva());
	// Determinar tipo partida
	if ( dynamic_cast<DtPartidaIndividual*>(datosPartida) != NULL )
	{
		// ALTA PARTIDA INDIVIDUAL
		auto datosPartidaInd = dynamic_cast<DtPartidaIndividual*>(datosPartida);
		if (datosPartidaInd->getContinuacion() != NULL)
		{
			// CONTINUA PARTIDA ANTERIOR
			int id = manejadorPartida->generarIdPartidaInd();
			Videojuego* videojuego = CtrlVideojuego::getCtrlVideojuego()->getVJ(datosPartidaInd->getNombreVJ());
			DtFechaHora* fechaInicio = new DtFechaHora(datosPartidaInd->getFecha());
			PartidaIndividual* continua = manejadorPartida->getPI(*datosPartidaInd->getContinuacion());
			PartidaIndividual* partida = new PartidaIndividual(id, 0, false, fechaInicio, NULL, videojuego, continua);
			// Actualizar colecciones
			jugador->agregarPartida(id, partida);
			manejadorPartida->AgregarPartidaIndividual(id, partida);
		}
		else
		{
			// NO CONTINUA PARTIDA ANTERIOR
			int id = manejadorPartida->generarIdPartidaInd();
			Videojuego* videojuego = CtrlVideojuego::getCtrlVideojuego()->getVJ(datosPartidaInd->getNombreVJ());
			DtFechaHora* fechaInicio = new DtFechaHora(datosPartidaInd->getFecha());
			PartidaIndividual* partida = new PartidaIndividual(id, 0, false, fechaInicio, NULL, videojuego, NULL);
			// Actualizar colecciones
			jugador->agregarPartida(id, partida);
			manejadorPartida->AgregarPartidaIndividual(id, partida);
		}
	}
	else
	{
		// ALTA PARTIDA MULTIJUGADOR
		auto datosPartidaMulti = dynamic_cast<DtPartidaMultijugador*>(datosPartida);
		
		set<string> nicknames = datosPartidaMulti->getNicknameJugadoresUnidos();
		map<string, InfoPartidaMulti*> unidos;
		for (auto it = nicknames.begin(); it != nicknames.end(); ++it)
		{
			string nickname = *it;
			Jugador* jugador = CtrlUsuario::getInstancia()->buscarJugador(nickname);
			InfoPartidaMulti* info = new InfoPartidaMulti(NULL, jugador);
			unidos.insert( pair<string, InfoPartidaMulti*>(jugador->getMail(), info) );
		}
		int id = manejadorPartida->generarIdPartidaMulti();
		Videojuego* videojuego = CtrlVideojuego::getCtrlVideojuego()->getVJ(datosPartidaMulti->getNombreVJ());
		DtFechaHora* fechaInicio = new DtFechaHora(datosPartidaMulti->getFecha());
		PartidaMultijugador* partida = new PartidaMultijugador(id, 0, false, fechaInicio, NULL, videojuego, 
			datosPartidaMulti->getTransmitidaEnVivo(), unidos);
		// Actualizar colecciones;
		jugador->agregarPartida(id, partida);
		manejadorPartida->AgregarPartidaMultijugador(id, partida);
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
	manejadorPartida->finalizarPartida(fin, id);
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