#ifndef PARTIDA
#define PARTIDA

#include "datatypes/DtFechaHora.h"

class Jugador;
class Videojuego;

class Partida
{
  private:
    float identificador;
    DtFechaHora fecha;
    float duracion;
    Jugador* iniciada_por;
    Videojuego* tiene;
    bool finalizada;

  public:
    Partida(DtFechaHora, float, Jugador*, Videojuego*);
    virtual float darTotalHorasParticipantes() = 0; // class Partida sera una clase abstracta
    virtual ~Partida();
    bool estaFinalizada();
  
    // Setters
    void setFecha(DtFechaHora);
    void setDuracion(float);
    void setJugador(Jugador*);
    void setVideojuego(Videojuego*);
    void cambiarEstado();

    // Getters
    DtFechaHora getFecha();
    float getDuracion();
    Jugador* getJugador();
    Videojuego* getVideojuego();
    float getIdentificador();
    
};

#endif
