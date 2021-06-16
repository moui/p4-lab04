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
class ManejadorVideojuego;

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
        DtVideojuego verInfoVideojuego(string nombre); 


        //suscribirse a Videojuego (caso de uso en CtrlUsuario), devuelve copia del catalogo
        map<string, DtVideojuegoSuscripcion*> ObtenerCatalogo(); 
        DtDescripcionSuscripcion* getDatosDescripcionSuscripcion(TipoPeriodo p, string nomVJ);

        //categorias
        set<DtCategoria*> listarCategorias();
        void seleccionarCategoria(string nombre);
        void agregarCategoria(string nombre, string descripcion, TipoCat tipo);
        void confirma_agregarCategoria();
        void cancela_agregarCategoria();
        
        //IniciarPartida
	void iniciadaP(Partida* p);
	Videojuego* getVJ(string nomVJ);
};

#endif
