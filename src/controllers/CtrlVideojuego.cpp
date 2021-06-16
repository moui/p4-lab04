#include "../../lib/controllers/CtrlVideojuego.h"

using namespace std;

CtrlVideojuego* CtrlVideojuego::instancia = NULL;

CtrlVideojuego::~CtrlVideojuego()
{
}

CtrlVideojuego::CtrlVideojuego()
{
  manejadorVideojuego = new ManejadorVideojuego();
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

DtDescripcionSuscripcion* CtrlVideojuego::getDatosDescripcionSuscripcion(TipoPeriodo p, string nomVJ)
{
  DtDescripcionSuscripcion* res=NULL;
  Videojuego* v=manejadorVideojuego->buscarVideojuego(nomVJ);
  res=v->getDatosDescripcionSuscripcion(p);
  if(res==NULL)
  {
    throw invalid_argument("No se encontraron datos en el videojuego. ");
  }
  return res;
  
}



//categorias

set<DtCategoria*>CtrlVideojuego::listarCategorias(){
  return manejadorVideojuego->listarCategorias();
}


void CtrlVideojuego::seleccionarCategoria(string nombre){

}

void CtrlVideojuego::agregarCategoria(string nnombre, string ndescripcion, TipoCat ntipo){
  this->nombre = nnombre;
  this->descripcion = ndescripcion;
  this->tipo = ntipo;
}

void CtrlVideojuego::confirma_agregarCategoria(){
  manejadorVideojuego->agregarCategoria(nombre, new Categoria(nombre, descripcion, tipo));
}

void CtrlVideojuego::cancela_agregarCategoria(){
  
}

//IniciarPartida
void CtrlVideojuego::iniciadaP(Partida* p){
	manejadorVideojuego->setPartida(p);
}

Videojuego* CtrlVideojuego::getVJ(string nomVJ){
	return manejadorVideojuego->buscarVideojuego(nomVJ);
}
