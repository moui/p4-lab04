#ifndef DT_PARTIDA
#define DT_PARTIDA

#include "DtFechaHora.h"

class DtPartida
{
    protected:
        int identificador;
        float duracion;
        DtFechaHora* fecha;
        string nomVJ;

    public:
        // Constructor y destructor
        DtPartida(int id, float duracion, DtFechaHora* fecha, string n);
        virtual ~DtPartida();

        virtual void abstracta() = 0; // Funcion virtual pura => DtPartida es abstracta
        // Getters
        string getNombreVJ();
        int getId();
        float getDuracion();
        DtFechaHora* getFecha();
};

#endif
