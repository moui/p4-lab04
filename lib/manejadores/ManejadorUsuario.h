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
        // Singleton
        static ManejadorUsuario* instancia;
        // Constructor
        ManejadorUsuario();
        // Member
        map<string, Desarrollador> desarrolladores;
        map<string, Desarrollador>::iterator itd;
        map<string, Jugador> jugadores;
        map<string, Jugador>::iterator itj;


    public:
        // GetInstance
        static ManejadorUsuario* getInstancia();
        // Destructor
        ~ManejadorUsuario();

        // Getters y Setters
        Usuario* buscarUsuario(string clave);
        void agregarUsuario(Usuario* usuario);
        void borrarUsuario(string clave);

};

#endif