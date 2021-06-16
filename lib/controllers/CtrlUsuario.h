#ifndef CTRLUSUARIO
#define CTRLUSUARIO

#include "../interfaces/IUsuario.h"
#include "../Jugador.h"
#include "../Desarrollador.h"
#include "../manejadores/ManejadorUsuario.h"
#include "../datatypes/DtVideojuegoSuscripcion.h"
#include "../datatypes/DtSuscripcion.h"
#include "CtrlVideojuego.h"

#include <string>
#include <algorithm>
#include <set>

using namespace std;

class CtrlVideojuego;
class ManejadorUsuario;

// Singleton. Implementa IUsuario.
class CtrlUsuario : public IUsuario
{
    private:
        // Singleton
        static CtrlUsuario* instancia;
        // Constructor
        CtrlUsuario();
        // Members
        Usuario* sesionActiva;
        ManejadorUsuario* manejadorUsuario;
        // "Memoria"
        string mail, contrasena, nickname, empresa, descripcion;

        map<string, DtVideojuegoSuscripcion*> Dcatalogo;

    public:
        // GetInstance
        static CtrlUsuario* getInstancia();
        // Destructor
        ~CtrlUsuario();

        // Getters y Setters
        Usuario* getSesionActiva();
        ManejadorUsuario* getManejadorUsuario();
        void setSesionActiva(Usuario* usuario);
        
        // Implementacion IUsuario
        void altaUsuario();
        DtUsuario* iniciarSesion(string mail, string contrasena);

        // caso de uso suscribirse a videojuego

        map<string, DtVideojuegoSuscripcion*> ObtenerCatalogo(); 
        set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesActivas();
        set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesNoActivas();
        TipoEstado JuegoSuscribirse(string nomVJ);
        void CancelarOperacion();

        // Caso de Uso Alta Usuario
        void ingresaDatosUsuario(string nmail, string ncontrasena);
        void ingresaDatosJugador(string nnickname, string ndescripcion);
        void ingresaDatosDesarrollador(string nempresa);
        void confirmaAltaDesarrollador();
        void confirmaAltaJugador();
        void cancelaAlta();
        
        //IniciarPartida
	set<string> listaJugadoresSus(string NomVJ);
	set<DtPartidaIndividual*> listaPartidasIndividualesTerminadas();
	void iniciadaP(Partida* p);
	map<string, InfoPartidaMulti> getInfoJugadores(DtFechaHora f, set<string> mails);
};

#endif
