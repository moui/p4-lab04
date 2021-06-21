#ifndef DT_FECHAHORA
#define DT_FECHAHORA

#include <ostream>
#include <iomanip>

using namespace std;

class DtFechaHora
{
    private:
        int dia;
        int mes;
        int ano;
        int hora;
        int minuto;

    public:	
        DtFechaHora(); // Construye MinDtFechaHora. Todos los atributos valen cero.
        DtFechaHora(int dia, int mes, int ano); // Construye fecha. Atributos de tiempo valen cero.
        DtFechaHora(int dia, int mes, int ano, int hora, int minuto); // Contruye fechaHora.
        DtFechaHora(DtFechaHora* fecha); // Por copia
        ~DtFechaHora(); // Destructor

        // Getters
        int getDia();
        int getMes();
        int getAno();
        int getHora();
        int getMinuto();

        // Sobrecarga del operador de insercion <<
        friend std::ostream& operator<<(std::ostream& os, const DtFechaHora& dtFecha);

        static float Meses(DtFechaHora* fechaFin, DtFechaHora* fechaInicio);

        static float Dias(DtFechaHora* fechaFin, DtFechaHora* fechaInicio);
};

#endif
