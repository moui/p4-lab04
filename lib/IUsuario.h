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
};

#endif