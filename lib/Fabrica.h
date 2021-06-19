#ifndef FABRICA
#define FABRICA

#include "interfaces/IUsuario.h"
#include "interfaces/IVideojuego.h"
#include "interfaces/IPartida.h"
#include "controllers/CtrlUsuario.h"
#include "controllers/CtrlVideojuego.h"
#include "controllers/CtrlPartida.h"

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
        IPartida* getIPartida();
        // GetInstance
	    static Fabrica* getInstancia();

        static void destruir();
};

#endif