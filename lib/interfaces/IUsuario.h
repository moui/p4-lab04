#ifndef IUSUARIO
#define IUSUARIO

#include <string>

using namespace std;

class IUsuario
{
    public:
        virtual ~IUsuario();

        virtual void altaUsuario() = 0;
        virtual DtUsuario iniciarSesion(string mail, string contrasena) = 0;

        virtual void ingresaDatosUsuario(string nmail, string ncontrasena) = 0;
        virtual void ingresaDatosJugador(string nnickname, string ndescipcion) = 0;
        virtual void ingresaDatosDesarrollador(string nempresa) = 0;
        virtual void confirmaAltaDesarrollador() = 0;
        virtual void confirmaAltaJugador() = 0;
        virtual void cancelaAlta() = 0;
};

#endif