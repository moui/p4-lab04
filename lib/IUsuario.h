#ifndef IUSUARIO
#define IUSUARIO

class IUsuario
{
    public:
        IUsuario();
        virtual ~IUsuario();

        virtual void altaUsuario();
        virtual void iniciarSesion();
        virtual void agregarCategoria();
        virtual void seleccionarEstadistica();
        virtual void consultarEstadistica();
        virtual void seguirJugador();

        virtual void confirmaAltaJugador();
        virtual void cancelaAltaJugador();
        virtual void ingresaNicknameJugador(string nickname);
        virtual void ingresaDatosUauario(string mail, string contrasena);
        virtual void ingresaNombreEmpresa(string nombre);
        virtual void confirmaAltaDesarrollador();
        virtual void cancelaAltaDesarrollador();
        virtual set<string> listarVideojuegosPublicados();
        virtual void suscribirse(string nombre);
        virtual void cancelarOperacion();
        virtual void altaSuscripcion();        
};

#endif