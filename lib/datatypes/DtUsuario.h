#ifndef DT_USUARIO
#define DT_USUARIO

#include <string>

using std::string;

class DtUsuario
{
  protected:
    string email;

  public:
    // Constructor y destructor
    DtUsuario(string email);
    virtual ~DtUsuario();
    
    virtual void abstracta() = 0; // Funcion virtual pura => DtUsuario es abstracta
    
    // Getters
    string getEmail();
};

#endif