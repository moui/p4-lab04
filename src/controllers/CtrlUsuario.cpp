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
        if(datosSuscripcion==NULL)
        {
            throw invalid_argument("no se guardaron los datos en el sistema. ");
        }
        jugador->AltaSuscripcion(datosSuscripcion);
        CtrlVideojuego* ctrlvidejuego;
        ctrlvidejuego = CtrlVideojuego::getCtrlVideojuego();
        string nomVJ = datosSuscripcion->getnombreVJ();
        string nomJ=jugador->getMail();
        ctrlvidejuego->agregarSuscrito(nomVJ, nomJ);
    }

    void CtrlUsuario::CancelarOperacion()
    {
        //Dcatalogo.clear();
        delete datosSuscripcion;
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
            case 1:periodo=TipoPeriodo::Mensual; break; 
            case 3:periodo=TipoPeriodo::Trimestral; break; 
            case 12:periodo=TipoPeriodo::Anual; break;
            case 0:periodo=TipoPeriodo::Vitalicia; break;
            default: throw invalid_argument( "Periodo de validez invalido. " ); break;        
        }
        CtrlVideojuego* ctrlvidejuego;
        ctrlvidejuego = CtrlVideojuego::getCtrlVideojuego();

        int costo = ctrlvidejuego->getCostoSuscripcion(periodo, nomVJ);

        this->datosSuscripcion = new DtSuscripcion(nomVJ, new DtFechaHora(FechaSistema::getInstancia()->getFecha()),
            costo, pago, TipoEstado::activa, periodo);
    }

    TipoEstado CtrlUsuario::JuegoSuscribirse(string nomVJ){
        TipoEstado res= TipoEstado::expirada;

        Usuario* user= CtrlUsuario::getSesionActiva();
        Jugador * jugador={dynamic_cast<Jugador*>(user)};

        Suscripcion* s= jugador->getSuscripcion(nomVJ);
        if (s!=NULL)
        {
            if (s->getPeriodo() == TipoPeriodo::Vitalicia) {
                throw invalid_argument( "No se puede cancelar suscripcion Vitalicia. " );
            }
            
        res = s->getEstado();
        }
        return res;
    }

    void CtrlUsuario::ObtenerCatalogo(){
        CtrlVideojuego* ctrlvidejuego;
        ctrlvidejuego = CtrlVideojuego::getCtrlVideojuego();
        this->Dcatalogo = ctrlvidejuego->ObtenerCatalogo();
        if (Dcatalogo.empty())
        {
            throw invalid_argument("Fallo copia local del catalogo ");
        }

}


    set<DtVideojuegoSuscripcion*> CtrlUsuario::listarVideojuegoSuscripcionesActivas(){
        set<DtVideojuegoSuscripcion*> res;
        Usuario* user= CtrlUsuario::getSesionActiva();
        Jugador * jugador={dynamic_cast<Jugador*>(user)};

        auto map = jugador->listarVideojuegoSuscripcionesActivas();
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            res.insert(it->second);
        }

        return res;
    }

    set<DtVideojuegoSuscripcion*> CtrlUsuario::listarVideojuegoSuscripcionesNoActivas()
    {
        set<DtVideojuegoSuscripcion*> suscripcionesNoActivas;

        CtrlVideojuego* ctrlVideojuego = CtrlVideojuego::getCtrlVideojuego();

        Jugador * jugador = dynamic_cast<Jugador*>(getSesionActiva());
        auto map = jugador->listarVideojuegoSuscripcionesActivas();
        
        suscripcionesNoActivas = ctrlVideojuego->getComplemento(map);
        
        // Borrar mem del map
        for (auto it = map.begin(); it != map.end(); ++it)
        {
            delete it->second;
        }
        
        return suscripcionesNoActivas;
       
    }

// SELECCIONAR ESTADISTICAS


void CtrlUsuario::listarEstadisticas() //se imprimen directamente los strings, e ma facil
{
    cout << "                 (1)   TOTAL HORAS DE JUEGO. \n";
    cout << "\n";
    cout << "Calcula el total de horas de juego, en todas las partidas para un juego determinado. \n";
    cout << Constantes::Separador;
    cout << "                 (2)  TOTAL DE JUGADORES SUSCRITOS. \n";
    cout << "\n";
    cout << "Calcula el total de jugadores suscritos a determinado. \n";

}

void CtrlUsuario::seleccionarEstadisticas(bool s1, bool s2)
    {
        Usuario* user= CtrlUsuario::getSesionActiva();
        Desarrollador * desarrollador={dynamic_cast<Desarrollador*>(user)};

        if(s1)
        {
            desarrollador->agregarEstadistica(1);
        }
        if(s2)
        {
            desarrollador->agregarEstadistica(2);
        }
    }
// CONSULTAR ESTADISTICAS


set<string> CtrlUsuario::listarVideojuegosPublicados()
{
    set<string> res;
    Usuario* user= CtrlUsuario::getSesionActiva();
    Desarrollador * desarrollador={dynamic_cast<Desarrollador*>(user)};
    res= desarrollador->listarVideojuegosPublicados();
    if(res.empty())
    {
        throw invalid_argument("No se obtuvieron datos del Desarrollador. ");
    }
    return res;
}

set<DtEstadistica*> CtrlUsuario::ConsultarEstadisticas(string nomVJ)
{
    set<DtEstadistica*> res;
    Usuario* user= CtrlUsuario::getSesionActiva();
    Desarrollador * desarrollador={dynamic_cast<Desarrollador*>(user)};
    res=desarrollador->CalcularEstadisticas(nomVJ);
    if (res.empty())
    {
        throw invalid_argument("No de obtuvieron datos del desarrollador. ");
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


set<DtVideojuego*> CtrlUsuario::listarVideoJuegosDesarrollador(){
    set<DtVideojuego*> res;
    Desarrollador* des = dynamic_cast<Desarrollador*>(CtrlUsuario::getSesionActiva());
    return des->getVJPub();
}