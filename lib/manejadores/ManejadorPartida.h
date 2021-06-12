#ifndef MANEJADORPARTIDA
#define MANEJADORPARTIDA

#include "../Partida.h"
#include "../PartidaIndividual.h"
#include "../PartidaMultijugador.h"

#include <map>

using namespace std;
 
class ManejadorPartida {
	private:
		 // Singleton
        	static ManejadorPartida* instancia;
        	// Constructor
       	ManejadorPartida();
       	// Member 
		map<float, PartidaIndividual> partidasI;
		map<float, PartidaIndividual>::Iterator itPI;

		map<float, PartidaMultijugador> partidasM;
		map<float, PartidaMultijugador>::Iterator itPM;
	public:
		// GetInstance
        	static ManejadorPartida* getInstancia();

        	// Destructor
        	~ManejadorPartida();

		//Getters y Setters
		PartidaIndividual* getPI(float id);
		PartidaMultijugador* getPM(float id);
		void AgregarPartidaIndividual(float id, PartidaIndividual pi);
		void AgregarPartidaMultijugador(float id, PartidaMultijugador pm);

}
