#include "lib/Fabrica.h"

using namespace std;

Fabrica * Fabrica::instancia = NULL;

Fabrica::Fabrica() {}

Fabrica * Fabrica::getInstancia(){
	if (instancia == NULL) {
            instancia = new Fabrica();
	}
	return instancia;
}

Fabrica::~Fabrica(){

}

IUsuario *Fabrica::getIUsuario(){
    return CtrlUsuario::getCtrlUsuario();
}