#ifndef FECHA_SISTEMA
#define FECHA_SISTEMA

#include "../datatypes/DtFechaHora.h"

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