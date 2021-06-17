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

    void CtrlUsuario::AltaSuscripcion()
    {
        Usuario* user= CtrlUsuario::getSesionActiva();
        Jugador * jugador={dynamic_cast<Jugador*>(user)};
        if(datosDescripcionSuscripcion==NULL)
        {
            throw invalid_argument("no se guardaron los datos en el sistema. ");
        }
        jugador->AltaSuscripcion(datosDescripcionSuscripcion, pagoSuscripcion);


    }

    void CtrlUsuario::CancelarOperacion()
    {
        Dcatalogo.clear();
        delete datosDescripcionSuscripcion;
        //delete pagoSuscripcion;
    }

    void CtrlUsuario::CancelarSuscripcion(string nomVJ){

        Usuario* user= CtrlUsuario::getSesionActiva();
        Jugador * jugador={dynamic_cast<Jugador*>(user)};
        jugador->CancelarSuscripcion(nomVJ);

    }

    void CtrlUsuario::SuscribirseVideojuego(int a, int b, string nomVJ)
    {
        TipoPago pago;
        TipoPeriodo periodo;
        switch(a)
        {
            case 1:pago=TipoPago::paypal; break; 
            case 2:pago=TipoPago::tarjeta; break; 
            case 3:pago=TipoPago::otro; break; 
            default: throw invalid_argument( "Metodo de pago invalido. " ); break;
        }
        switch(b)
        {
            case 1:periodo=TipoPeriodo::mensual; break; 
            case 3:periodo=TipoPeriodo::trimestral; break; 
            case 12:periodo=TipoPeriodo::anual; break;
            case 0:periodo=TipoPeriodo::vitalicia; break;
            default: throw invalid_argument( "Periodo de validez invalido. " ); break;        
        }
        CtrlVideojuego* ctrlvidejuego;
        ctrlvidejuego = CtrlVideojuego::getCtrlVideojuego();

        DtDescripcionSuscripcion* ds=NULL;
        ds= ctrlvidejuego->getDatosDescripcionSuscripcion(periodo, nomVJ);
        this->datosDescripcionSuscripcion=ds;
        this->pagoSuscripcion= pago;


    }


    TipoEstado CtrlUsuario::JuegoSuscribirse(string nomVJ){
        TipoEstado res= TipoEstado::expirada;

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
        CtrlVideojuego* ctrlvidejuego;
        ctrlvidejuego = CtrlVideojuego::getCtrlVideojuego();
        res = ctrlvidejuego->ObtenerCatalogo();
        if (Dcatalogo.empty())
        {
            throw invalid_argument("Fallo copia local del catalogo ");
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

// SELECCIONAR ESTADISTICAS

set<DtEstadistica*> CtrlUsuario::listarEstadisticas()
{
        set<DtEstadistica*> res;
        /*Usuario* user= CtrlUsuario::getSesionActiva();
        Desarrollador* desarrollador={dynamic_cast<Desarrollador*>(user)};*/
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

map<string, InfoPartidaMulti*> CtrlUsuario::getInfoJugadores(DtFechaHora f, set<string> mails){
	return manejadorUsuario->getInfoJugadores(f, mails);
}

//FinalizarPartida
set<DtPartida*> CtrlUsuario::listaPartidasIniciadas(){
	return (manejadorUsuario->listaPartidasIniciadas(sesionActiva->getMail()));
}

void CtrlUsuario::finPartida(DtFechaHora f, float id){
	manejadorUsuario->finPartida(sesionActiva->getMail(), f, id);
}
