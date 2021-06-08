#include "../lib/CtrlVideojuego.h"

using namespace std;

CtrlVideojuego * getCtrlVideojuego::instancia = NULL;

CtrlVideojuego::~CtrlVideojuego(){

}

CtrlUsuario * CtrlVideojuego::getCtrlVideojuego(){
    if (instancia == NULL){
        instancia = new CtrlVideojuego();
    }
    return instancia;
}



set<string>listarVideoJuegosDesarrollador(){
  return "\n"
}

void CtrlVideojuego::videojuegoAEliminar(nombre: string){

}

void CtrlVideojuego::cancelarEliminarVideoJuego(){

}

void CtrlVideojuego::confirmarEliminarVideoJuego(){

}

void CtrlVideojuego::ingresarDatosVideojuego(datos: DtVideojuego){

}

set<Dtcategoria>CtrlVideojuego::listarCategorias(){
  return NULL;
}


void CtrlVideojuego::seleccionarCategoria(nombre: String){

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

set<DtVideojuegosuscripcion> CtrlVideojuego::ObtenerCatalogo(){
  return NULL;
}

void CtrlVideojuego::SuscribirseVideojuego(TipoPago pago, TipoPeriodo periodo){
}

void CtrlVideojuego::AgregarSuscripcion(suscripcion *s){
}

void CtrlVideojuego::AltaSuscripcion(){   //faltan parametros
}
