#ifndef FABRICA
#define FABRICA

#include "interfaces/IUsuario.h"
#include "controllers/CtrlUsuario.h"

using namespace std;

//preguntar en el monitoreo si es correcto que la fecha y hora del sistema se alamcene en la fabrica
// preguntar si hay clase sistema o solo se ponene en el main las interfaces y la fabrica

// Singleton
class Fabrica
{
    private:
	    static Fabrica* instancia;
        // Constructor
	    Fabrica();

    public:
        // Destructor
        ~Fabrica();
        // GetInterfaces
        IUsuario* getIUsuario();
        // GetInstance
	    static Fabrica* getInstancia();
};

#endif