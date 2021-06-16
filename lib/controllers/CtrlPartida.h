#ifndef CTRLPARTIDA
#define CTRLPARTIDA

#include "../interfaces/IPartida.h"
#include "../datatypes/DtPartidaIndividual.h"
#include "../datatypes/DtPartida.h"
#include "../PartidaIndividual.h"
#include "../PartidaMultijugador.h"
#include "../controllers/CtrlUsuario.h"
#include "../controllers/CtrlVideojuego.h"
#include "../manejadores/ManejadorPartida.h"
#include "../Jugador.h"
#include "../Fabrica.h"
#include "../interfaces/IUsuario.h"
#include <set>
#include <string>

using namespace std;

class CtrlPartida : public IPartida
{
    private:
        set<PartidaIndividual*> partidasI;
        set<PartidaMultijugador*> partidasM;
	float cantP;

        static CtrlPartida * instancia;
        CtrlPartida();
	
	ManejadorPartida* manejadorPartida;
	
	//Memoria
	string nomVJ;
	float f;
	bool* enVivo;
	set<string> mails;

    public:
        ~CtrlPartida();

        static CtrlPartida * getCtrlPartida();

	ManejadorPartida* getManejadorPatida();

        void crearPartida(string nombreVJ);
        void partidaAContinuar(float id);
        void listaJugUnidos(set<string> Mails);
        set<string> listaJugSuscriptos();
        void confirmarIniciarPartida(DtFechaHora inicio);
        set<DtPartidaIndividual*> listaPartidasIndTer();
        void ENVivo(bool EnVivo);
        void cancelarIniciarPartida();
        set<DtPartida> listaPartidasIniciadas(string nickname);
        void finalizarPartida(float id);
        void cancelarFinalizarPartida(); 

};

#endif
