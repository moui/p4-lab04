#ifndef FECHA_SISTEMA
#define FECHA_SISTEMA

#include "../datatypes/DtFechaHora.h"

#include <ctime>

using std::time_t;

class FechaSistema
{
    private:
        DtFechaHora* fechaInicial;
        DtFechaHora* fechaActual;
        time_t inicio;

    public:
        FechaSistema();
        ~FechaSistema();

        // Getters y setters
        DtFechaHora* getFechaActual();
        void setFechaInicial(DtFechaHora* nuevaFecha);

        // Operaciones
        void actualizarFechaActual();

        time_t DtFechaHora__to__time_t(DtFechaHora* fecha);
        DtFechaHora* time_t__to__DtFechaHora(time_t fecha);
};


#endif