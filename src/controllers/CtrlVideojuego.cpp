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

// eliminar videojuego

void CtrlVideojuego::videojuegoAEliminar(string nombre){
  this->vjelim = nombre;
}

void CtrlVideojuego::cancelar_eliminarVideoJuego(){

}

void CtrlVideojuego::confirmar_eliminarVideoJuego(){
  CtrlUsuario* ctrlUsuario;
  ctrlUsuario = CtrlUsuario::getInstancia();
  Desarrollador* d = dynamic_cast<Desarrollador*> (ctrlUsuario->getSesionActiva());
  d->quitarVJ(manejadorVideojuego->buscarVideojuego(vjelim));
  manejadorVideojuego->borrarVideojuego(vjelim);
  //borrar suscripciones
}

 // publicar videojuego
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
  if (res.empty()){throw invalid_argument("es aca el error");}
  return res;
}

int CtrlVideojuego::getCostoSuscripcion(TipoPeriodo p, string nomVJ)
{
	Videojuego* videojuego = manejadorVideojuego->buscarVideojuego(nomVJ);
    if (videojuego == NULL)
		throw invalid_argument("No existe videojuego " + nomVJ);
	
	switch (p)
	{
		case TipoPeriodo::Mensual:
			return videojuego->getCosto1();
		case TipoPeriodo::Trimestral:
			return videojuego->getCosto3();
		case TipoPeriodo::Anual:
			return videojuego->getCosto12();
		case TipoPeriodo::Vitalicia:
			return videojuego->getCostoV();
		default:
			throw invalid_argument("");
	}
}

void CtrlVideojuego::agregarSuscrito(string nomVJ, string nomJ)
{
  manejadorVideojuego->agregarSuscrito(nomVJ, nomJ);
}

DtVideojuegoSuscripcion* CtrlVideojuego::getDataSuscripciones(string nombreVideojuego)
{
    Videojuego* vj = manejadorVideojuego->buscarVideojuego(nombreVideojuego);
    if (vj == NULL)
		throw invalid_argument("No existe videojuego " + nombreVideojuego);
    

    return new DtVideojuegoSuscripcion(nombreVideojuego, vj->getCosto1(), vj->getCosto3(), vj->getCosto12(), vj->getCostoV());
}

set<DtVideojuegoSuscripcion*> CtrlVideojuego::getComplemento(map<string, DtVideojuegoSuscripcion*> map)
{
    set<DtVideojuegoSuscripcion*> res;

    auto catalogo = ObtenerCatalogo();
    for (auto it = catalogo.begin(); it != catalogo.end(); ++it)
    {
        DtVideojuegoSuscripcion* infoSusc = it->second;
        string nombre = infoSusc->getNombreVideojuego();
        if ( map.empty() || ( map.find(nombre) == map.end() ) )
        {
            auto _infoSusc = new DtVideojuegoSuscripcion(nombre, infoSusc->getCosto1(), 
                infoSusc->getCosto3(), infoSusc->getCosto12(), infoSusc->getCostoV());
            res.insert(_infoSusc);
        }
        delete infoSusc;
    }
    
    return res;
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
  if (videojuego == NULL)
    throw invalid_argument("Videojuego no existe en el catalogo.");
  else   
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

set<string> CtrlVideojuego::listarNombresVideojuego(){
  return manejadorVideojuego->listarNombresVideojuego();
}