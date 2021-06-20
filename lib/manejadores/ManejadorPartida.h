#ifndef MANEJADORPARTIDA
#define MANEJADORPARTIDA

#include "../Partida.h"
#include "../PartidaIndividual.h"
#include "../PartidaMultijugador.h"
#include "../controllers/CtrlUsuario.h"

#include <map>
#include <string>
#include <set>

using namespace std;
 
class PartidaMultijugador;
class PartidaIndividual;

class ManejadorPartida {
	private:
		// Singleton
        static ManejadorPartida* instancia;
        // Constructor
       	ManejadorPartida();
       	// Member 
		map<int, PartidaIndividual*> partidasI;
		map<int, PartidaIndividual*>::iterator itPI;

		map<int, PartidaMultijugador*> partidasM;
		map<int, PartidaMultijugador*>::iterator itPM;
	public:
		// GetInstance
        static ManejadorPartida* getInstancia();

        // Destructor
        ~ManejadorPartida();

		//Getters y Setters
		PartidaIndividual* getPI(int id);
		PartidaMultijugador* getPM(int id);
		void AgregarPartidaIndividual(int id, PartidaIndividual* pi);
		void AgregarPartidaMultijugador(int id, PartidaMultijugador* pm);


		//ABANDONAR PARTIDA MJ

		void ConfirmarAbandonarPartida(string mail, int partidaMJ);
		set<DtPartidaMultijugador*> listarPartidasMultijugadorUnidas(string mailJugador);

};

#endif
