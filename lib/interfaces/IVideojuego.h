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

        virtual set<DtCategoria*> listarCategorias() = 0;
        virtual void agregarCategoria(string nnombre, string ndescripcion, TipoCat ntipo) = 0; 
        virtual void seleccionarCategoria(string nombre) = 0;
        virtual void confirma_agregarCategoria() = 0;
        virtual void cancela_agregarCategoria() = 0;

        virtual void ingresarDatosVideojuego(string, string, float, float, float, float) = 0;
        virtual void cancela_publicarVideojuego() = 0;
        virtual void confirma_publicarVideojuego() = 0;

       /* virtual set<string>listarVideoJuegosDesarrollador()=0;
        virtual void videojuegoAEliminar(string nombre);
        virtual void cancelarEliminarVideoJuego();
        virtual void confirmarEliminarVideoJuego();
        virtual void ingresarDatosVideojuego(DtVideojuego datos);
        virtual DtVideojuego mostrarVideojuego();
        virtual void cancelaPublicarVideojuego();
        virtual void confirmaPublicarVideojuego();
        virtual void confirmaPublicarVideojuego(Videojuego * v); // no se si es correcto, pero lo podemos cambiar, esta en el diagrama
        virtual set<DtVideojuegoSuscripcion> ObtenerCatalogo();
        virtual void SuscribirseVideojuego(TipoPago pago, TipoPeriodo periodo);
        virtual void AgregarSuscripcion(Suscripcion *s); //para agregar en descSuscripcion
        virtual void AltaSuscripcion(); //faltan parametros
        virtual DtVideojuego verInfoVideojuego(string nombre); */
};

#endif
