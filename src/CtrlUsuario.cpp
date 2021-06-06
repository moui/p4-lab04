#include "../lib/CtrlUsuario.h"

using namespace std;

CtrlUsuario * CtrlUsuario::instancia = NULL;
    
CtrlUsuario::~CtrlUsuario(){

}
    
CtrlUsuario * CtrlUsuario::getCtrlUsuario(){
    if (instancia == NULL){
        instancia = new CtrlUsuario();
    }
    return instancia;
}

void ingresaDatosUauario(string mail, string contrasena){

}

void ingresaNombreEmpresa(string nombre){

}

void confirmaAltaDesarrollador(){

}

void cancelaAltaDesarrollador(){

}

void ingresaNicknameJugador(string nickname){

}

void confirmaAltaJugador(){

}

void cancelaAltaJugador(){

}

        