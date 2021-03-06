#include "../lib/Videojuego.h"

Videojuego::Videojuego(string nnombre, string ndescripcion, float costomensual, float costotrimestral, float costoanual, float costovitalicia, set<Categoria*> ncats){
 this->nombre = nnombre;
 this->descripcion = ndescripcion;
 this->costo1 = costomensual;
 this->costo3 = costotrimestral;
 this->costo12 = costoanual;
 this->costoV = costovitalicia;
 this->categoriasvj = ncats;
 this->tothorasjuego = 0;
}

//getters

string Videojuego::getNombreVJ(){
    return this->nombre;
}

string Videojuego::getDescripcionVJ(){
    return this->descripcion;
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

set<Categoria*> Videojuego::getCategoriasVJ(){
    return this->categoriasvj;
}

//setters

void Videojuego::setNombreVJ(string nombreVJ){
    this->nombre=nombreVJ;
}

void Videojuego::setDescripcionVJ(string descripcionVJ){
    this->descripcion=descripcionVJ;
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

void Videojuego::setCategoriasVJ(set<Categoria*> cats){
    this->categoriasvj = cats;
}

// getDatatype
DtVideojuego* Videojuego::getDatatype()
{
    set<DtCategoria*> dtCategorias;
    
    for (itcatvj = categoriasvj.begin(); itcatvj != categoriasvj.end(); ++itcatvj)
    {
        Categoria* cat = *itcatvj;
        dtCategorias.insert(cat->getDtCategoria());
    }
    return new DtVideojuego(nombre, descripcion, costo1, costo3, costo12, costoV, dtCategorias, ppromedio, tothorasjuego);
}


Videojuego::~Videojuego()
{
};



 void Videojuego::agregarSuscrito(string nomJ)
 {
     suscritos.insert(nomJ);
 }

int Videojuego::getSuscritos()
 {
     return suscritos.size();
 }

map<string, TipoPuntaje> Videojuego::getPuntajesVJ(){
    return this->puntajesjugadores;
}

void Videojuego::setPuntajeVJ(string nombrejugador, TipoPuntaje puntaje){
    puntajesjugadores.insert( pair<string, TipoPuntaje>(nombrejugador, puntaje) );
}

void Videojuego::calcularPromedio(){
    float cant = puntajesjugadores.size();
    float sum = 0;
    for (itpj = puntajesjugadores.begin(); itpj != puntajesjugadores.end(); ++itpj)
    {
        switch (itpj->second)
        {
        case TipoPuntaje::uno:
            sum = sum + 1;
            break;
        case TipoPuntaje::dos:
            sum = sum + 2;
            break;
        case TipoPuntaje::tres:
            sum = sum + 3;
            break;
        case TipoPuntaje::cuatro:
            sum = sum + 4;
            break;
        case TipoPuntaje::cinco:
            sum = sum + 5;
            break;
        default:
            break;
        }
    }
    this->ppromedio = sum / cant;
}

float Videojuego::getPromedio(){
    return ppromedio;
}

float Videojuego::getTotalHorasJugadas(){
    return this->tothorasjuego;
}

void Videojuego::setTotalHorasJugadas(float tot){
    this->tothorasjuego = this->tothorasjuego + tot;
}