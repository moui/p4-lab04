#include "../lib/Fabrica.h"

// se implementa como un singleton, alternativa 1 del teorico

// Singleton
Fabrica* Fabrica::instancia = NULL;

// Constructor
Fabrica::Fabrica() 
{
}

//Destructor
Fabrica::~Fabrica()
{
}

// GetInstance
Fabrica * Fabrica::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new Fabrica();
    }
    return instancia;
}

// GetInterfaces
IUsuario *Fabrica::getIUsuario()
{
    return CtrlUsuario::getInstancia();
}