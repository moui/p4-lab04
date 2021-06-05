#ifndef CTRLUSUARIO
#define CTRLUSUARIO

#include "IUsuario.h"
#include "Jugador.h"
#include "Desarrollador.h"
#include <set>

using namespace std;

class CtrlUsuario : public IUsuario
{
    private:
        set<Jugador*> jugadores;
        set<Desarrollador*> desarrolladores;

        static CtrlUsuario * instancia;
        CtrlUsuario();

        Usuario * sesionActiva;

    public:
        ~CtrlUsuario();

        Usuario getSesionActiva();
        static CtrlUsuario * getCtrlUsuario();

        void confirmaAltaJugador();
        void cancelaAltaJugador();
        void ingresaNicknameJugador(string nickname);
        void ingresaDatosUauario(string mail, string contrasena);
        void ingresaNombreEmpresa(string nombre);
        void confirmaAltaDesarrollador();
        void cancelaAltaDesarrollador();
        set<string> listarVideojuegosPublicados();
        void suscribirse(string nombre);
        void cancelarOperacion();
        void altaSuscripcion();
};

#endif