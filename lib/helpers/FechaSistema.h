#ifndef FECHA_SISTEMA
#define FECHA_SISTEMA

#include "../datatypes/DtFechaHora.h"

#include <ctime>

using std::time_t;

class FechaSistema
{
    private:
        DtFechaHora* fecha;

    public:
        FechaSistema();
        ~FechaSistema();

        // Getters y setters
        DtFechaHora* getFecha();
        void setFecha(DtFechaHora* nuevaFecha);
};


#endif