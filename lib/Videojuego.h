#ifndef VIDEOJUEGO
#define VIDEOJUEGO

#include "Partida.h"
#include "datatypes/TipoPuntaje.h"
#include "datatypes/DtDescripcionSuscripcion.h"
#include "datatypes/DtVideojuego.h"
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

    float costo1, costo3, costo12, costoV, ppromedio;

    set<string> suscritos;

    set<Categoria*> categoriasvj;
    set<Categoria*>::iterator itcatvj;

    map<string, TipoPuntaje> puntajesjugadores;
    map<string, TipoPuntaje>::iterator itpj;
    
  public:
    //Videojuego(string, Partida **);
    Videojuego(string , string , float , float , float , float, set<Categoria*>);
    ~Videojuego();
    

    //getters

    string getNombreVJ();
    string getDescripcionVJ();
    float getCosto1();
    float getCosto3();
    float getCosto12();
    float getCostoV();

    set<Categoria*> getCategoriasVJ();

    map<string, TipoPuntaje> getPuntajesVJ(); 

    DtVideojuego* getDatatype();

    float getPromedio();

    //setters

    void setNombreVJ(string);
    void setDescripcionVJ(string);
    void setPartida(Partida*);
    void setCategoria(Categoria*);

    void setCosto1(float c1);
    void setCosto3(float c3);
    void setCosto12(float c12);
    void setCostoV(float cV);

    void calcularPromedio();

    void setCategoriasVJ(set<Categoria*> catvj); 

    void setPuntajeVJ(string, TipoPuntaje);

    //TJS

    void agregarSuscrito(string nomJ);
    int getSuscritos();

};

#endif
