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

    float Videojuego::getCosto1(){
        return this->costo1;
    }
    float Videojuego::getCosto3(){
        return this->costo3;
    }
    float Videojuego::getCosto12(){
        return this->costo12;
    }
    float Videojuego::getCostoV(){
        return this->costoV;
    } 

    //setters

    void Videojuego::setNombreVJ(string nombreVJ){
        this->nombre=nombreVJ;
    }

    void Videojuego::setTienePartida(Partida ** p){
        this->tiene=p;
    }

    void Videojuego::setCosto1(float c1){
        this->costo1=c1;
    }
    void Videojuego::setCosto3(float c3){
        this->costo3=c3;
    }
    void Videojuego::setCosto12(float c12){
        this->costo12=c12;
    }
    void Videojuego::setCostoV(float cV){
        this->costoV=cV;
    }


    Videojuego::~Videojuego(){
        int curr = 0;
        while (this->tiene[curr] != NULL)
            delete this->tiene[curr++];
        delete[] this->tiene;
    };

void Videojuego::agregarDescripcionSuscripcion(DescripcionSuscripcion* ds){
    descSuscripcionVJ.insert(ds);
}

