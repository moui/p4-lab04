#ifndef CTRLVIDEOJUEGO
#define CTRLVIDEOJUEGO

#include "../interfaces/IVideojuego.h"
#include "../Videojuego.h"
#include "../Desarrollador.h"
#include "../datatypes/DtVideojuegoSuscripcion.h"
#include "../datatypes/DtCategoria.h"
#include "../manejadores/ManejadorVideojuego.h"
#include "CtrlUsuario.h"
#include <set>

using namespace std;
class ManejadorVideojuego;

class CtrlVideojuego : public IVideojuego
{
    private:
    
        ManejadorVideojuego* manejadorVideojuego;
        static CtrlVideojuego * instancia;
        CtrlVideojuego();

        //memoria
        string nombre, descripcion;
        float costo1, costo3, costo12, costoV;        
        TipoCat tipo;
        set<Categoria*> cats;
        set<Categoria*>::iterator itcat;

    public:
        ~CtrlVideojuego();

        static CtrlVideojuego * getCtrlVideojuego();

        void videojuegoAEliminar(string nombre);
        void cancelarEliminarVideoJuego();
        void confirmarEliminarVideoJuego();


        DtVideojuego verInfoVideojuego(string nombre); 


        //suscribirse a Videojuego (caso de uso en CtrlUsuario), devuelve copia del catalogo
        map<string, DtVideojuegoSuscripcion*> ObtenerCatalogo(); 
        DtDescripcionSuscripcion* getDatosDescripcionSuscripcion(TipoPeriodo p, string nomVJ);
        void agregarSuscrito(string nomVJ, string nomJ);

        //publicar videojuego
        void ingresarDatosVideojuego(string, string, float, float, float, float);
        void cancela_publicarVideojuego();
        DtVideojuego* mostrarVideojuego();
        void confirma_publicarVideojuego();
        void seleccionarCategoria(string, TipoCat);
        set<DtCategoria*> listarCategoriasGenero();
        set<DtCategoria*> listarCategoriasPlataforma();
        set<DtCategoria*> listarCategoriasOtros();


        //categorias
        set<DtCategoria*> listarCategorias();
        void agregarCategoria(string nnombre, string ndescripcion, TipoCat ntipo);
        void confirma_agregarCategoria();
        void cancela_agregarCategoria();
        
        //IniciarPartida
	    void iniciadaP(Partida* p);
	    Videojuego* getVJ(string nomVJ);
};

#endif
