#include "../../lib/controllers/CtrlVideojuego.h"

using namespace std;
 //*
CtrlVideojuego* CtrlVideojuego::instancia = NULL;

CtrlVideojuego::~CtrlVideojuego()
{
}

CtrlVideojuego::CtrlVideojuego()
{
}

CtrlVideojuego * CtrlVideojuego::getCtrlVideojuego(){
    if (instancia == NULL){
        instancia = new CtrlVideojuego();
    }
    return instancia;
}



set<string> listarVideoJuegosDesarrollador(){
  set<string> a;
  return a;
}

void CtrlVideojuego::videojuegoAEliminar(string nombre){

}

void CtrlVideojuego::cancelarEliminarVideoJuego(){

}

void CtrlVideojuego::confirmarEliminarVideoJuego(){

}

void CtrlVideojuego::ingresarDatosVideojuego(DtVideojuego datos){

}

DtVideojuego CtrlVideojuego::mostrarVideojuego(){
  DtVideojuego b;
  return b;
}

void CtrlVideojuego::cancelaPublicarVideojuego(){
}

void CtrlVideojuego::confirmaPublicarVideojuego(){
}

void CtrlVideojuego::confirmaPublicarVideojuego(Videojuego * v){
}

set<DtVideojuegoSuscripcion> CtrlVideojuego::ObtenerCatalogo(){
  set<DtVideojuegoSuscripcion> a;
  return a;
}

void CtrlVideojuego::SuscribirseVideojuego(TipoPago pago, TipoPeriodo periodo){
}

void CtrlVideojuego::AgregarSuscripcion(Suscripcion *s){
}

void CtrlVideojuego::AltaSuscripcion(){}

//categorias

set<DtCategoria>CtrlVideojuego::listarCategorias(){
  set<DtCategoria> a;
  return a;
}


void CtrlVideojuego::seleccionarCategoria(string nombre){

}

void CtrlVideojuego::agregarCategoria(string nombre, string descripcion, TipoCat tipo){

}

void CtrlVideojuego::confirma_agregarCategoria(){

}

void CtrlVideojuego::cancela_agregarCategoria(){
  
}