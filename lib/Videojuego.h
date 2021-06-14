#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include "Partida.h"
#include "datatypes/TipoPuntaje.h"
#include "DescripcionSuscripcion.h"
#include "Categoria.h"
#include <string>
#include <set>

using namespace std;

// class Partida;

class Videojuego
{
  private:
    string nombre;
    string descripcion;

    float costo1;
    float costo3;
    float costo12;
    float costoV;

    Partida **tiene;
    set <DescripcionSuscripcion*> descSuscripcionVJ;
    set <DescripcionSuscripcion*>::iterator itdsVJ;

  public:
    Videojuego(string, Partida **);
    ~Videojuego();
    

    //getters

    string getNombreVJ();

    Partida ** getTienePartida();

    float getCosto1();
    float getCosto3();
    float getCosto12();
    float getCostoV(); 


    //setters

    void setNombreVJ(string);
    void setTienePartida(Partida **);
    void setPuntaje(TipoPuntaje);
    void setPartida(Partida*);
    void setCategoria(Categoria*);

    void setCosto1(float c1);
    void setCosto3(float c3);
    void setCosto12(float c12);
    void setCostoV(float cV);

    void agregarDescripcionSuscripcion(DescripcionSuscripcion* ds);

};

#endif
