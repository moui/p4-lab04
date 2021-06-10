#ifndef DT_PARTIDAINDIVIDUAL
#define DT_PARTIDAINDIVIDUAL

#include "DtPartida.h"
#include <iostream>

using std::ostream;
using std::endl;

class DtPartidaIndividual : public DtPartida
{
    private:
        PartidaIndividual* continuacion;

    public:
        // Contructor y destructor
        DtPartidaIndividual(float identificador,float duracion, DtFechaHora fecha, PartidaIndividual* continuacion);
        ~DtPartidaIndividual();
        // Declaracion de funcion pura de DtPartida
        void abstracta(); 
        // Getters
        float* getContinuacion();
        // Sobrecarga del operador de insercion <<
        friend  ostream& operator<<(ostream& os, const DtPartidaIndividual& dtPartidaInd);
};

#endif

