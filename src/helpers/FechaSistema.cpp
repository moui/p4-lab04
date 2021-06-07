#include "../../lib/helpers/FechaSistema.h"

FechaSistema::FechaSistema()
{
    this->fechaInicial = time_t__to__DtFechaHora(time(NULL));
    this->fechaActual = time_t__to__DtFechaHora(time(NULL));
    this->inicio = time(NULL);
}

FechaSistema::~FechaSistema()
{
    delete fechaInicial;
    delete fechaActual;
}

DtFechaHora* FechaSistema::getFechaActual()
{
    return fechaActual;
}

void FechaSistema::setFechaInicial(DtFechaHora* nuevaFecha)
{
    delete this->fechaInicial;
    this->fechaInicial = nuevaFecha;
    this->inicio = time(NULL);
}

void FechaSistema::actualizarFechaActual()
{
    delete fechaActual;
    time_t fin = time(NULL);
    time_t fecha__time_t = DtFechaHora__to__time_t(fechaInicial);
    tm* fecha_tm = localtime(&fecha__time_t);
    fecha_tm->tm_sec += static_cast<int>(difftime(fin, inicio));
    fechaActual = time_t__to__DtFechaHora(mktime(fecha_tm)); 
}

time_t FechaSistema::DtFechaHora__to__time_t(DtFechaHora* fecha)
{
    tm* fecha_tm = new tm();
    fecha_tm->tm_isdst = -1; // DST
    fecha_tm->tm_year = fecha->getAno() - 1900;
    fecha_tm->tm_mon = fecha->getMes() - 1; 
    fecha_tm->tm_mday = fecha->getDia();
    fecha_tm->tm_hour = fecha->getHora();
    fecha_tm->tm_min = fecha->getMinuto();
    time_t fecha__time_t = mktime(fecha_tm);
    delete fecha_tm;
    return fecha__time_t;
}

DtFechaHora* FechaSistema::time_t__to__DtFechaHora(time_t fecha)
{
    tm* fecha_tm = localtime(&fecha);
    return new DtFechaHora(fecha_tm->tm_mday, fecha_tm->tm_mon + 1, fecha_tm->tm_year + 1900,
        fecha_tm->tm_hour, fecha_tm->tm_min);
}