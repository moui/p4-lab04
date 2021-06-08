#include "../lib/Videojuego.h"

Videojuego::Videojuego(std::string nombre, Partida **partidas)
{
  this->nombre = nombre;
  this->tiene = partidas;
  return;
}


    //getters

    string Videojuego::getNombreVJ(){
        return this->nombre;
        }

    Partida ** Videojuego::getTienePartida(){
        return this->tiene;
    }

    //setters

    void Videojuego::setNombreVJ(string nombreVJ){
        this->nombre=nombreVJ;
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

