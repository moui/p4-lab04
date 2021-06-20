#ifndef SUSCRIPCION
#define SUSCRIPCION

#include "datatypes/TipoEstado.h"
#include "datatypes/TipoPago.h"
#include "datatypes/DtFechaHora.h"
#include "datatypes/TipoPeriodo.h"
#include "helpers/FechaSistema.h"
#include <string>
#include <map>


using namespace std;

class Suscripcion{
    
    private:
        string nombreVJ;
        DtFechaHora* fecha;
        float costo;
        TipoPago pago;
        TipoPeriodo periodo;
        bool cancelada;

    public:
        Suscripcion(string nomVJ, DtFechaHora* f, float costo, TipoPago pago, TipoPeriodo periodo, bool cancelada);
        ~Suscripcion();

        //Getters
        string getnombreVJ();
        DtFechaHora* getFecha();
        float getCosto();
        bool getCanceleda();
        TipoPago getTipoPago();
        TipoPeriodo getPeriodo();
        TipoEstado getEstado(); // Se calcula a partir de los demas atributos

        //Setters
        void setNombreVJ(string n);
        void setFecha(DtFechaHora* f);
        void setCosto(float c);
        void setTipoPago(TipoPago p);
        void setPeriodo(TipoPeriodo periodo);
        void setCancelada(bool cancelada);
};

#endif
