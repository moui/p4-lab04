#include "../../lib/controllers/CtrlUsuario.h"

// Singleton
CtrlUsuario* CtrlUsuario::instancia = NULL;
// GetInstance
CtrlUsuario* CtrlUsuario::getInstancia()
{
    if (instancia == NULL)
    {
        instancia = new CtrlUsuario();
    }
    return instancia;
}
// Constructor
CtrlUsuario::CtrlUsuario()
{
    sesionActiva = NULL;
}
// Destructor
CtrlUsuario::~CtrlUsuario()
{
}
// Getters
Usuario* CtrlUsuario::getSesionActiva()
{
    return sesionActiva;
}
// Setters
void CtrlUsuario::setSesionActiva(Usuario* usuario)
{
    sesionActiva = usuario;
}
// Implementacion de IUsuario
void CtrlUsuario::altaUsuario()
{

}

void CtrlUsuario::iniciarSesion()
{

}