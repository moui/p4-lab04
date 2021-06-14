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


        //caso de uso suscribirse a Videojuego

        

        //categorias
        set<DtCategoria> listarCategorias();
        void seleccionarCategoria(string nombre);
        void agregarCategoria(string nombre, string descripcion, TipoCat tipo);
        void confirma_agregarCategoria();
        void cancela_agregarCategoria();

};

#endif
