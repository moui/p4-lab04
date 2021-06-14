#ifndef DT_VIDEOJUEGO_SUSCRIPCION
#define DT_VIDEOJUEGO_SUSCRIPCION

#include <string>

using namespace std;

class DtVideojuegoSuscripcion
{
    private:
    string nomVJ;
    float costo1;
    float costo3;
    float costo12;
    float costoV;

    public:
        DtVideojuegoSuscripcion(float c1, float c3, float c12, float cV);
        ~DtVideojuegoSuscripcion();

        string getNombreVideojuego(); 
        float getCosto1();
        float getCosto3();
        float getCosto12();
        float getCostoV(); 
};

#endif