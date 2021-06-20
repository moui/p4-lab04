#ifndef DT_PARTIDA
#define DT_PARTIDA

#include "DtFechaHora.h"

class DtPartida
{
    protected:
        float identificador;
        float duracion;
        DtFechaHora fecha;
        string nomVJ;

    public:
        // Constructor y destructor
        DtPartida(float id, float duracion, DtFechaHora fecha);
        virtual ~DtPartida();

        virtual void abstracta() = 0; // Funcion virtual pura => DtPartida es abstracta
        // Getters
        string getNombreVJ();
        float getId();
        float getDuracion();
        DtFechaHora getFecha();
};

#endif
