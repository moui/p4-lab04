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


Jugador* buscarJugador(string clave){
    return (itj=jugadores.find(clave)->second);
}
Desarrollador* buscarDesarrollador(string clave){
    return (itd==desarrolladores.find(clave)->second);
}


bool existeUsuario(string clave){
    bool res;
    itj=jugadores.find(clave);
    itd=desarrolladores.find(clave);
    return (res=(itd!=desarrolladores.end() || itj!=jugadores.end())); 
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
