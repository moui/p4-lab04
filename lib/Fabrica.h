#ifndef FABRICA
#define FABRICA

#include "interfaces/IUsuario.h"
#include "CtrlUsuario.h"

using namespace std;

// se implementa como un singleton

//preguntar en el monitoreo si es correcto que la fecha y hora del sistema se alamcene en la fabrica
// preguntar si hay clase sistema o solo se ponene en el main las interfaces y la fabrica

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