#ifndef DT_PARTIDAINDIVIDUAL
#define DT_PARTIDAINDIVIDUAL

#include "DtPartida.h"
#include <iostream>

using std::ostream;
using std::endl;

class DtPartidaIndividual : public DtPartida
{
    private:
        bool continuacion;

    public:
        // Contructor y destructor
        DtPartidaIndividual(float identificador,float duracion, DtFechaHora fecha, bool continuacion);
        ~DtPartidaIndividual();
        // Declaracion de funcion pura de DtPartida
        void abstracta(); 
        // Getters
        bool getContinuacion();
        // Sobrecarga del operador de insercion <<
        friend  ostream& operator<<(ostream& os, const DtPartidaIndividual& dtPartidaInd);
};

#endif

