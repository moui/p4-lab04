#ifndef FABRICA
#define FABRICA

#include "interfaces/IUsuario.h"
#include "controllers/CtrlUsuario.h"

using namespace std;

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

        static void destruir();
};

#endif