#include "../lib/Sistema.h"
#include <time.h>
#include <chrono>
#include <iostream>


int cantidadJ = 0;
int cantidadVJ = 0;
int cantidadP=0;

// Constructor
Sistema::Sistema()
{
  cantidadJ = cantidadVJ = 0;
  arregloJugadores = new Jugador*[MAX_JUGADORES];
  for (int i = 0; i < MAX_JUGADORES; i++)
  {
    arregloJugadores[i] = NULL;
  }
  arregloVideojuego = new Videojuego*[MAX_VIDEOJUEGOS];
  for (int i = 0; i < MAX_VIDEOJUEGOS; i++)
  {
    arregloVideojuego[i] = NULL;
  }
  arregloPartidas = new Partida*[MAX_PARTIDAS];
  for (int i = 0; i < MAX_PARTIDAS; i++)
  {
    arregloPartidas[i] = NULL;
  }
}

// Destructor
Sistema::~Sistema()
{
  for (int i = 0; i < cantidadJ; i++) {
    delete arregloJugadores[i];
  }
  for (int i = 0; i < cantidadVJ; i++) {
    delete arregloVideojuego[i];
  }
  for (int i = 0; i < cantidadP; i++) {
    delete arregloPartidas[i];
  }
  delete[] arregloVideojuego;
  delete[] arregloJugadores;
  delete[] arregloPartidas;
}

/*registra un jugador en el sistema. si existe jugador con igual nickname se lanza una excepción */

void Sistema::agregarJugador(string nickname, int edad, string contrasena)
{
    int i=0;
    if (cantidadJ == 0) {
        arregloJugadores[0] = new Jugador(nickname,contrasena,edad, NULL, NULL);
        cantidadJ++;
    }
    else {
        while(i < cantidadJ && nickname!=arregloJugadores[i]->getNickname())
            i++;

        if (cantidadJ==MAX_JUGADORES) throw std::invalid_argument("Ha alcanzado el tope de Jugadores.");

        if( (i == cantidadJ) && (i < MAX_JUGADORES) ) {
            arregloJugadores[cantidadJ]= new Jugador(nickname,contrasena,edad, NULL, NULL);
            cantidadJ++;
        }
        else
            throw std::invalid_argument("Jugador ya registrado.");
    }
}

void Sistema::agregarVideojuego(string nombre, TipoJuego genero)
{
    int i=0;
    if (cantidadVJ == 0) {
            arregloVideojuego[0] = new Videojuego(nombre, genero, NULL);
            cantidadVJ++;
    }
    else {
        while(i < cantidadVJ && nombre!=arregloVideojuego[i]->getNombreVJ())
            i++;
        
        if (cantidadVJ==MAX_VIDEOJUEGOS) throw std::invalid_argument("Ha alcanzado el tope de Videojuegos.");

        if( (i == cantidadVJ) && (i < MAX_VIDEOJUEGOS) ) {
            arregloVideojuego[cantidadVJ]= new Videojuego(nombre, genero, NULL);
            cantidadVJ++;
        }
        else
            throw std::invalid_argument("Videojuego ya registrado.");
    }
}


DtJugador **Sistema::obtenerJugadores(int& cantJugadores)
{
    cantJugadores = cantidadJ;
    DtJugador **res = new DtJugador*[cantidadJ];
    Jugador *jugador = NULL;
    for(int i=0; i< cantidadJ; i++){
        jugador = arregloJugadores[i];
        DtJugador *dtJugador = new DtJugador(jugador->getNickname(),jugador->getEdad());
        res[i] = dtJugador;
    }
    return res;
}

DtVideojuego **Sistema::obtenerVideojuegos(int& cantVideojuegos)
{
  DtVideojuego **arvj = new DtVideojuego*[cantidadVJ];
  cantVideojuegos = cantidadVJ;
  Videojuego *v = NULL;
  for (int i = 0; i < cantVideojuegos; i++)
  {
      v = arregloVideojuego[i];
      std::string s = v->getNombreVJ();
      TipoJuego g = v->getGenero();
      float h = 0;
      int n = 0;
      while (n < cantidadP)
      {
  	  h = h + arregloPartidas[n]->darTotalHorasParticipantes();
  	  n++;
      }
      DtVideojuego *d = new DtVideojuego(s, g, h);
      arvj[i] = d;
  }
  return arvj;
}

DtPartida **Sistema::obtenerPartidas(string videojuego, int& cantPartidas)
{
    //chequeo de registro del videojuego

    int j=0;
    while (j<cantidadVJ){
                if (arregloVideojuego[j]->getNombreVJ()==videojuego)
                    break;
                else
                    j++;
            }
    if (j==cantidadVJ) throw std::invalid_argument ("No existe Juego.");



    DtPartida **res= new DtPartida* [cantidadP];
    Partida * p = NULL;

    for (int i=0; i<cantidadP; i++) {
        p=arregloPartidas[i];

        if (p->getVideojuego()->getNombreVJ()==videojuego) {
            PartidaMultijugador * esmulti={dynamic_cast<PartidaMultijugador*>(p)};
            PartidaIndividual * esind={dynamic_cast<PartidaIndividual*>(p)};

            if (esmulti){
                res[i]= new DtPartidaMultijugador(esmulti->getFecha(), esmulti->getDuracion(), esmulti->getEnVivo(), esmulti->getNicknames(), esmulti->getUnidos());
                cantPartidas++;
            } else {
                res[i]=new DtPartidaIndividual(esind->getFecha(), esind->getDuracion(), esind->getcontinuaPartidaAnterior());
                cantPartidas++;
            }
        }

    }

    if (cantPartidas==0) throw std::invalid_argument("No existen partidas para ese videojuego.");

    return res;

}

void Sistema::iniciarPartida(string nickname, string videojuego, DtPartida* datos)
{
            //chequeo de existencia de jugador y juego
            int i=0;
            while (i<cantidadJ){
                if (arregloJugadores[i]->getNickname()==nickname)
                    break;
                else
                    i++;
            }

            if (i==cantidadJ){
                throw std::invalid_argument ("No existe Jugador.\n");
            }

            int j=0;
            while (j<cantidadVJ){
                if (arregloVideojuego[j]->getNombreVJ()==videojuego)
                    break;
                else
                    j++;
            }
            if (j==cantidadVJ){
                throw std::invalid_argument ("No existe Juego.\n");
            }

             if (cantidadP==MAX_PARTIDAS)throw std::invalid_argument("Ha alcanzado el tope de Partidas.\n");


            // fin del chequeo


            // obtiene la hora
            time_t t = time(0);
            struct tm* now = localtime(&t);

            int dia=now->tm_mday;
            int mes=now->tm_mon +1;
            int anio=now->tm_year+1900;
            int hora=now->tm_hour;
            int minuto=now->tm_min;

            DtFechaHora f= DtFechaHora(dia, mes, anio, hora, minuto);

            //dynamic_cast

            DtPartidaMultijugador * esmulti={dynamic_cast<DtPartidaMultijugador*>(datos)};
            DtPartidaIndividual * esind={dynamic_cast<DtPartidaIndividual*>(datos)};

            if (cantidadP==0&&i<cantidadJ&&j<cantidadVJ){
                if (esmulti){
                    arregloPartidas[0]= new PartidaMultijugador(f, esmulti->getDuracion(), esmulti->getTransmitidaEnVivo(),arregloJugadores[i], arregloVideojuego[j], NULL, esmulti->getNicknameJugadoresUnidos(), esmulti->getCantidadJugadoresUnidos());
                    cantidadP++;
                }

                else {

                arregloPartidas[0]= new PartidaIndividual(f, esind->getDuracion(), esind->getContinuaPartidaAnterior(), arregloJugadores[i], arregloVideojuego[j]);
                cantidadP++;

                }

            }else if(j<cantidadJ&&i<cantidadVJ&&cantidadP<MAX_PARTIDAS){
                if (esmulti){
                    arregloPartidas[cantidadP]= new PartidaMultijugador(f, esmulti->getDuracion(), esmulti->getTransmitidaEnVivo(),arregloJugadores[i], arregloVideojuego[j], NULL, esmulti->getNicknameJugadoresUnidos(), esmulti->getCantidadJugadoresUnidos());
                    cantidadP++;
                } else{
                    arregloPartidas[cantidadP]= new PartidaIndividual(f, esind->getDuracion(), esind->getContinuaPartidaAnterior(), arregloJugadores[i], arregloVideojuego[j]);
                    cantidadP++;

                };
            };

        }
