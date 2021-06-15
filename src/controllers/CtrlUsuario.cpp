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
//iniciar sesion

DtUsuario* CtrlUsuario::iniciarSesion(string mail, string contrasena){
    DtUsuario* res=NULL;
    bool existeUsr=manejadorUsuario->existeUsuario(mail);
    if (!existeUsr) {
        throw invalid_argument( "Usuario no registrado." );    
    } else{
        Jugador* j = manejadorUsuario->buscarJugador(mail);

        if (j!=NULL) {

            bool autentica = manejadorUsuario->autenticarJugador(mail, contrasena);
            if (!autentica) {

                throw invalid_argument( "Contrasena incorrecta.");
            } else {
                this->sesionActiva=j;

                string m = j->getMail();
                string n = j->getNickname();
                string d = j->getDescripcion();

                res= new DtJugador(m,n,d);

            }
        } else {
            bool autentica = manejadorUsuario->autenticarDesarollador(mail, contrasena);
            if (!autentica) {

                throw invalid_argument( "Contrasena incorrecta.");
            } else {
                Desarrollador* d= manejadorUsuario->buscarDesarrollador(mail);
                this->sesionActiva=d;

                string m = d->getMail();
                string e = d->getEmpresa();

                res= new DtDesarrollador(m,e);

            }
        }
    }
    return res;
}

//implementacion caso de uso Suscribirse a Videojuego


    TipoEstado CtrlUsuario::JuegoSuscribirse(string nomVJ){
        TipoEstado res;

        Usuario* user= CtrlUsuario::getSesionActiva();
        Jugador * jugador={dynamic_cast<Jugador*>(user)};
        Suscripcion* s= jugador->getSuscripcion(nomVJ);
        if (s->getVitalicia()) {
            throw invalid_argument( "No se puede cancelar suscripcion Vitalicia. " );
        }
        res = s->getEstado();

        return res;
    }

    map<string, DtVideojuegoSuscripcion*> CtrlUsuario::ObtenerCatalogo(){
        map<string, DtVideojuegoSuscripcion*> res;
        if (!Dcatalogo.empty()) {
        CtrlVideojuego* ctrlvidejuego;
        ctrlvidejuego = CtrlVideojuego::getCtrlVideojuego();
        res = ctrlvidejuego->ObtenerCatalogo();
        } else {
            throw invalid_argument( "Catalogo de Videojuegos vacio. ");
        }
        return res;
}


    set<DtVideojuegoSuscripcion*> CtrlUsuario::listarVideojuegoSuscripcionesActivas(){
        set<DtVideojuegoSuscripcion*> res;
        this->Dcatalogo=ObtenerCatalogo();
        Usuario* user= CtrlUsuario::getSesionActiva();
        Jugador * jugador={dynamic_cast<Jugador*>(user)};
        res=jugador->listarVideojuegoSuscripcionesActivas(Dcatalogo);
        return res;
    }

    set<DtVideojuegoSuscripcion*> CtrlUsuario::listarVideojuegoSuscripcionesNoActivas(){
        set<DtVideojuegoSuscripcion*> res;
        map<string, DtVideojuegoSuscripcion*>::iterator itDcatalogo;
        for(itDcatalogo=Dcatalogo.begin(); itDcatalogo!=Dcatalogo.end(); itDcatalogo++){
            res.insert(itDcatalogo->second);
            Dcatalogo.erase(itDcatalogo);
        }
        return res;
       
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
    manejadorUsuario->agregarJugador(mail, new Jugador(mail, contrasena, nickname, descripcion));
}

void CtrlUsuario::cancelaAlta(){

}

//IniciarPartida
set<string> CtrlUsuario::listaJugadoresSus(string NomVJ){
	return (manejadorUsuario->listaJugadoresSus(NomVJ));
}

set<DtPartidaIndividual*> CtrlUsuario::listaPartidasIndividualesTerminadas(){
	Jugador* j = dynamic_cast<Jugador*> (sesionActiva);
	return manejadorUsuario->partidasIndividualesFinalizadas(j->getNickname());
}

void CtrlUsuario::iniciadaP(Partida* p){
	string c = sesionActiva->getMail();
	manejadorUsuario->iniciadaP(c ,p);
}
