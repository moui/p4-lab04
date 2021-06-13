#include "../../lib/manejadores/ManejadorUsuario.h"

// Singleton
ManejadorUsuario* ManejadorUsuario::instancia = NULL;

// GetInstance
ManejadorUsuario* ManejadorUsuario::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new ManejadorUsuario();
    }
    return instancia;
}
// Constructor
ManejadorUsuario::ManejadorUsuario(){}
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
    delete instancia;
}


void ManejadorUsuario::agregarDesarrollador(string clave, Desarrollador* des){
    desarrolladores.insert ( pair <string, Desarrollador*>(clave, des) );
}

void ManejadorUsuario::agregarJugador(string clave, Jugador* jug){
    jugadores.insert ( pair <string, Jugador*>(clave, jug) );
}

bool ManejadorUsuario::existeJugador(string nickname){
    bool res;
    while (itj!=jugadores.end()) {
        if (itj->second->getNickname()==nickname)
            break;
        itj++;
    }
    (itj==jugadores.end()) ? res=true : res=false;
    return res;
}

void ManejadorUsuario::borrarUsuario(string clave){}

Jugador* ManejadorUsuario::autenticarJugador(string mail, string contrasena){
   /* Jugador* res;
    itvj=desarrolladores.find(mail);
    */
    return NULL;
}

Desarrollador* ManejadorUsuario::autenticarDesarollador(string mail, string contrasena){
    return NULL;
}