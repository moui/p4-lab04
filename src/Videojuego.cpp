#include "../lib/Videojuego.h"

Videojuego::Videojuego(std::string nombre, TipoJuego genero, Partida **partidas)
{
  this->nombre = nombre;
  this->genero = genero;
  this->tiene = partidas;
  return;
}


    //getters

    string Videojuego::getNombreVJ(){
        return this->nombre;
        }


    TipoJuego Videojuego::getGenero(){
        return this->genero;
    }

    Partida ** Videojuego::getTienePartida(){
        return this->tiene;
    }

    //setters

    void Videojuego::setNombreVJ(string nombreVJ){
        this->nombre=nombreVJ;
    }

    void Videojuego::setGenero(TipoJuego t){
        this->genero=t;
    }


    void Videojuego::setTienePartida(Partida ** p){
        this->tiene=p;
    }


    Videojuego::~Videojuego(){
        int curr = 0;
        while (this->tiene[curr] != NULL)
            delete this->tiene[curr++];
        delete[] this->tiene;
    };

