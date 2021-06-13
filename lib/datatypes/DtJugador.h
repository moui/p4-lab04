#ifndef DT_JUGADOR
#define DT_JUGADOR

#include "DtUsuario.h"

#include <string>

using std::string;

class DtJugador : public DtUsuario
{
  private:
    string nickname;
    string descripcion;

  public:
    // Contructor y destructor
    DtJugador(string email, string nickname, string descripcion);
    ~DtJugador();
    // Declaracion de funcion pura de DtUsuario
    void abstracta(); 
    // Getters
    string getNickname();
    string getDescripcion();
};

#endif
