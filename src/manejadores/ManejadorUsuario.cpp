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

Usuario* ManejadorUsuario::buscarUsuario(string clave){
    return NULL;
}

void ManejadorUsuario::agregarDesarrollador(string clave, Desarrollador* des){
    desarrolladores.insert ( pair <string, Desarrollador*>(clave, des) );
}

void ManejadorUsuario::agregarJugador(string clave, Jugador* jug){
    jugadores.insert ( pair <string, Jugador*>(clave, jug) );
}

bool ManejadorUsuario::existeJugador(string nickname){
    bool ret = false;
    if ( jugadores.find(nickname) == jugadores.end() ) {
        ret = false;
    } else {
        ret = true;
    }
    return ret;
}

void ManejadorUsuario::borrarUsuario(string clave){}

 //Usuario* autenticarUsuario(string mail, string contrasena){
   //  if ( desarrolladores.find(mail))
// }