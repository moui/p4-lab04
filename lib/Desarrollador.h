#ifndef DESARROLLADOR
#define DESARROLLADOR

#include <string>
#include "Usuario.h"

using namespace std;

class Desarrollador : public Usuario
{
  private:
    string empresa;

  public:
    Desarrollador(string email, string contrasena, string empresa);
    ~Desarrollador();

    // Getters
    string getEmpresa();
 
    // Setters
    void setEmpresa(string empresa);
};

#endif
