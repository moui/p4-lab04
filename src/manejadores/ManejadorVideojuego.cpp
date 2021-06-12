#include "../../lib/manejadores/ManejadorVideojuego.h"

// Singleton
ManejadorVideojuego* ManejadorVideojuego::instancia = NULL;

// GetInstance
ManejadorVideojuego* ManejadorVideojuego::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new ManejadorVideojuego();
    }
    return instancia;
}
// Constructor
ManejadorVideojuego::ManejadorVideojuego(){}
// Destructor
ManejadorVideojuego::~ManejadorVideojuego(){
    catalogoVJ.clear();
    descSuscripcion.clear();
    delete instancia;
}
//getters
Videojuego* ManejadorVideojuego::buscarVideojuego(string clave){
    return (itvj=find(clave));
}

DescripcionSuscripcion* ManejadorVideojuego::buscarDescripcionSuscripcion(string clave){
    return (itds=find(clave));
}

Categoria* ManejadorVideojuego::buscarCategoria(string clave){
    return (itc=find(clave));
}
//setters
void ManejadorVideojuego::agregarVideojuego(string clave, Videojuego v){
    catalogoVJ.insert( pair <string, Videojuego>(clave, v));
}

void ManejadorVideojuego::agregarDescripcionSuscripcion(string clave, DescripcionSuscripcion ds){
    descSuscripcion.insert( pair <string, DescripcionSuscripcion>(clave, ds));
}

void ManejadorVideojuego::agregarCategoria(string clave, Categoria cat){
    descSuscripcion.insert( pair <string, Categoria>(clave, cat));
}

//deleters (?

void ManejadorVideojuego::borrarVideojuego(string clave){
    catalogoVJ.erase(itvj=find(clave));
}


void ManejadorVideojuego::borrarDescripcionSuscripcion(string clave){
    descSuscripcion.erase(itds=find(clave));
}

void ManejadorVideojuego::borrarCategoria(string clave){
    categorias.erase(itc=find(clave));
}