#ifndef IUSUARIO
#define IUSUARIO

#include <string>
#include <set>

using namespace std;

class IUsuario
{
    public:
        IUsuario();
        virtual ~IUsuario();

        virtual void altaUsuario();
        virtual void iniciarSesion();
        virtual void agregarCategoria();
        virtual void seleccionarEstadistica();
        virtual void consultarEstadistica();
        virtual void seguirJugador();

        virtual void confirmaAltaJugador();
        virtual void cancelaAltaJugador();
        virtual void ingresaDatosJugador(string nickname, string descripcion);
        virtual void ingresaDatosUsuario(string mail, string contrasena);
        virtual void ingresaDatosDesarrollador(string empresa);
        virtual void confirmaAltaDesarrollador();
        virtual void cancelaAltaDesarrollador();
        virtual set<string> listarVideojuegosPublicados();
        virtual void suscribirse(string nombre);
        virtual void cancelarOperacion();
        virtual void altaSuscripcion();       
        virtual bool 
};

#endif