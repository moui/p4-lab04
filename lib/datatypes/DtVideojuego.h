#ifndef DT_VIDEOJUEGO
#define DT_VIDEOJUEGO

#include <string>
#include <ostream>
#include <set>

using std::string;
using std::ostream;
using std::endl;

class DtVideojuego
{
    private:
        string nombre, descripcion;
        float costo1, costo3, costo12, costoV; 
        float* totalHorasDeJuego;

    public:
        // CTOR y DTOR
        DtVideojuego(string nombre, string descripcion, float costo1, float costo3, float costo12, 
            float costoV, float* totalHorasDeJuego);

        ~DtVideojuego();

        // Getters
        string getNombre();
        string getDescripcion();
        float getCosto1();
        float getCosto3();
        float getCosto12();
        float getCostoV();
        float* getTotalHorasDeJuego();

        // Sobrecarga
        friend ostream& operator<<(ostream& out, const DtVideojuego& dt);
};

#endif
