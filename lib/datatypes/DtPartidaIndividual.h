#ifndef DT_PARTIDAINDIVIDUAL
#define DT_PARTIDAINDIVIDUAL

#include "DtPartida.h"
#include <iostream>

using std::ostream;
using std::endl;

class DtPartidaIndividual : public DtPartida
{
    private:
        int* continuacion;

    public:
        // Contructor y destructor
        DtPartidaIndividual(int identificador,float duracion, DtFechaHora* fecha, DtFechaHora* fecha_fin,  string n, int* continuacion);
        DtPartidaIndividual(int identificador, DtFechaHora* fecha,  string n, int* continuacion);
        ~DtPartidaIndividual();
        // Declaracion de funcion pura de DtPartida
        void abstracta(); 
        // Getters
        int* getContinuacion();
        // Sobrecarga del operador de insercion <<
        friend  ostream& operator<<(ostream& os, const DtPartidaIndividual& dtPartidaInd);
};

#endif

