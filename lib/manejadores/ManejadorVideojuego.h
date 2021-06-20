#ifndef MANEJADORVIDEOJUEGO
#define MANEJADORVIDEOJUEGO

#include "../Videojuego.h"
#include "../Jugador.h"
#include "../Desarrollador.h"
#include "../Suscripcion.h"
#include "../DescripcionSuscripcion.h"
#include "../Categoria.h"
#include "../datatypes/DtCategoria.h"
#include "../datatypes/DtVideojuegoSuscripcion.h"

#include <string>
#include <map>
#include <set>
#include <algorithm>


using namespace std;

// Singleton.
class ManejadorVideojuego {
    private:
        // map
        map<string, Videojuego*> videojuegos;
        map<string, Videojuego*>::iterator itvj;

       /* map<string, DescripcionSuscripcion*> descSuscripcion;
        map<string, DescripcionSuscripcion*>::iterator itds;
*/
        map<string, Categoria*> categorias;
        map<string, Categoria*>::iterator itc;


    public:
        // Constructor
        ManejadorVideojuego();
        // Destructor
        ~ManejadorVideojuego();

        // Getters y mapters
        Videojuego* buscarVideojuego(string clave);
      /*  DescripcionSuscripcion* buscarDescripcionSuscripcion(string clave); */
        Categoria* buscarCategoria(string clave);

        void agregarVideojuego(string clave, Videojuego* vid);
      /*  void agregarDescripcionSuscripcion(string clave, DescripcionSuscripcion* ds);*/
        void agregarCategoria(string clave, Categoria* cat);

        void borrarVideojuego(string clave);
      /*  void borrarDescripcionSuscripcion(string clave);*/
        void borrarCategoria(string clave);

        //suscribirse

        map<string, DtVideojuegoSuscripcion*> ObtenerCatalogo();
        void agregarSuscrito(string nomVJ, string nomJ);

        //IniciarPartida

        set<DtCategoria*> listarCategorias();
        set<DtCategoria*> listarCategoriasGenero();
        set<DtCategoria*> listarCategoriasPlataforma();
        set<DtCategoria*> listarCategoriasOtros();

        set<string> listarNombresVideojuego();
};

#endif
