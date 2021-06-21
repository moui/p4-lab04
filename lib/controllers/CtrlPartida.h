#ifndef CTRLPARTIDA
#define CTRLPARTIDA

#include "../interfaces/IPartida.h"
#include "../datatypes/DtPartidaIndividual.h"
#include "../datatypes/DtPartidaMultijugador.h"
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

class CtrlUsuario;
class CtrlVideojuego;
class PartidaIndividual;
class PartidaMultijugador;
class ManejadorPartida;

class CtrlPartida : public IPartida
{
    private:
        static CtrlPartida * instancia;
        CtrlPartida();
	
	    ManejadorPartida* manejadorPartida;
	
	    //Memoria
        /*
	    string nomVJ;
	    float f;
	    bool* enVivo;
	    set<string> mails;
        */

    public:
        ~CtrlPartida();

        static CtrlPartida* getCtrlPartida();

	    ManejadorPartida* getManejadorPatida();

        void cancelarIniciarPartida() {} // Implementacion IPartida

        // Devuelve set<DtPartidaInd*> con las partidas individuales
            // finalizadas del jugador que inicio sesion.
        set<DtPartidaIndividual*> partidasIndFinalizadas(string nombreVideojuego); 
        
        

        void altaPartida(DtPartida* datosPartida);
        void finalizarPartida(DtFechaHora f, int id);

        /*
        void crearPartida(string nombreVJ);
        void partidaAContinuar(float id);
        void listaJugUnidos(set<string> Mails);
        set<string> listaJugSuscriptos();
        void confirmarIniciarPartida(DtFechaHora inicio);
        set<DtPartidaIndividual*> listaPartidasIndTer();
        void ENVivo(bool EnVivo);
        //void cancelarIniciarPartida();
        void finalizarPartida(DtFechaHora f, float id);
        void cancelarFinalizarPartida();

        */

        //ABANDONAR PARTIDA MULTIJUGADOR

        set<DtPartidaMultijugador*> listarPartidasMultijugadorUnidas(string mailJugador);
        void ConfirmarAbandonarPartida(string mail, int partidaMJ);

        //FINALIZAR PARTIDA

        set<DtPartida*> listaPartidasIniciadasSinFinalizar();
};

#endif
