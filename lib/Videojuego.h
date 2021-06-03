#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include "datatypes/TipoJuego.h"
#include "Partida.h"
#include <string>

using std::string;

// class Partida;

class Videojuego
{
  private:
    std::string nombre;
    TipoJuego genero;
    Partida **tiene;

  public:
    Videojuego(std::string, TipoJuego, Partida **);
    ~Videojuego();
    

    //getters

    std::string getNombreVJ();
    TipoJuego getGenero();
    Partida ** getTienePartida();

    //setters

    void setNombreVJ(string);
    void setGenero(TipoJuego);
    void setTienePartida(Partida **);



};

#endif
