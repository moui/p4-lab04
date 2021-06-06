#include "../lib/Sistema.h"

// Singleton
Sistema* Sistema::instancia = NULL;

// Constructor
Sistema::Sistema()
{
    
}

// Destructor
Sistema::~Sistema()
{

}

// GetInstance
Sistema* Sistema::getInstancia()
{
    if (instancia == NULL)
        instancia = new Sistema();

    return instancia;
}

// Getters
DtFechaHora Sistema::getFecha()
{
    return fecha;
}

// Setters
void Sistema::setFecha(DtFechaHora fechaSistema)
{
    fecha = fechaSistema;
}