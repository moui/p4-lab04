#include "../../lib/controllers/CtrlPartida.h"

using namespace std;

CtrlPartida * CtrlPartida::instancia = NULL;
    
CtrlPartida::~CtrlPartida(){

}

CtrlPartida::CtrlPartida(){

}
    
CtrlPartida * CtrlPartida::getCtrlPartida(){
    if (instancia == NULL){
        instancia = new CtrlPartida();
    }
    return instancia;
}

void crearPartida(string nombreVJ){

}

void partidaAContinuar(float id){

}
void listaJugUnidos(set<string> nicknames){

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
	CtrlVideojuego* ctrlvidejuego;
        ctrlvidejuego = CtrlVideojuego::getCtrlVideojuego();
	Videojuego* v = ctrlVideojuego->getVJ();
	CtrlUsuario* ctrlUsuario;
    	ctrlUsuario = CtrlUsuario::getInstancia();
	map<string, InfoPartidaMulti> mapInfoPM = ctrlUsuario->getInfoPartida(nicknames);	
	if (this->enVivo != NULL) {
		PartidaMultijugador* p = PartidaMultijugador(cantP, 0, false, inicio, v, enVivo, mapInfoPM);
		ctrlvideojuego->iniciadaP(dynamic_cast<Partida*>(p));
		ctrlUsuario->iniciadaP(dynamic_cast<Partida*>(p));
	} else {
		PartidaIndividual* p = PartidaIndividual(id, 0, false, inicio, v, enVivo, f);
		ctrlvideojuego->iniciadaP(dynamic_cast<Partida*>(p));
		ctrlUsuario->iniciadaP(dynamic_cast<Partida*>(p));
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

void enVivo(bool enVivo){

}
void cancelarIniciarPartida(){

}
set<DtPartidaIndividual> listaPartidasIniciadas(string nickname){
    set<DtPartidaIndividual> a;
    return a;
}
void finalizarPartida(float id){

}
void cancelarFinalizarPartida(){

}
