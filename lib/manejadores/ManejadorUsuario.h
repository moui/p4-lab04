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
        void agregarDesarrollador(string clave, Desarrollador* des);
        void agregarJugador(string clave, Jugador* jug);
        bool existeJugador(string nickname);
        void borrarUsuario(string clave);

        Jugador* buscarJugador(string clave);
        Desarrollador* buscarDesarrollador(string clave);

        bool existeUsuario(sting clave);

        bool autenticarJugador(string mail, string contrasena);
        bool autenticarDesarollador(string mail, string contrasena);
};

#endif