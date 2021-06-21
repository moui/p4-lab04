#ifndef IPARTIDA
#define IPARTIDA

#include <string>
#include <set>

#include "../datatypes/DtPartidaIndividual.h"
#include "../datatypes/DtPartidaMultijugador.h"
#include "../datatypes/DtPartida.h"

using namespace std;

class IPartida //aca
{
    public:
        IPartida();
        virtual ~IPartida();

        virtual set<DtPartidaIndividual*> partidasIndFinalizadas(string nombreVideojuego) = 0;

        virtual void altaPartida(DtPartida* partida) = 0;
        
        //virtual void cancelarIniciarPartida() = 0;

       /* virtual void iniciarPartida();
        virtual void abandonarPartidaMultijugador();
        virtual void FinalizarPartida();
        virtual void RealizarComentario();

        virtual void crearPartida(string nombreVJ);
        virtual void partidaAContinuar(float id);
        virtual void listaJugUnidos(set<string> nicknames);
        virtual set<string> listaJugSuscriptos();
        virtual void confirmarIniciarPartida();
        virtual set<DtPartidaIndividual> listaPartidasIndTer();
        virtual void enVivo(bool enVivo);
        virtual void cancelarIniciarPartida();
        virtual set<DtPartida> listaPartidasIniciadas(string nickname);
        virtual void finalizarPartida(float id);
        virtual void cancelarFinalizarPartida(); */

        //FINALIZAR PARTIDA

        virtual set<DtPartida*> listaPartidasIniciadasSinFinalizar()=0;

};

#endif