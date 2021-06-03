#ifndef DT_PARTIDAINDIVIDUAL
#define DT_PARTIDAINDIVIDUAL

#include "DtPartida.h"
#include <iostream>

class DtPartidaIndividual : public DtPartida
{
  private:
    bool continuaPartidaAnterior;

  public:
    DtPartidaIndividual(DtFechaHora ,float ,bool );
    // Getters
    bool getContinuaPartidaAnterior();


    friend  std::ostream& operator<<(std::ostream& out, const DtPartidaIndividual& dt);
};

#endif
