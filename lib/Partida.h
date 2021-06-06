#ifndef PARTIDA
#define PARTIDA

#include "datatypes/DtFechaHora.h"

class Jugador;
class Videojuego;

class Partida
{
  private:
    float identificador;
    float duracion;
    bool finalizada;
    DtFechaHora fecha;
    Videojuego* tiene;

  public:
    Partida(float id, float duracion, bool finalizada, DtFechaHora fecha, Videojuego* videojuego);
    virtual ~Partida();
    virtual float darTotalHorasParticipantes() = 0; // Partida es una clase abstracta
  
    // Setters
    void setId(float id);
    void setDuracion(float duracion);
    void setFinalizada(bool finalizada);
    void setFecha(DtFechaHora fecha);
    void setVideojuego(Videojuego* videojuego);

    // Getters
    float getId();
    float getDuracion();
    bool getFinalizada();
    DtFechaHora getFecha();
    Videojuego* getVideojuego();
};

#endif
