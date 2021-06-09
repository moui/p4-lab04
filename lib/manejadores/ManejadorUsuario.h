#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO

#include "../Jugador.h"
#include "../Desarrollador.h"

#include <string>
#include <map>

using namespace std;

// Singleton.
class ManejadorUsuario {
    private:
        // Singleton
        static ManejadorUsuario* instancia;
        // Constructor
        ManejadorUsuario();
        // Member
        map<string, Desarrollador> desarrolladores;
        map<string, Jugador> jugadores;


    public:
        // GetInstance
        static ManejadorUsuario* getInstancia();
        // Destructor
        ~ManejadorUsuario();

        // Getters y Setters
        Usuario* buscarUsuario(string clave);
        void agregarUsuario(Usuario* usuario);

};

#endif