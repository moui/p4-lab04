#ifndef IUSUARIO
#define IUSUARIO

#include <string>
#include <set>
#include "../datatypes/DtUsuario.h"
#include "../datatypes/DtVideojuegoSuscripcion.h"
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


        virtual TipoEstado JuegoSuscribirse(string nomVJ)=0;
        virtual set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesActivas()=0;
        virtual set<DtVideojuegoSuscripcion*> listarVideojuegoSuscripcionesNoActivas()=0;
};

#endif