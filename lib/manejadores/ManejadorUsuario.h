#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO

#include "../Usuario.h"
#include "../Jugador.h"
#include "../Desarrollador.h"

#include <string>
#include <map>

using namespace std;

// Singleton.
class ManejadorUsuario {
    private:
        // Member
        map<string, Desarrollador*> desarrolladores;
        map<string, Desarrollador*>::iterator itd;
        map<string, Jugador*> jugadores;
        map<string, Jugador*>::iterator itj;

    public:
        // Constructor
        ManejadorUsuario();
        // Destructor
        ~ManejadorUsuario();

        // Getters y Setters
        Usuario* buscarUsuario(string clave);
        void agregarDesarrollador(string clave, Desarrollador* des);
        void agregarJugador(string clave, Jugador* jug);
        bool existeJugador(string nickname);
        void borrarUsuario(string clave);
       // Usuario* autenticarUsuario(string mail, string contrasena);
};

#endif