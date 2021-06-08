#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include "Partida.h"
#include <string>
#include <set>

using std::string;

// class Partida;

class Videojuego
{
  private:
    std::string nombre;

    Partida **tiene;

  public:
    Videojuego(std::string, Partida **);
    ~Videojuego();
    

    //getters

    std::string getNombreVJ();

    Partida ** getTienePartida();


    //setters

    void setNombreVJ(string);
    void setTienePartida(Partida **);
    void setPuntaje(TipoPuntaje);
    void setPartida(Partida*);
    void setCategoria(Categoria*)
};

#endif
