#include "../lib/PartidaMultijugador.h"

PartidaMultijugador::PartidaMultijugador(
  DtFechaHora fecha, float duracion, bool transmitidaEnVivo, Jugador *inicia, Videojuego *videojuego, Jugador **jugadores,std::string * nickname, int unidos)
  :Partida(fecha, duracion, inicia, videojuego)

{
  this->unidos=unidos;
  this->unen = jugadores;
  this->transmitidaEnVivo = transmitidaEnVivo;
  this->nicknameJ=nickname;

}

// PartidaMultijugador::~PartidaMultijugador(){
// };

//getters
bool PartidaMultijugador::getEnVivo(){
    return this->transmitidaEnVivo;
}

Jugador** PartidaMultijugador::getUnen(){
   return this->unen;
   }
std::string* PartidaMultijugador::getNicknames(){
    return this->nicknameJ;
}
int PartidaMultijugador::getUnidos(){
    return this->unidos;
}

//setters
void PartidaMultijugador::setEnVivo (bool envivo){
    this->transmitidaEnVivo=envivo;
}
void PartidaMultijugador::setUnidos(int unidos){
    this->unidos=unidos;
}

void PartidaMultijugador::setNicknames(std::string* nicknamej){
    this->nicknameJ=nicknamej;
}

float PartidaMultijugador::darTotalHorasParticipantes()
{
    return (getUnidos() + 1)*getDuracion();
}

