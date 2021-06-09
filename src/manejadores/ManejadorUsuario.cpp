#include "../../lib/manejadores/ManejadorUsuario.h"

// Singleton
ManejadorUsuario* ManejadorUsuario::instancia = NULL;

// GetInstance
ManejadorUsuario* ManejadorUsuario::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new ManejadorUsuario();
    }
    return instancia;
}
// Constructor
ManejadorUsuario::ManejadorUsuario(){}
// Destructor
ManejadorUsuario::~ManejadorUsuario(){}

Usuario* ManejadorUsuario::buscarUsuario(string clave){
    return NULL;
}

void ManejadorUsuario::agregarUsuario(Usuario* usuario){}

void ManejadorUsuario::borrarUsuario(string clave){}