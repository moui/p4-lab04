#include "../../lib/manejadores/ManejadorVideojuego.h"

// Constructor
ManejadorVideojuego::ManejadorVideojuego(){}

// Destructor
ManejadorVideojuego::~ManejadorVideojuego(){
    videojuegos.clear();
    //descSuscripcion.clear();
}
//getters
Videojuego* ManejadorVideojuego::buscarVideojuego(string clave){
    return (videojuegos.find(clave)->second);
}

/*DescripcionSuscripcion* ManejadorVideojuego::buscarDescripcionSuscripcion(string clave){
    return (descSuscripcion.find(clave)->second);
}
*/
Categoria* ManejadorVideojuego::buscarCategoria(string clave){
    itc = categorias.find(clave);
    return itc->second;
}

//setters
void ManejadorVideojuego::agregarVideojuego(string clave, Videojuego* vid){
    videojuegos.insert( pair <string, Videojuego*>(clave, vid));
}

/*void ManejadorVideojuego::agregarDescripcionSuscripcion(string clave, DescripcionSuscripcion* ds){
    descSuscripcion.insert( pair <string, DescripcionSuscripcion*>(clave, ds));
}*/

void ManejadorVideojuego::agregarCategoria(string clave, Categoria* cat){
    categorias.insert( pair <string, Categoria*>(clave, cat));
}

//deleters (?

void ManejadorVideojuego::borrarVideojuego(string clave){
    videojuegos.erase(itvj=videojuegos.find(clave));
}


/*void ManejadorVideojuego::borrarDescripcionSuscripcion(string clave){
    descSuscripcion.erase(itds=descSuscripcion.find(clave));
}*/

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

//IniciarPartida
void ManejadorVideojuego::setPartida(Partida* p){
	p->getVideojuego()->setPartida(p);
}

set<DtCategoria*> ManejadorVideojuego::listarCategorias(){
    set<DtCategoria*> ret;
    if(!categorias.empty()){
        for(auto itc = categorias.begin(); itc != categorias.end(); ++itc){
		    ret.insert(itc->second->getDtCategoria());
	    }
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
    return ret;
}