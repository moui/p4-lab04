#ifndef MANEJADORPARTIDA
#define MANEJADORPARTIDA

#include "../Partida.h"
#include "../PartidaIndividual.h"
#include "../PartidaMultijugador.h"
#include "../controllers/CtrlUsuario.h"

#include <map>

using namespace std;
 
class ManejadorPartida {
	private:
		// Singleton
        static ManejadorPartida* instancia;
        // Constructor
       	ManejadorPartida();
       	// Members
		map<float, PartidaIndividual*> partidasI;
		map<float, PartidaIndividual*>::iterator itPI;

		map<float, PartidaMultijugador*> partidasM;
		map<float, PartidaMultijugador*>::iterator itPM;
	public:
		// GetInstance
        static ManejadorPartida* getInstancia();

        // Destructor
        ~ManejadorPartida();

		//Getters y Setters
		PartidaIndividual* getPI(float id);
		PartidaMultijugador* getPM(float id);
		void AgregarPartidaIndividual(float id, PartidaIndividual* pi);
		void AgregarPartidaMultijugador(float id, PartidaMultijugador* pm);

};

#endif
