#ifndef JUGADOR
#define JUGADOR

#include <string>
#include <map>
#include "Usuario.h"
#include "Partida.h"

using namespace std;

class Jugador : public Usuario
{
  private:
    string nickname;
    string descripcion;
    map<int,Partida*> inicio;

  public:
    // Constructor y destructor
    Jugador(string email, string contrasena, string nickname, string descripcion, map<int,Partida*> inicio);
    ~Jugador();

    // Getters
    string getNickname();
    string getDescripcion();
    map<int, Partida*> getInicioPartidas();

    // Setters
    void setNickname(string nickname);
    void setDescripcion(string descripcion);
    void setInicioPartidas(map<int,Partida*> inicio);
};

#endif
