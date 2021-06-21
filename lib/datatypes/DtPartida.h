#ifndef DT_PARTIDA
#define DT_PARTIDA

#include "DtFechaHora.h"

class DtPartida
{
    protected:
        int identificador;
        float duracion;
        DtFechaHora* fecha;
        DtFechaHora* fecha_fin;
        string nomVJ;

    public:
        // Constructor y destructor
        DtPartida(int id, float duracion, DtFechaHora* fecha, DtFechaHora* fecha_fin, string n);
        DtPartida(int id, DtFechaHora* fecha, string n);
        virtual ~DtPartida();

        virtual void abstracta() = 0; // Funcion virtual pura => DtPartida es abstracta
        // Getters
        string getNombreVJ();
        int getId();
        float getDuracion() const;
        DtFechaHora* getFecha();
        DtFechaHora* getFechaFin();

        friend  ostream& operator<<(ostream& os, const DtPartida& dtPartida);
};

#endif
