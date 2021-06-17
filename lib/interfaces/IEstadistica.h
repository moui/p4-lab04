#ifndef I_ESTADISTICA
#define I_ESTADISTICA

#include <string>
#include <set>
#include "../datatypes/DtUsuario.h"
#include "../datatypes/DtEstadistica.h"
#include "../datatypes/TipoEstado.h"

using namespace std;

class IEstadistica
{
        public:
        
        virtual ~IEstadistica();

       // virtual DtEstadistica* calcular()=0;

};

#endif