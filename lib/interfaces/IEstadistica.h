#ifndef I_ESTADISTICA
#define I_ESTADISTICA

#include <string>
#include <set>
#include "../Videojuego.h"
#include "../datatypes/DtUsuario.h"
#include "../datatypes/DtEstadistica.h"
#include "../datatypes/TipoEstado.h"

using namespace std;

class IEstadistica
{
        public:
        
        virtual ~IEstadistica();

        virtual DtEstadistica* calcular(Videojuego* v)=0;

};

#endif