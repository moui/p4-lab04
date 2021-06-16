#include "../../lib/manejadores/ManejadorUsuario.h"

// Constructor
ManejadorUsuario::ManejadorUsuario()
{

}
// Destructor
ManejadorUsuario::~ManejadorUsuario(){
    for (itd = desarrolladores.begin(); itd != desarrolladores.end(); itd++)
    {
        if (itd->second != NULL)
            delete itd->second;
    }
    for (itj = jugadores.begin(); itj != jugadores.end(); itj++)
    {
        if (itj->second != NULL)
            delete itj->second;
    }
    desarrolladores.clear();
    jugadores.clear();
}


void ManejadorUsuario::agregarDesarrollador(string clave, Desarrollador* des){
    desarrolladores.insert ( pair <string, Desarrollador*>(clave, des) );
}

void ManejadorUsuario::agregarJugador(string clave, Jugador* jug){
    jugadores.insert ( pair <string, Jugador*>(clave, jug) );
}

bool ManejadorUsuario::existeJugador(string nickname){
    bool res;
    if ( !jugadores.empty() ){
        itj = jugadores.begin();
        while (itj!=jugadores.end()) {
            if (itj->second->getNickname()==nickname)
                break;
            itj++;
        }
        (itj==jugadores.end()) ? res=false : res=true;
    }
    else res = false;
    return res;
}

void ManejadorUsuario::borrarUsuario(string clave){}


Jugador* ManejadorUsuario::buscarJugador(string clave){
    Jugador* res;
    if (jugadores.find(clave)!=jugadores.end()){
        res= jugadores.find(clave)->second;
    } else res=NULL;

    return res;
}
Desarrollador* ManejadorUsuario::buscarDesarrollador(string clave){
   Desarrollador* res;
    if (desarrolladores.find(clave)!=desarrolladores.end()){
        res= desarrolladores.find(clave)->second;
    } else res=NULL;
    
    return res;
}


bool ManejadorUsuario::existeUsuario(string clave){
    bool res;
    itj=jugadores.find(clave);
    itd=desarrolladores.find(clave);
    return (res=(itd!=desarrolladores.end() || itj!=jugadores.end())); 
}

//IniciarPartida
set<string> ManejadorUsuario::listaJugadoresSus(string NomVJ){
	set<string> s;
	itj = jugadores.begin();
	for(itj = jugadores.begin(); itj != jugadores.end(); ++itj){
		if(itj->second->estaSuscritoA(NomVJ)){
			s.insert(itj->second->getNickname());
		}
	}
	return s;
}

set<DtPartidaIndividual*> ManejadorUsuario::partidasIndividualesFinalizadas(string nickname){
	itj = jugadores.begin();
	while((itj->second->getNickname() != nickname) && (itj != jugadores.end())){
		++itj;
	}
	return itj->second->partidasIndividualesFinalizadas();
}

void ManejadorUsuario::iniciadaP(string clave,Partida* p){
	jugadores[clave]->iniciadaP(p);
}

map<string, InfoPartidaMulti*> ManejadorUsuario::getInfoJugadores(DtFechaHora f, set<string> mails){
	set<string>::iterator it = mails.begin();
	map<string, InfoPartidaMulti*> m;
	while(it != mails.end()){	
		m[*it] = new InfoPartidaMulti(f, jugadores[*it]);
		++it;
	}
	return m;
}

//FinalizarPartida
set<DtPartida*> ManejadorUsuario::listaPartidasIniciadas(string mail){
	return jugadores[mail]->partidasIniciadasSinFinalizar();
}

void ManejadorUsuario::finPartida(string mail, DtFechaHora f, float id){
	jugadores[mail]->finPartida(id, f);
}

bool ManejadorUsuario::autenticarJugador(string mail, string contrasena){
    bool res=false;
    if (!jugadores.empty()){
        itj= jugadores.find(mail);

        if(itj!=jugadores.end()){
            ( (mail==itj->second->getMail()) && (contrasena==itj->second->getContrasena()) ) ? res= true : res= false;
        }

    }
    return res;
}

 bool ManejadorUsuario::autenticarDesarollador(string mail, string contrasena){
    bool res=false;
    if (!desarrolladores.empty()){
        itd= desarrolladores.find(mail);

        if(itd!=desarrolladores.end()){
            ( (mail==itd->second->getMail()) && (contrasena==itd->second->getContrasena()) ) ? res= true : res= false;
        }

    }
    return res;
}
