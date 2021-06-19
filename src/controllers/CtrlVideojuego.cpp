#include "../../lib/controllers/CtrlVideojuego.h"

using namespace std;

CtrlVideojuego* CtrlVideojuego::instancia = NULL;

CtrlVideojuego::~CtrlVideojuego()
{
  delete manejadorVideojuego;
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

void CtrlVideojuego::ingresarDatosVideojuego(string nnombre, string ndescripcion, float nc1, float nc3, float nc12, float ncv){
  this->nombre = nnombre;
  this->descripcion = ndescripcion;
  this->costo1 = nc1;
  this->costo3 = nc3;
  this->costo12 = nc12;
  this->costoV = ncv;
}

DtVideojuego* CtrlVideojuego::mostrarVideojuego(){
  set<DtCategoria*> tempcats;
  for (auto itcat = cats.begin(); itcat != cats.end(); ++itcat) {
    tempcats.insert((*itcat)->getDtCategoria());
  }
  return new DtVideojuego(nombre, descripcion, costo1, costo3, costo12, costoV, tempcats);
}

void CtrlVideojuego::cancela_publicarVideojuego(){
  //limpiar el set de categorias
  cats.clear();
}

void CtrlVideojuego::seleccionarCategoria(string nombre, TipoCat tcat){
  Categoria* tempcat = manejadorVideojuego->buscarCategoria(nombre);
  if (tempcat->getTipoCat() == tcat)
    cats.insert(manejadorVideojuego->buscarCategoria(nombre));
  else
    throw invalid_argument( "El nombre no corresponde a una categoria del tipo indicado." );
}

void CtrlVideojuego::confirma_publicarVideojuego(){
  Videojuego* nvj = new Videojuego(nombre, descripcion, costo1, costo3, costo12, costoV, cats);
  manejadorVideojuego->agregarVideojuego(nombre, nvj);
  CtrlUsuario* ctrlUsuario;
  ctrlUsuario = CtrlUsuario::getInstancia();
  Desarrollador* d = dynamic_cast<Desarrollador*> (ctrlUsuario->getSesionActiva());
  d->publicarVJ(nvj);
  cats.clear();
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

void CtrlVideojuego::agregarSuscrito(string nomVJ, string nomJ)
{
  manejadorVideojuego->agregarSuscrito(nomVJ, nomJ);
}



//categorias

set<DtCategoria*>CtrlVideojuego::listarCategorias(){
  return manejadorVideojuego->listarCategorias();
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
	
}

Videojuego* CtrlVideojuego::getVJ(string nomVJ){
	return manejadorVideojuego->buscarVideojuego(nomVJ);
}

DtVideojuego* CtrlVideojuego::verInfoVideojuego(string nombre)
{
  Videojuego* videojuego = getVJ(nombre);
  return videojuego->getDatatype();
}

set<DtCategoria*> CtrlVideojuego::listarCategoriasGenero(){
  return manejadorVideojuego->listarCategoriasGenero();
}
set<DtCategoria*> CtrlVideojuego::listarCategoriasPlataforma(){
  return manejadorVideojuego->listarCategoriasPlataforma();
}
set<DtCategoria*> CtrlVideojuego::listarCategoriasOtros(){
  return manejadorVideojuego->listarCategoriasOtros();
}