#ifndef MANEJADORUSUARIO
#define MANEJADORUSUARIO

#include "../Usuario.h"
#include "../Jugador.h"
#include "../Desarrollador.h"
#include "../datatypes/DtPartidaIndividual.h"
#include "../datatypes/DtPartidaMultijugador.h"
#include "../datatypes/DtPartida.h"

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
        //IniciarPartida
    	set<string> listaJugadoresSus(string NomVJ);
	set<DtPartidaIndividual*> partidasIndividualesFinalizadas(string nickname);
	void iniciadaP(string clave, Partida* p);

        Jugador* buscarJugador(string clave);
        Desarrollador* buscarDesarrollador(string clave);

        bool existeUsuario(string clave);

        bool autenticarJugador(string mail, string contrasena);
        bool autenticarDesarollador(string mail, string contrasena);
};

#endif
