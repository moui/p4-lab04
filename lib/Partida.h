#ifndef PARTIDA
#define PARTIDA

#include "datatypes/DtFechaHora.h"

class Jugador;
class Videojuego;

class Partida
{
  private:
    DtFechaHora fecha;
    float duracion;
    Jugador* iniciada;
    Videojuego* tiene;

  public:
    Partida(DtFechaHora, float, Jugador*, Videojuego*);
    virtual float darTotalHorasParticipantes() = 0; // class Partida sera una clase abstracta
    virtual ~Partida();

    // Setters
    void setFecha(DtFechaHora);
    void setDuracion(float);
    void setJugador(Jugador*);
    void setVideojuego(Videojuego*);

    // Getters
    DtFechaHora getFecha();
    float getDuracion();
    Jugador* getJugador();
    Videojuego* getVideojuego();
};

#endif
