#include "../../lib/controllers/CtrlUsuario.h"

// Singleton
CtrlUsuario* CtrlUsuario::instancia = NULL;
// GetInstance
CtrlUsuario* CtrlUsuario::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new CtrlUsuario();
    }
    return instancia;
}
// Constructor
CtrlUsuario::CtrlUsuario()
{
    sesionActiva = NULL;
}
// Destructor
CtrlUsuario::~CtrlUsuario()
{
    delete instancia;
}
// Getters
Usuario* CtrlUsuario::getSesionActiva()
{
    return sesionActiva;
}
// Setters
void CtrlUsuario::setSesionActiva(Usuario* usuario)
{
    sesionActiva = usuario;
}
// Implementacion de IUsuario
void CtrlUsuario::altaUsuario()
{

}

void CtrlUsuario::iniciarSesion()
{

}

// Implementacion de caso de uso Alta Usuario
void CtrlUsuario::ingresaDatosUsuario(string nmail, string ncontrasena){
    this->mail = nmail;
    this->contrasena = ncontrasena;
}

void CtrlUsuario::ingresaDatosJugador(string nnickname, string ndescripcion){
    ManejadorUsuario* manusr = ManejadorUsuario::getInstancia();
    if ( manusr->existeJugador(nickname) ){
        throw invalid_argument( "Ya existe un jugador con ese nickname." );
    }
    else {
        this->nickname = nnickname;
        this->descripcion = ndescripcion;
    }
}

void CtrlUsuario::ingresaDatosDesarrollador(string nempresa){
    this->empresa = nempresa;
}

void CtrlUsuario::confirmaAltaDesarrollador(){
    ManejadorUsuario* manusr = ManejadorUsuario::getInstancia();
    manusr->agregarDesarrollador(mail, Desarrollador(mail, contrasena, empresa));
}

void CtrlUsuario::confirmaAltaJugador(){
    ManejadorUsuario* manusr = ManejadorUsuario::getInstancia();
    manusr->agregarJugador(nickname, Jugador(mail, contrasena, nickname, descripcion));
}

void CtrlUsuario::cancelaAlta(){

}