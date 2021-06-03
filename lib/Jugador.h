#ifndef JUGADOR
#define JUGADOR

#include <string>

class Partida;
class PartidaMultijugador;

using std::string;

class Jugador
{
  private:
    std::string nickname;
    std::string contrasena;
    int edad;
    Partida** iniciada;
    PartidaMultijugador** unen;

  public:
    Jugador(string, string, int, Partida** , PartidaMultijugador** );
    ~Jugador();

    // Getters
    std::string getNickname();
    std::string getContrasena();
    int getEdad();
    Partida** getPartidasIniciadas();
    PartidaMultijugador** getPartidasMultijugador();

    // Setters
    void setNickname(string nickname);
    void setContrasena(string contrasena);
    void setEdad(int edad);
    void setPartidasIniciadas(Partida** iniciadas);
    void setPartidasMultijugador(PartidaMultijugador** partidasMultijugador);
};

#endif
