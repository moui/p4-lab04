#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include "Partida.h"
#include "datatypes/TipoPuntaje.h"
#include "datatypes/DtDescripcionSuscripcion.h"
#include "DescripcionSuscripcion.h"
#include "Categoria.h"
#include <string>
#include <set>

using namespace std;

// class Partida;

class Videojuego
{
  private:
    string nombre, descripcion;

    float costo1, costo3, costo12, costoV;

    Partida **tiene;
    set <DescripcionSuscripcion*> descSuscripcionVJ;
    set <DescripcionSuscripcion*>::iterator itdsVJ;

    set<string> suscritos;

    set<Categoria*> categoriasvj;
    set<Categoria*>::iterator itcatvj;
  public:
    //Videojuego(string, Partida **);
    Videojuego(string , string , float , float , float , float, set<Categoria*>);
    ~Videojuego();
    

    //getters

    string getNombreVJ();

    Partida ** getTienePartida();

    float getCosto1();
    float getCosto3();
    float getCosto12();
    float getCostoV();

    set<Categoria*> getCategoriasVJ(); 

    DtDescripcionSuscripcion* getDatosDescripcionSuscripcion(TipoPeriodo p);


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

    void setCategoriasVJ(set<Categoria*> catvj); 

    void agregarDescripcionSuscripcion(DescripcionSuscripcion* ds);

    //TJS

    void agregarSuscrito(string nomJ);
    int getSuscritos();

};

#endif
