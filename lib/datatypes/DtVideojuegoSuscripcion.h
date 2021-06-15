#ifndef DT_VIDEOJUEGO_SUSCRIPCION
#define DT_VIDEOJUEGO_SUSCRIPCION

#include <string>
#include <iostream>

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
        DtVideojuegoSuscripcion(string n, float c1, float c3, float c12, float cV);
        ~DtVideojuegoSuscripcion();

        string getNombreVideojuego()const; 
        float getCosto1()const;
        float getCosto3()const;
        float getCosto12()const;
        float getCostoV()const; 



      friend  std::ostream& operator<<(std::ostream& os, const DtVideojuegoSuscripcion& dt);    
};

#endif