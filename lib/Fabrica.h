#ifndef FABRICA
#define FABRICA

#include "interfaces/IUsuario.h"
#include "interfaces/IVideojuego.h"
#include "controllers/CtrlUsuario.h"
#include "controllers/CtrlVideojuego.h"

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
        IVideojuego* getIVideojuego();
        // GetInstance
	    static Fabrica* getInstancia();

        static void destruir();
};

#endif