#ifndef SISTEMA
#define SISTEMA

#include "datatypes/DtFechaHora.h"
#include "interfaces/IUsuario.h"
#include "Fabrica.h"

#include <chrono>
#include <ctime>

using std::chrono::system_clock;
using std::time_t;

// Clase sistema. Singleton.
class Sistema
{
    private:
        static Sistema* instancia; // Singleton
	    Sistema(); // Constructor
        
        // Members
        DtFechaHora* fecha;
    public:
        ~Sistema(); // Destructor
	    static Sistema* getInstancia(); // GetInstance

        // Getters y Setters
        DtFechaHora* getFecha();
        void setFecha(DtFechaHora* fechaSistema);

        // Operaciones
        // Retorna instancia de DtFechaHora representando la fecha actual.
        DtFechaHora* ahora(); 
};





#endif