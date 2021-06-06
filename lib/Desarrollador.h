#ifndef DESARROLLADOR
#define DESARROLLADOR

#include <string>
#include "Usuario.h"

using namespace std;

class Desarrollador : public Usuario
{
  private:
    string empresa;
    set<Videojuegos*> publicados;
    set<Estadisticas*> seleccionadas;

  public:
    Desarrollador(string, string, string);
    ~Desarrollador();

    // Getters
    string getEmpresa();
    set<DtVideojuego*> getVJPub();
    set<string*> ListarVideojuegosPublicados();
    set<DtEstadisticas*> CalEst(idVJ:string);
 
    // Setters
    void setEmpresa(string empresa);
    void publicarVJ(Videojuego vj);
    void setEstadistica(Estadistica e);
};

#endif
