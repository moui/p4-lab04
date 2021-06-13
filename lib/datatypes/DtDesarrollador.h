#ifndef DT_DESARROLLADOR
#define DT_DESARROLLADOR

#include "DtUsuario.h"

#include <string>

using std::string;

class DtDesarrollador : public DtUsuario
{
  private:
    string empresa;

  public:
    // Contructor y destructor
    DtDesarrollador(string email, string empresa);
    ~DtDesarrollador();
    // Declaracion de funcion pura de DtUsuario
    void abstracta(); 
    // Getters
    string getEmpresa();
};

#endif
