#include "lib/datatypes/DtFechaHora.h"
#include "lib/const/Constantes.h"

#include <iostream>
#include <limits>
#include <string>
#include <set>

#include "lib/helpers/FechaSistema.h"
#include "lib/datatypes/DtUsuario.h"
#include "lib/datatypes/DtJugador.h"
#include "lib/datatypes/DtDesarrollador.h"
#include "lib/datatypes/DtVideojuegoSuscripcion.h"
#include "lib/datatypes/DtSuscripcion.h"
#include "lib/datatypes/DtFechaHora.h"
#include "lib/interfaces/IUsuario.h"
#include "lib/Fabrica.h"

using namespace std;

// Recibe y parsea string a DtFechaHora. Si el formato ingresado es invalido devuelve NULL.
static DtFechaHora *ValidarFechaSistema();

int main()
{
    FechaSistema *fechaSistema = new FechaSistema();
    IUsuario *IUsr = Fabrica::getInstancia()->getIUsuario();
    //IVideojuego *IVid = Fabrica::getInstancia()->getIVideojuego(); si se usa descomentar
    string mail, contrasena;
    int operacion = 1;
    cout << Constantes::MenuPrincipal;
    while (operacion != 0)
    {
        cout << "Ingrese codigo de operacion: ";
        cin >> operacion;

        switch (operacion)
        {
        case 1:
        {
            string empresa, nickname, descripcion;
            char tipo, repe, conf;
            bool aconfirmar, reintentar;
            cout << Constantes::PresentacionAltaUsuario_Inicio;
            cout << "Ingrese mail: ";
            cin >> mail;
            cout << "Ingrese contrasena: ";
            cin >> contrasena;
            try
            {
                IUsr->ingresaDatosUsuario(mail, contrasena);
            }
            catch (const std::invalid_argument &err)
            {
                cerr << "Error: " << err.what() << '\n';
            }
            cout << "Ingrese el tipo de usuario: (D)esarrollador o (J)ugador? ";
            // while (tipo != 'D' || tipo != 'J'){
            cin >> tipo;
            switch (tipo)
            {
            case 'D':
            {
                cout << "Ingrese empresa: ";
                cin >> empresa;
                //alta desarrollador
                try
                {
                    IUsr->ingresaDatosDesarrollador(empresa);
                    aconfirmar = true;
                }
                catch (const std::invalid_argument &err)
                {
                    cerr << "Error: " << err.what() << '\n';
                    aconfirmar = false;
                }
                break;
            }
            case 'J':
            {
                reintentar = true;
                while (reintentar)
                {
                    cout << "Ingrese nickname: ";
                    cin >> nickname;
                    cout << "Ingrese descripcion: ";
                    cin >> descripcion;
                    try
                    {
                        IUsr->ingresaDatosJugador(nickname, descripcion);
                        aconfirmar = true;
                        reintentar = false;
                    }
                    catch (const std::invalid_argument &err)
                    {
                        cerr << "Error: " << err.what() << '\n';
                        cout << "Desea (R)eintentar o (C)ancelar? ";
                        cin >> repe;
                        //  while (repe != 'R' || repe != 'C'){
                        switch (repe)
                        {
                        case 'R':
                        {
                            reintentar = true;
                            break;
                        }
                        case 'C':
                        {
                            aconfirmar = false;
                            reintentar = false;
                            break;
                        }
                        default:
                            cout << "Ingreso una opcion invalida. Intente nuevamente. \n";
                            break;
                        }
                    }
                }
                break;
            }
            default:
                cout << "Ingreso una opcion invalida. Intente nuevamente. \n";
                break;
            }

            if (aconfirmar == true)
            {
                cout << "Desea confirmar el (A)lta o (C)ancelar? ";
                cin >> conf;
                //  while (conf != 'A' || repe != 'C'){
                switch (conf)
                {
                case 'A':
                {
                    if (tipo == 'J')
                    {
                        try
                        {
                            IUsr->confirmaAltaJugador();
                        }
                        catch (const std::invalid_argument &err)
                        {
                            cerr << "Error: " << err.what() << '\n';
                        }
                    }
                    else
                    {
                        try
                        {
                            IUsr->confirmaAltaDesarrollador();
                        }
                        catch (const std::invalid_argument &err)
                        {
                            cerr << "Error: " << err.what() << '\n';
                        }
                    }
                    break;
                }
                case 'C':
                {
                    try
                    {
                        IUsr->cancelaAlta();
                    }
                    catch (const std::invalid_argument &err)
                    {
                        cerr << "Error: " << err.what() << '\n';
                    }
                    break;
                }
                default:
                    cout << "Ingreso una opcion invalida. Intente nuevamente. \n";
                    break;
                }
                cout << Constantes::Separador;
            }
            else
            {
                try
                {
                    IUsr->cancelaAlta();
                }
                catch (const std::invalid_argument &err)
                {
                    cerr << "Error: " << err.what() << '\n';
                }
            }
            break;
        }
        case 2:
        {
            int subOperacion = 1;
            cout << Constantes::PresentacionIniciarSesion_Inicio;
            cout << "Ingrese mail: ";
            cin >> mail;
            cout << "Ingrese contrasena: ";
            cin >> contrasena;
            try
            {
                DtUsuario *usuario = IUsr->iniciarSesion(mail, contrasena);
                cout << Constantes::PresentacionIniciarSesion_Fin << usuario->getEmail() << ".\n";

                if (dynamic_cast<DtDesarrollador*>(usuario) != NULL)
                { // usuario es instancia de DtDesarrollador
                    // DtDesarrollador *desarrollador = dynamic_cast<DtDesarrollador*>(usuario);
                    
                    // MENU DESARROLLADOR
                    cout << Constantes::MenuDesarrollador;
                    while (subOperacion != 0)
                    {
                        cout << Constantes::IngresarOperacion;
                        cin >> subOperacion;
                        switch (subOperacion)
                        {
                        case 1:
                        {
                            // AGREGAR CATGORIA
                            break;
                        }
                        case 2:
                        {
                            // PUBLICAR VIDEOJUEGO
                            break;
                        }
                        case 3:
                        {
                            // ELIMINAR VIDEOJUEGO
                            break;
                        }
                        case 4:
                        {
                            // SELECCIONAR ESTADISTICAS
                            break;
                        }
                        case 5:
                        {
                            // CONSULTAR ESTADISTICAS
                            break;
                        }
                        case 6:
                        {
                            // VER INFORMACION DE VIDEOJUEGO
                            break;
                        }
                        case 0:
                        {
                            // SALIR
                            break;
                        }
                        default:
                            cout << "Codigo invalido.\n";
                            break;
                        }
                    }
                }
                else
                { // usuario es instancia de DtJugador
                    // DtJugador *jugador = dynamic_cast<DtJugador*>(usuario);
                    
                    // MENU JUGADOR
                    cout << Constantes::MenuJugador;
                    while (subOperacion != 0)
                    {
                        cout << Constantes::IngresarOperacion;
                        cin >> subOperacion;
                        switch (subOperacion)
                        {
                        case 1:
                        {
                            // SUSCRIBIRSE A VIDEOJUEGO
                            cout << Constantes::PresentacionSuscribirse;
                            try 
                            {
                             set<DtVideojuegoSuscripcion*> sa = IUsr->listarVideojuegoSuscripcionesActivas();
                             set<DtVideojuegoSuscripcion*> sna = IUsr->listarVideojuegoSuscripcionesNoActivas();
                             cout << "SUSCRIPCIONES ACTIVAS: \n";
                             for (set<DtVideojuegoSuscripcion*>::iterator itsa=sa.begin(); itsa!=sa.end(); itsa++){
                                 cout<< *itsa;
                             };
                             cout << Constantes::Separador;
                             cout << "SUSCRIPCIONES NO ACTIVAS: \n";
                             for (set<DtVideojuegoSuscripcion*>::iterator itsna=sna.begin(); itsna!=sna.end(); itsna++){
                                 cout<< *itsna;
                             };
                             cout << Constantes::Separador;
                             cout << "Seleccione un Videojuego para suscribirse: \n";
                            // cin >> string nomVJ;
                            
                            }
                            catch (const std::invalid_argument &err)
                            {
                            cerr << "Error: " << err.what() << '\n';
                            }
                            break;
                        }
                        case 2:
                        {
                            // ASIGNAR PUNTAJE A VIDEOJUEGO
                            break;
                        }
                        case 3:
                        {
                            // INICIAR PARTIDA
                            break;
                        }
                        case 4:
                        {
                            // ABANDONAR PARTIDA MULTIJUGADOR
                            break;
                        }
                        case 5:
                        {
                            // FINALIZAR PARTIDA
                            break;
                        }
                        case 6:
                        {
                            // VER INFORMACION DE VIDEOJUEGO
                            break;
                        }
                        case 0:
                        {
                            // SALIR
                            break;
                        }
                        default:
                            cout << "Codigo invalido.\n";
                            break;
                        }
                    }                
                }
                cout << Constantes::MenuPrincipal;
                delete usuario;
            }
            catch (const std::invalid_argument &exception)
            {
                cout << exception.what() << '\n' << Constantes::Separador;
            }
            break;
        }
        case 3:
            // MOSTRAR FECHA DEL SISTEMA
            cout << Constantes::PresentacionFechaActual << *(fechaSistema->getFecha()) << Constantes::Separador;
            break;
        case 4:
        {
            // MODIFICAR FECHA DEL SISTEMA
            cout << Constantes::PresentacionModificarFecha_Inicio;
            DtFechaHora *nuevaFecha = ValidarFechaSistema();
            while (nuevaFecha == NULL)
            {
                cout << Constantes::MsjeErrorIngresoFecha;
                nuevaFecha = ValidarFechaSistema();
            }
            fechaSistema->setFecha(nuevaFecha);
            cout << Constantes::PresentacionModificarFecha_Fin;
            break;
        }
        case 5:
            // CARGAR DATOS DE PRUEBA

            //cargar desarrolladores
            IUsr->ingresaDatosUsuario("ironhide@mail.com", "123");
            IUsr->ingresaDatosDesarrollador("Ironhide Game Studio");
            IUsr->confirmaAltaDesarrollador();

            IUsr->ingresaDatosUsuario("epic@mail.com", "123");
            IUsr->ingresaDatosDesarrollador("Epic Games");
            IUsr->confirmaAltaDesarrollador();

            IUsr->ingresaDatosUsuario("mojang@mail.com", "123");
            IUsr->ingresaDatosDesarrollador("Mojang Studios");
            IUsr->confirmaAltaDesarrollador();

            IUsr->ingresaDatosUsuario("ea@mail.com", "123");
            IUsr->ingresaDatosDesarrollador("EA Sports");
            IUsr->confirmaAltaDesarrollador();

            //cargar jugadores
            IUsr->ingresaDatosUsuario("gamer@mail.com", "123");
            IUsr->ingresaDatosJugador("gamer", "soy gamer");
            IUsr->confirmaAltaJugador();

            IUsr->ingresaDatosUsuario("ari@mail.com", "123");
            IUsr->ingresaDatosJugador("ari", "soy ari");
            IUsr->confirmaAltaJugador();

            IUsr->ingresaDatosUsuario("ibai@mail.com", "123");
            IUsr->ingresaDatosJugador("ibai", "soy ibai");
            IUsr->confirmaAltaJugador();

            IUsr->ingresaDatosUsuario("camila@mail.com", "123");
            IUsr->ingresaDatosJugador("camila", "soy camila");
            IUsr->confirmaAltaJugador();

            //carga categorias
            
            break;
        case 0:
            // SALIR
            break;
        default:
            cout << "Codigo invalido.\n";
            break;
        }
    }

    Fabrica::destruir();
    delete fechaSistema;
    return 0;
}

static DtFechaHora *ValidarFechaSistema()
{
    int DD, MM, AAAA, HH, mm;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.clear();

    cin >> DD;
    if (!cin || DD < 1 || DD > 31)
    {
        cin.clear();
        return NULL;
    }
    if (cin.get() != '-')
    {
        cin.clear();
        return NULL;
    }

    cin >> MM;
    if (!cin || MM < 1 || MM > 12)
    {
        cin.clear();
        return NULL;
    }
    if (cin.get() != '-')
    {
        cin.clear();
        return NULL;
    }

    cin >> AAAA;
    if (!cin || AAAA < 1900 || AAAA > 3000)
    {
        cin.clear();
        return NULL;
    }
    if (cin.get() != '@')
    {
        cin.clear();
        return NULL;
    }

    cin >> HH;
    if (!cin || HH < 0 || HH > 23)
    {
        cin.clear();
        return NULL;
    }
    if (cin.get() != '-')
    {
        cin.clear();
        return NULL;
    }

    cin >> mm;
    if (!cin || mm < 0 || mm > 59)
    {
        cin.clear();
        return NULL;
    }

    return new DtFechaHora(DD, MM, AAAA, HH, mm);
}
