#ifndef CTRLUSUARIO
#define CTRLUSUARIO

#include "../interfaces/IUsuario.h"
#include "../Jugador.h"
#include "../Desarrollador.h"

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

    public:
        // GetInstance
        static CtrlUsuario* getInstancia();
        // Destructor
        ~CtrlUsuario();
        // Getters
        Usuario* getSesionActiva();
        // Setters
        void setSesionActiva(Usuario* usuario);
        // Implementacion IUsuario
        void altaUsuario();
        void iniciarSesion();
};

#endif