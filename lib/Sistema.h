#ifndef SISTEMA
#define SISTEMA

#include "datatypes/DtFechaHora.h"
#include "interfaces/IUsuario.h"
#include "Fabrica.h"

// Clase sistema. Singleton.
class Sistema
{
    private:
        static Sistema* instancia;
        // Constructor
	    Sistema();
        
        // Members
        DtFechaHora fecha;
    public:
        // Destructor
        ~Sistema();

        // GetInstance
	    static Sistema* getInstancia();

        // Getters
        DtFechaHora getFecha();

        // Setters
        void setFecha(DtFechaHora fechaSistema);
};





#endif