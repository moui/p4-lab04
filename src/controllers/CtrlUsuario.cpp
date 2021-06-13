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
    manejadorUsuario = new ManejadorUsuario();
}
// Destructor
CtrlUsuario::~CtrlUsuario()
{
    delete manejadorUsuario;
}
// Getters
Usuario* CtrlUsuario::getSesionActiva()
{
    return sesionActiva;
}
ManejadorUsuario* CtrlUsuario::getManejadorUsuario()
{
    return manejadorUsuario;
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

void CtrlUsuario::iniciarSesion(string mail, string contrasena){
   // ManejadorUsuario* manusr = ManejadorUsuario::getInstancia();
    
}

// Implementacion de caso de uso Alta Usuario
void CtrlUsuario::ingresaDatosUsuario(string nmail, string ncontrasena){
    this->mail = nmail;
    this->contrasena = ncontrasena;
}

void CtrlUsuario::ingresaDatosJugador(string nnickname, string ndescripcion){
    if ( manejadorUsuario->existeJugador(nnickname) ){
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
    manejadorUsuario->agregarDesarrollador(mail, new Desarrollador(mail, contrasena, empresa));
}

void CtrlUsuario::confirmaAltaJugador(){
    manejadorUsuario->agregarJugador(nickname, new Jugador(mail, contrasena, nickname, descripcion));
}

void CtrlUsuario::cancelaAlta(){

}

//IniciarPartida
set<string> CtrlUsuario::listaJugadoresSus(string NomVJ){
	return (manejadorUsuario->listaJugadoresSus(NomVJ));
}
