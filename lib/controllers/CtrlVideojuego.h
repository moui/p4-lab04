#ifndef CTRLVIDEOJUEGO
#define CTRLVIDEOJUEGO

#include "../interfaces/IVideojuego.h"
#include "../Videojuego.h"
#include "../Desarrollador.h"
#include "../datatypes/DtVideojuegoSuscripcion.h"
#include "../datatypes/DtCategoria.h"
#include "../manejadores/ManejadorVideojuego.h"
#include <set>

using namespace std;

class CtrlVideojuego : public IVideojuego
{
    private:
        set<Suscripcion> suscripciones;
        set<DescripcionSuscripcion> descSuscripcion;
        set <Videojuego> catalogoVJ;

        ManejadorVideojuego* manejadorVideojuego;

        static CtrlVideojuego * instancia;
        CtrlVideojuego();

    public:
        ~CtrlVideojuego();

        static CtrlVideojuego * getCtrlVideojuego();

        set<string>listarVideoJuegosDesarrollador();
        void videojuegoAEliminar(string nombre);
        void cancelarEliminarVideoJuego();
        void confirmarEliminarVideoJuego();
        void ingresarDatosVideojuego(DtVideojuego datos);
        DtVideojuego mostrarVideojuego();
        void cancelaPublicarVideojuego();
        void confirmaPublicarVideojuego();
        void confirmaPublicarVideojuego(Videojuego * v); // no se si es correcto, pero lo podemos cambiar, esta en el diagrama
        set<DtVideojuegoSuscripcion> ObtenerCatalogo();
        void SuscribirseVideojuego(TipoPago pago, TipoPeriodo periodo);
        void AgregarSuscripcion(Suscripcion *s); //para agregar en descSuscripcion
        void AltaSuscripcion(); //faltan parametros
        DtVideojuego verInfoVideojuego(string nombre); 

        //categorias
        set<DtCategoria>listarCategorias();
        void seleccionarCategoria(string nombre);

};

#endif
