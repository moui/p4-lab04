#ifndef CTRLUSUARIO
#define CTRLUSUARIO

#include "../interfaces/IUsuario.h"
#include "../Jugador.h"
#include "../Desarrollador.h"
#include "../manejadores/ManejadorUsuario.h"
#include "../datatypes/DtVideojuegoSuscripcion.h"
#include "../datatypes/DtPartidaMultijugador.h"
#include "../datatypes/DtDescripcionSuscripcion.h"
#include "../datatypes/DtSuscripcion.h"
#include "../datatypes/DtEstadistica.h"
#include "../datatypes/TipoEstado.h"
#include "../datatypes/TipoPago.h"
#include "../const/Constantes.h"
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

        DtSuscripcion* datosSuscripcion;
        TipoPago pagoSuscripcion;

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

        void SuscribirseVideojuego(int a, int b, string nomVJ);
        void ObtenerCatalogo(); 
        set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesActivas();
        set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesNoActivas();
        TipoEstado JuegoSuscribirse(string nomVJ);
        void CancelarOperacion();
        void CancelarSuscripcion(string nomVJ);
        void AltaSuscripcion();
        TipoEstado getEstadoSuscripcion(string nombreVideojuego);

        // SELECCIONAR ESTADISTICAS

        void listarEstadisticas();
        void seleccionarEstadisticas(bool s1, bool s2);

        // CONSULTAR ESTADISTICAS
        set<string> listarVideojuegosPublicados();
        set<DtEstadistica*> ConsultarEstadisticas(string nomVJ);
        
        // Caso de Uso Alta Usuario
        void ingresaDatosUsuario(string nmail, string ncontrasena);
        void ingresaDatosJugador(string nnickname, string ndescripcion);
        void ingresaDatosDesarrollador(string nempresa);
        void confirmaAltaDesarrollador();
        void confirmaAltaJugador();
        void cancelaAlta();

        set<DtVideojuego*> listarVideoJuegosDesarrollador();

        //ABANDONAR PARTIDA MJ
        set<DtPartidaMultijugador*> listarPartidasMultijugadorUnidas();
        void ConfirmarAbandonarPartida(int partidaMJ);

        void removerSuscripciones(string nombrevj);

        //FINALIZAR PARTIDA

        set<DtPartida*> listaPartidasIniciadasSinFinalizar();

};

#endif
