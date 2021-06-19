#ifndef DT_VIDEOJUEGO
#define DT_VIDEOJUEGO

#include <string>
#include <set>

using namespace std;

class DtVideojuego
{
  private:
    string nombre, descripcion;
    float costo1, costo3, costo12, costoV, thj;
    float totalHorasDeJuego;

  public:
    ~DtVideojuego();
    DtVideojuego(string, string, float, float, float, float);

    //getters
    string getNombre();
    string getDescripcion();
    float getCosto1();
    float getCosto3();
    float getCosto12();
    float getCostoV();
    float getthj();

    //setters
    void setNombre(string);
    void setDescripcion(string);
    void setCosto1(float c1);
    void setCosto3(float c3);
    void setCosto12(float c12);
    void setCostoV(float cV);
    void setthj(float thj);
};

#endif
