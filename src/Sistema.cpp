#include "../lib/Sistema.h"

// Singleton
Sistema* Sistema::instancia = NULL;

// Constructor
Sistema::Sistema()
{
    fecha = ahora();
}

// Destructor
Sistema::~Sistema()
{
    delete fecha;
}

// GetInstance
Sistema* Sistema::getInstancia()
{
    if (instancia == NULL)
        instancia = new Sistema();

    return instancia;
}

// Getters
DtFechaHora* Sistema::getFecha()
{
    return fecha;
}

// Setters
void Sistema::setFecha(DtFechaHora* fechaSistema)
{
    fecha = fechaSistema;
}

// Metodos

DtFechaHora* Sistema::ahora()
{
    time_t now_t = system_clock::to_time_t(system_clock::now());
    struct tm* now_tm = localtime(&now_t);
    return new DtFechaHora(now_tm->tm_mday, now_tm->tm_mon, now_tm->tm_year + 1900, now_tm->tm_hour, now_tm->tm_min);
}