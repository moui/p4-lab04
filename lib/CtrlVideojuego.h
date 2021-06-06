#ifndef CTRLVIDEOJUEGO
#define CTRLVIDEOJUEGO

#include "interfaces/IVideojuego.h"
#include "Videojuego.h"
#include "Desarrollador.h"
#include <set>

using namespace std;

class CtrlVideojuego : public IVideojuego
{
    private:
        set<Suscripcion> suscripciones;
        set<DescripcionSuscripcion> descSuscripcion;
        set <Videojuego> catalogoVJ;

        static CtrlVideojuego * instancia;
        CtrlVideojuego();

        //Usuario * sesionActiva;

    public:
        ~CtrlVideojuego();

        //Usuario getSesionActiva();
        static CtrlVideojuego * getCtrlVideojuego();

        set<string>listarVideoJuegosDesarrollador();
        void videojuegoAEliminar(nombre: string);
        void cancelarEliminarVideoJuego();
        void confirmarEliminarVideoJuego();
        void ingresarDatosVideojuego(datos: DtVideojuego);
        set<Dtcategoria>listarCategorias();
        void seleccionarCategoria(nombre: String);
        DtVideojuego mostrarVideojuego();
        void cancelaPublicarVideojuego();
        void confirmaPublicarVideojuego();
        void confirmaPublicarVideojuego(Videojuego * v); // no se si es correcto, pero lo podemos cambiar, esta en el diagrama
        set<DtVideojuegosuscripcion> ObtenerCatalogo();
        void SuscribirseVideojuego(TipoPago pago, TipoPeriodo periodo);
        void AgregarSuscripcion(suscripcion *s); //para agregar en descSuscripcion
        void AltaSuscripcion(); //faltan parametros
        DtVideojuego verInfoVideojuego(string nombre);
};

#endif
