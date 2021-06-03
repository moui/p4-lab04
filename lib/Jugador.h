#ifndef JUGADOR
#define JUGADOR

#include <string>
#include "Usuario.h"

class Partida;
class PartidaMultijugador;

using namespace std;

class Jugador : public Usuario
{
  private:
    string nickname;
    int edad;
    Partida** iniciada;
    PartidaMultijugador** unen;

  public:
    Jugador(string, string, string, int, Partida** , PartidaMultijugador** );
    ~Jugador();

    // Getters
    string getNickname();
    int getEdad();
    Partida** getPartidasIniciadas();
    PartidaMultijugador** getPartidasMultijugador();

    // Setters
    void setNickname(string nickname);
    void setEdad(int edad);
    void setPartidasIniciadas(Partida** iniciadas);
    void setPartidasMultijugador(PartidaMultijugador** partidasMultijugador);
};

#endif
