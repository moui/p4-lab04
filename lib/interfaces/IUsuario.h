#ifndef IUSUARIO
#define IUSUARIO

#include <string>
#include <set>
#include "../datatypes/DtUsuario.h"
#include "../datatypes/DtEstadistica.h"
#include "../datatypes/DtVideojuego.h"
#include "../datatypes/DtVideojuegoSuscripcion.h"
#include "../datatypes/DtPartidaMultijugador.h"
#include "../datatypes/TipoEstado.h"

using namespace std;

class IUsuario
{
    public:
        virtual ~IUsuario();

        virtual void altaUsuario() = 0;
        virtual DtUsuario* iniciarSesion(string mail, string contrasena) = 0;

        virtual void ingresaDatosUsuario(string nmail, string ncontrasena) = 0;
        virtual void ingresaDatosJugador(string nnickname, string ndescipcion) = 0;
        virtual void ingresaDatosDesarrollador(string nempresa) = 0;
        virtual void confirmaAltaDesarrollador() = 0;
        virtual void confirmaAltaJugador() = 0;
        virtual void cancelaAlta() = 0;

        //Suscribirse
        virtual void AltaSuscripcion()=0;
        virtual void CancelarOperacion()=0;
        virtual void SuscribirseVideojuego(int a, int b, string nomVJ)=0;
        virtual void CancelarSuscripcion(string nomVJ)=0;
        virtual TipoEstado JuegoSuscribirse(string nomVJ)=0;
        virtual set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesActivas()=0;
        virtual set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesNoActivas()=0;

        //seleccionar estadisticas

        virtual void listarEstadisticas()=0;
        virtual void seleccionarEstadisticas(bool s1, bool s2)=0;

        //CONSULTAR ESTADISTICA

        virtual set<string> listarVideojuegosPublicados() = 0;
        virtual set<DtEstadistica*> ConsultarEstadisticas(string nomVJ)=0;

        //ABANDONAR PARTIDA MULTIJUGADOR

        virtual set<DtPartidaMultijugador*> listarPartidasMultijugadorUnidas()=0;
        virtual void ConfirmarAbandonarPartida(int partidaMJ)=0;


        //eliminar
        virtual set<DtVideojuego*> listarVideoJuegosDesarrollador() = 0;
};

#endif