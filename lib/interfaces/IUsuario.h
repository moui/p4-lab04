#ifndef IUSUARIO
#define IUSUARIO

class IUsuario
{
    public:
        virtual ~IUsuario();

        virtual void altaUsuario() = 0;
        virtual void iniciarSesion() = 0;
};

#endif