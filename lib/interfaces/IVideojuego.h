#ifndef IVIDEOJUEGO
#define IVIDEOJUEGO

#include <string>
#include <set>

using namespace std;
class IVideojuego
{
    public:
        IVideojuego();
        virtual ~IVideojuego();

        virtual set<string>listarVideoJuegosDesarrollador()=0;
        virtual void videojuegoAEliminar(nombre: string);
        virtual void cancelarEliminarVideoJuego();
        virtual void confirmarEliminarVideoJuego();
        virtual void ingresarDatosVideojuego(datos: DtVideojuego);
        virtual set<Dtcategoria>listarCategorias();
        virtual void seleccionarCategoria(nombre: String);
        virtual DtVideojuego mostrarVideojuego();
        virtual void cancelaPublicarVideojuego();
        virtual void confirmaPublicarVideojuego();
        virtual void confirmaPublicarVideojuego(Videojuego * v); // no se si es correcto, pero lo podemos cambiar, esta en el diagrama
        virtual set<DtVideojuegosuscripcion> ObtenerCatalogo();
        virtual void SuscribirseVideojuego(TipoPago pago, TipoPeriodo periodo);
        virtual void AgregarSuscripcion(suscripcion *s); //para agregar en descSuscripcion
        virtual void AltaSuscripcion(); //faltan parametros
        virtual DtVideojuego verInfoVideojuego(string nombre)();
};

#endif
