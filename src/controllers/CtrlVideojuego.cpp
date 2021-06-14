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


//imprementacion caso de uso suscribirse a VJ

map<string, DtVideojuegoSuscripcion*> CtrlVideojuego::ObtenerCatalogo(){
  map<string, DtVideojuegoSuscripcion*> res;
  res=manejadorVideojuego->ObtenerCatalogo();
  return res;
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