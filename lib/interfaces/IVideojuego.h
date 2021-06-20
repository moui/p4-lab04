#ifndef IVIDEOJUEGO
#define IVIDEOJUEGO

#include <string>
#include <set>

#include "../datatypes/DtVideojuegoSuscripcion.h"
#include "../datatypes/DtVideojuego.h"
#include "../Videojuego.h"
#include "../Suscripcion.h"

using namespace std;

class IVideojuego
{
    public:
        IVideojuego();
        virtual ~IVideojuego();

        // Operaciones ALTA CATEGORIA
        virtual set<DtCategoria*> listarCategorias() = 0;
        virtual void agregarCategoria(string nnombre, string ndescripcion, TipoCat ntipo) = 0; 
        virtual void confirma_agregarCategoria() = 0;
        virtual void cancela_agregarCategoria() = 0;

        // Operaciones PUBLICAR VIDEOJUEGO
        virtual void ingresarDatosVideojuego(string, string, float, float, float, float) = 0;
        virtual void cancela_publicarVideojuego() = 0;
        virtual void confirma_publicarVideojuego() = 0;
        virtual set<DtCategoria*> listarCategoriasGenero() = 0;
        virtual set<DtCategoria*> listarCategoriasPlataforma() = 0;
        virtual set<DtCategoria*> listarCategoriasOtros() = 0;
        virtual void seleccionarCategoria(string, TipoCat) = 0;
        virtual DtVideojuego* mostrarVideojuego() = 0;
        virtual DtVideojuego* verInfoVideojuego(string nombre) = 0;
        virtual void videojuegoAEliminar(string nombre) = 0;
        virtual void cancelar_eliminarVideoJuego() = 0;
        virtual void confirmar_eliminarVideoJuego() = 0;
        virtual map<string, string> listarNombresVideojuego() = 0;

        virtual void asignarPuntajeVideojuego(string, TipoPuntaje) = 0;

       /* virtual set<string>listarVideoJuegosDesarrollador()=0; */
};

#endif
