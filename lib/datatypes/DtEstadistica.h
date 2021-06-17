#ifndef DT_ESTADISTICA
#define DT_ESTADISTICA

#include <string>
#include <iostream>

using namespace std;

class DtEstadistica
{
    private:
    
    string nomEstadistica;
    float valor;
    public:
        DtEstadistica(string n, float valor);
        ~DtEstadistica();

        string getNombre()const;
        float getValor()const;

        friend std::ostream& operator<<(std::ostream& out,const DtEstadistica& dt);
};

#endif