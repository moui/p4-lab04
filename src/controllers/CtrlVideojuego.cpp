#include "../../lib/controllers/CtrlVideojuego.h"

using namespace std;
 //*
CtrlVideojuego * getCtrlVideojuego::instancia = NULL;

CtrlVideojuego::~CtrlVideojuego(){

}

CtrlVideojuego * CtrlVideojuego::getCtrlVideojuego(){
    if (instancia == NULL){
        instancia = new CtrlVideojuego();
    }
    return instancia;
}



set<string>listarVideoJuegosDesarrollador(){
  return "\n"
}

void CtrlVideojuego::videojuegoAEliminar(string nombre){

}

void CtrlVideojuego::cancelarEliminarVideoJuego(){

}

void CtrlVideojuego::confirmarEliminarVideoJuego(){

}

void CtrlVideojuego::ingresarDatosVideojuego(DtVideojuego datos){

}

set<DtCategoria>CtrlVideojuego::listarCategorias(){
  return NULL;
}


void CtrlVideojuego::seleccionarCategoria(string nombre){

}

DtVideojuego CtrlVideojuego::mostrarVideojuego(){
  return NULL;
}

void CtrlVideojuego::cancelaPublicarVideojuego(){
}

void CtrlVideojuego::confirmaPublicarVideojuego(){
}

void CtrlVideojuego::confirmaPublicarVideojuego(Videojuego * v){
}

set<DtVideojuegoSuscripcion> CtrlVideojuego::ObtenerCatalogo(){
  return NULL;
}

void CtrlVideojuego::SuscribirseVideojuego(TipoPago pago, TipoPeriodo periodo){
}

void CtrlVideojuego::AgregarSuscripcion(Suscripcion *s){
}

void CtrlVideojuego::AltaSuscripcion(){  *//