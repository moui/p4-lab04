#ifndef SISTEMA
#define SISTEMA

#include "helpers/FechaSistema.h"
#include "datatypes/DtFechaHora.h"
#include "interfaces/IUsuario.h"
#include "Fabrica.h"

// Clase sistema. Singleton.
class Sistema
{
    private:
        static Sistema* instancia; // Singleton
	    Sistema(); // Constructor
        
        // Members
        FechaSistema* fechaSistema;
        
    public:
        ~Sistema(); // Destructor
	    static Sistema* getInstancia(); // GetInstance

        // Getters y Setters
        DtFechaHora* getFecha();
        void setFecha(DtFechaHora* fechaSistema);
};





#endif