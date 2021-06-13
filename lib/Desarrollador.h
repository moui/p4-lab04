#ifndef DESARROLLADOR
#define DESARROLLADOR

#include <string>
#include "Usuario.h"
#include "Videojuego.h"
#include "interfaces/IEstadistica.h"
#include "datatypes/DtVideojuego.h"
#include "datatypes/DtEstadistica.h"
#include "datatypes/DtDesarrollador.h"
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
    set<DtEstadistica*> CalEst(string idVj);
 
    // Setters
    void setEmpresa(string empresa);
    void publicarVJ(Videojuego vj);
    void setEstadistica(IEstadistica e);

    void mostrarUsuario();
};

#endif
