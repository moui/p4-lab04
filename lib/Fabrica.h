#ifndef FABRICA
#define FABRICA

#include "IUsuario.h"
#include "CtrlUsuario.h"

using namespace std;

// se implementa como un singleton

class Fabrica
{
    private:
	    static Fabrica * instancia;
	    Fabrica();

    public:
        ~Fabrica();
	    static Fabrica * getInstancia();
	    
        IUsuario * getIUsuario();
};

#endif