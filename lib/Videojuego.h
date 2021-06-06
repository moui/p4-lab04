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
    std::string descripcion;
    set<Categoria*> categorias;
    set<Partida*> tiene;
    set<Puntaje*> Puntuaciones;

  public:
    Videojuego(std::string, Partida **, set<Categoria*>);
    ~Videojuego();
    

    //getters

    std::string getNombreVJ();
    TipoJuego getGenero();
    set<Partida*> getTienePartida();
    set<DtCategoria*> getCategorias();
    Puntaje* getPuntaje();

    //setters

    void setNombreVJ(string);
    void setGenero(TipoJuego);
    void setTienePartida(Partida **);
    void setPuntaje(TipoPuntaje);
    void setPartida(Partida*);
    void setCategoria(Categoria*)
};

#endif
