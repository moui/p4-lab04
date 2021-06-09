#ifndef CTRLUSUARIO
#define CTRLUSUARIO

#include "../interfaces/IUsuario.h"
#include "../Jugador.h"
#include "../Desarrollador.h"

#include <string>

using namespace std;

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
        // "Memoria"
        string mail, contrasena, nickname, empresa, descripcion;

    public:
        // GetInstance
        static CtrlUsuario* getInstancia();
        // Destructor
        ~CtrlUsuario();

        // Getters y Setters
        Usuario* getSesionActiva();
        void setSesionActiva(Usuario* usuario);
        
        // Implementacion IUsuario
        void altaUsuario();
        void iniciarSesion();

        // Caso de Uso Alta Usuario
        void ingresaDatosUsuario(string nmail, string ncontrasena);
        void ingresaDatosJugador(string nnickname, string ndescripcion);
        void ingresaDatosDesarrollador(string nempresa);
        void confirmaAltaDesarrollador();
        void confirmaAltaJugador();
        void cancelaAlta();
};

#endif