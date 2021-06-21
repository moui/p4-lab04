#include "../../lib/manejadores/ManejadorVideojuego.h"

// Constructor
ManejadorVideojuego::ManejadorVideojuego(){}

// Destructor
ManejadorVideojuego::~ManejadorVideojuego(){
    for (itvj = videojuegos.begin(); itvj != videojuegos.end(); itvj++)
    {
        if (itvj->second != NULL)
            delete itvj->second;
    }
    videojuegos.clear();

    for (itc = categorias.begin(); itc != categorias.end(); itc++)
    {
        if (itc->second != NULL)
            delete itc->second;
    }
    categorias.clear();
}
//getters
Videojuego* ManejadorVideojuego::buscarVideojuego(string clave){
    if (videojuegos.find(clave) == videojuegos.end())
        return NULL;
    else 
        return videojuegos.find(clave)->second;
}

Categoria* ManejadorVideojuego::buscarCategoria(string clave){
    if (categorias.find(clave) == categorias.end())
        return NULL;
    else 
        return categorias.find(clave)->second;
}

//setters
void ManejadorVideojuego::agregarVideojuego(string clave, Videojuego* vid){
    videojuegos.insert( pair <string, Videojuego*>(clave, vid));
}

void ManejadorVideojuego::agregarCategoria(string clave, Categoria* cat){
    categorias.insert( pair <string, Categoria*>(clave, cat));
}

//deleters 

void ManejadorVideojuego::borrarVideojuego(string clave){
    if (!videojuegos.empty()){
        itvj = videojuegos.find(clave);
        Videojuego* vj = itvj->second;
        videojuegos.erase(itvj);
        delete vj;
    }
}

void ManejadorVideojuego::borrarCategoria(string clave){
    categorias.erase(itc=categorias.find(clave));
}

//suscribirse a videojuego

map<string, DtVideojuegoSuscripcion*> ManejadorVideojuego::ObtenerCatalogo(){
    map<string, DtVideojuegoSuscripcion*> res;
    if(!videojuegos.empty()){
        for (itvj=videojuegos.begin(); itvj!=videojuegos.end(); itvj++){
            string n=itvj->second->getNombreVJ();
            float c1=itvj->second->getCosto1();
            float c3=itvj->second->getCosto3();
            float c12=itvj->second->getCosto12();
            float cV=itvj->second->getCostoV();
            DtVideojuegoSuscripcion* vs=new DtVideojuegoSuscripcion(n,c1,c3,c12,cV);
            res.insert( pair<string, DtVideojuegoSuscripcion*>(n,vs));
        }
    } else 
    {
        throw invalid_argument( "Catalogo de Videojuegos vacio. ");
    }
    return res;
}

void ManejadorVideojuego::agregarSuscrito(string nomVJ, string nomJ)
{
    itvj=videojuegos.find(nomVJ);
    (itvj->second)->agregarSuscrito(nomJ);

}


//IniciarPartida

set<DtCategoria*> ManejadorVideojuego::listarCategorias(){
    set<DtCategoria*> ret;
    if(!categorias.empty()){
        for(auto itc = categorias.begin(); itc != categorias.end(); ++itc){
		    ret.insert(itc->second->getDtCategoria());
	    }
    }
    else {
        throw invalid_argument( "Catalogo de Categorias vacio. ");
    }
    return ret;
}

set<DtCategoria*> ManejadorVideojuego::listarCategoriasGenero(){
    set<DtCategoria*> ret;
    if(!categorias.empty()){
        for(auto itc = categorias.begin(); itc != categorias.end(); ++itc){
            if (itc->second->getTipoCat() == TipoCat::Genero){
                ret.insert(itc->second->getDtCategoria());
            }
		    
	    }
    }
    else {
        throw invalid_argument( "Catalogo de Categorias vacio. ");
    }
    return ret;
}
      
set<DtCategoria*> ManejadorVideojuego::listarCategoriasPlataforma(){
    set<DtCategoria*> ret;
    if(!categorias.empty()){
        for(auto itc = categorias.begin(); itc != categorias.end(); ++itc){
            if (itc->second->getTipoCat() == TipoCat::Plataforma){
                ret.insert(itc->second->getDtCategoria());
            }
		    
	    }
    }
    else {
        throw invalid_argument( "Catalogo de Categorias vacio. ");
    }
    return ret;
}

set<DtCategoria*> ManejadorVideojuego::listarCategoriasOtros(){
    set<DtCategoria*> ret;
    if(!categorias.empty()){
        for(auto itc = categorias.begin(); itc != categorias.end(); ++itc){
            if (itc->second->getTipoCat() == TipoCat::Otro){
                ret.insert(itc->second->getDtCategoria());
            }
		    
	    }
    }
    else {
        throw invalid_argument( "Catalogo de Categorias vacio. ");
    }
    return ret;
}

map<string, string> ManejadorVideojuego::listarNombresVideojuego(){
    map<string, string> ret;
    if(!videojuegos.empty()){
        for(auto itvj = videojuegos.begin(); itvj != videojuegos.end(); ++itvj){
		    ret.insert(pair<string, string>(itvj->second->getNombreVJ(), itvj->second->getDescripcionVJ()));
	    }
    }
    else {
        throw invalid_argument( "Catalogo de Videojuegos vacio. ");
    }
    return ret;
}

void ManejadorVideojuego::asignarPuntajeVideojuegoJ(string nombrevj, string nickname, TipoPuntaje puntaje){
    if (!videojuegos.empty()){
        itvj = videojuegos.find(nombrevj);
        itvj->second->setPuntajeVJ(nickname, puntaje);
        itvj->second->calcularPromedio();
    }
    else {
        throw invalid_argument( "Catalogo de Videojuegos vacio. ");
    }
}