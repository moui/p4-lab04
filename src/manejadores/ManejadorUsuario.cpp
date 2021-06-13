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

Jugador* ManejadorUsuario::autenticarJugador(string mail, string contrasena){
   /* Jugador* res;
    itvj=desarrolladores.find(mail);
    */
    return NULL;
}

Desarrollador* ManejadorUsuario::autenticarDesarollador(string mail, string contrasena){
    return NULL;
}
