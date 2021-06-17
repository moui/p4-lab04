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

void CtrlVideojuego::ingresarDatosVideojuego(string nnombre, string ndescripcion, float nc1, float nc3, float nc12, float ncv){
  this->nombre = nnombre;
  this->descripcion = ndescripcion;
  this->costo1 = nc1;
  this->costo3 = nc3;
  this->costo12 = nc12;
  this->costoV = ncv;
}

DtVideojuego CtrlVideojuego::mostrarVideojuego(){
  DtVideojuego b;
  return b;
}

void CtrlVideojuego::cancela_publicarVideojuego(){

}

void CtrlVideojuego::confirma_publicarVideojuego(){
  Videojuego* vid = new Videojuego(nombre, descripcion, costo1, costo3, costo12, costoV, setcat);
  manejadorVideojuego->agregarVideojuego(nombre, vid);
  IUsuario *IUsr = Fabrica::getInstancia()->getIUsuario();
  
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
