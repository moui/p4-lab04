#ifndef FECHA_SISTEMA
#define FECHA_SISTEMA

#include "../datatypes/DtFechaHora.h"

class FechaSistema
{
    private:
        static FechaSistema* instancia;
        FechaSistema();

        DtFechaHora* fecha;

    public:
        static FechaSistema* getInstancia();
        ~FechaSistema();

        // Getters y setters
        DtFechaHora* getFecha();
        void setFecha(DtFechaHora* nuevaFecha);
};


#endif