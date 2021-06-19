#ifndef DESARROLLADOR
#define DESARROLLADOR

#include <string>
#include "Usuario.h"
#include "Videojuego.h"
#include "interfaces/IEstadistica.h"
#include "datatypes/DtVideojuego.h"
#include "datatypes/DtEstadistica.h"
#include "datatypes/DtDesarrollador.h"
#include "estadisticas/TotalHorasJuego.h"
#include "estadisticas/TotalJugadoresSuscritos.h"
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
    Videojuego* getVideojuego(string nomVJ);
 
    // Setters
    void setEmpresa(string empresa);
    void publicarVJ(Videojuego vj);
    // void setEstadistica(IEstadistica e);

    void mostrarUsuario();

    //seleccionar estadisticas

    void agregarEstadistica(int stat);

    //CONSULTAR ESTADISTICAS

    set<string> listarVideojuegosPublicados();
    set<DtEstadistica*> CalcularEstadisticas(string nomVJ);
};

#endif
