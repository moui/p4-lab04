#include "../../lib/controllers/CtrlPartida.h"

using namespace std;

CtrlPartida * CtrlPartida::instancia = NULL;
    
CtrlPartida::~CtrlPartida(){

}
    
CtrlPartida * CtrlPartida::getCtrPartida(){
    if (instancia == NULL){
        instancia = new CtrlCtrlPartida();
    }
    return instancia;
}

void crearPartida(string nombreVJ){

}

void partidaAContinuar(float id){

}
void listaJugUnidos(set<string> nicknames){

}
set<string> listaJugSuscriptos(){

}
void confirmarIniciarPartida(){

}
set<DtPartidaIndividual> listaPartidasIndTer(){

}
void enVivo(bool enVivo){

}
void cancelarIniciarPartida(){

}
set<DtPartida> listaPartidasIniciadas(string nickname){

}
void finalizarPartida(float id){

}
void cancelarFinalizarPartida(){

}

