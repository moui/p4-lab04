#include "../lib/Videojuego.h"

Videojuego::Videojuego(string nnombre, string ndescripcion, float costomensual, float costotrimestral, float costoanual, float costovitalicia, set<Categoria*> ncats){
 this->nombre = nnombre;
 this->descripcion = ndescripcion;
 this->costo1 = costomensual;
 this->costo3 = costotrimestral;
 this->costo12 = costoanual;
 this->costoV = costovitalicia;
 this->categoriasvj = ncats;
}

//getters

DtDescripcionSuscripcion* Videojuego::getDatosDescripcionSuscripcion(TipoPeriodo p)
{
    DtDescripcionSuscripcion* res;
    float cost;
    switch (p)
    {
        case TipoPeriodo::Mensual : cost=this->costo1; break;
        case TipoPeriodo::Trimestral : cost=this->costo3; break;
        case TipoPeriodo::Anual : cost=this->costo12; break;
        case TipoPeriodo::Vitalicia : cost=this->costoV; break;
        default: throw invalid_argument("Periodo no valido \n");
    }

    string nomVJ = this->nombre;
    res = new DtDescripcionSuscripcion(nomVJ, cost, p);
    return res;
   
}

string Videojuego::getNombreVJ(){
    return this->nombre;
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

    return new DtVideojuego(nombre, descripcion, costo1, costo3, costo12, costoV, dtCategorias);
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