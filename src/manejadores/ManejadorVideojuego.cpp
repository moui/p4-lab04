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
Videojuego ManejadorVideojuego::buscarVideojuego(string clave){
    return (catalogoVJ.find(clave)->second);
}

DescripcionSuscripcion ManejadorVideojuego::buscarDescripcionSuscripcion(string clave){
    return (descSuscripcion.find(clave)->second);
}

Categoria ManejadorVideojuego::buscarCategoria(string clave){
    return (categorias.find(clave)->second);
}
//setters
void ManejadorVideojuego::agregarVideojuego(string clave, Videojuego v){
    catalogoVJ.insert( pair <string, Videojuego>(clave, v));
}

void ManejadorVideojuego::agregarDescripcionSuscripcion(string clave, DescripcionSuscripcion ds){
    descSuscripcion.insert( pair <string, DescripcionSuscripcion>(clave, ds));
}

void ManejadorVideojuego::agregarCategoria(string clave, Categoria cat){
    categorias.insert( pair <string, Categoria>(clave, cat));
}

//deleters (?

void ManejadorVideojuego::borrarVideojuego(string clave){
    catalogoVJ.erase(itvj=catalogoVJ.find(clave));
}


void ManejadorVideojuego::borrarDescripcionSuscripcion(string clave){
    descSuscripcion.erase(itds=descSuscripcion.find(clave));
}

void ManejadorVideojuego::borrarCategoria(string clave){
    categorias.erase(itc=categorias.find(clave));
}