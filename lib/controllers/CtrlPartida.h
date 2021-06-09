#ifndef CTRLPARTIDA
#define CTRLPARTIDA

#include "../interfaces/IPartida.h"
#include "../datatypes/DtPartidaIndividual.h"
#include "../datatypes/DtPartida.h"
#include "../PartidaIndividual.h"
#include "../PartidaMultijugador.h"
#include <set>

using namespace std;

class CtrlPartida : public IPartida
{
    private:
        set<PartidaIndividual*> partidasI;
        set<PartidaMultijugador*> partidasM;

        static CtrlPartida * instancia;
        CtrlPartida();


    public:
        ~CtrlPartida();

        static CtrlPartida * getCtrlPartida();

        void crearPartida(string nombreVJ);
        void partidaAContinuar(float id);
        void listaJugUnidos(set<string> nicknames);
        set<string> listaJugSuscriptos();
        void confirmarIniciarPartida();
        set<DtPartidaIndividual> listaPartidasIndTer();
        void enVivo(bool enVivo);
        void cancelarIniciarPartida();
        set<DtPartida> listaPartidasIniciadas(string nickname);
        void finalizarPartida(float id);
        void cancelarFinalizarPartida(); 

};

#endif
