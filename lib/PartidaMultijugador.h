#ifndef PARTIDAMULTIJUGADOR
#define PARTIDAMULTIJUGADOR

#include "Partida.h"
#include "InfoPartidaMulti.h"

#include <string>
#include <map>

using namespace std;

class InfoPartidaMulti;

class PartidaMultijugador : public Partida
{
    private:
        bool transmitidaEnVivo;
        map<string, InfoPartidaMulti*> participan;

    public:
        // Constructores y destructores
        PartidaMultijugador(int id, float duracion, bool finalizada, DtFechaHora* fecha, Videojuego* videojuego,
            bool enVivo, map<string, InfoPartidaMulti*> mapInfoPM);


        ~PartidaMultijugador();
        
        // Getters
        bool getTransmitidaEnVivo();
        map<string, InfoPartidaMulti*> getParticipan();

        // Setters
        void setTransmitidaEnVivo(bool enVivo);
        void setParticipan(map<string, InfoPartidaMulti*> mapInfoPM);


        // Operaciones
        float darTotalHorasParticipantes();
	    void setHoraAbandono(DtFechaHora f, string clave);
	    void forzarAbandono(DtFechaHora f);        
};
#endif
