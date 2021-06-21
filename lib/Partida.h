#ifndef PARTIDA
#define PARTIDA

#include "datatypes/DtFechaHora.h"
#include <set>

class Jugador;
class Videojuego;

class Partida
{
  private:
    int identificador;
    float duracion;
    bool finalizada;
    DtFechaHora* fecha;
    DtFechaHora* fecha_fin;
    Videojuego* tiene;

  public:
    Partida(int id, float duracion, bool finalizada, DtFechaHora* fecha, DtFechaHora* fecha_fin, Videojuego* videojuego);

    virtual ~Partida();
    virtual float darTotalHorasParticipantes() = 0; // Partida es una clase abstracta
  
    // Setters
    void setId(int id);
    void setDuracion(float duracion);
    void setFinalizada(bool finalizada);
    void setFecha(DtFechaHora* fecha);
    void setFechaFin(DtFechaHora* fecha_fin);
    void setVideojuego(Videojuego* videojuego);
    void cambiarEstado();


    // Getters
    int getId();
    float getDuracion();
    bool getFinalizada();
    DtFechaHora* getFecha();
    DtFechaHora* getFechaFin();
    Videojuego* getVideojuego();   
};

#endif
