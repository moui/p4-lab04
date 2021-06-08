#ifndef DESARROLLADOR
#define DESARROLLADOR

#include <string>
#include "Usuario.h"
#include <set>

using namespace std;

class Desarrollador : public Usuario
{
  private:
    string empresa;
    set<Videojuego*> publicados;
    set<IEstadistica*> seleccionadas;

  public:
    Desarrollador(string email, string contrasena, string empresa);
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
