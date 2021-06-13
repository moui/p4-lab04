#include "lib/datatypes/DtFechaHora.h"
#include "lib/const/Constantes.h"

#include <iostream>
#include <limits>
#include <string>

#include "lib/helpers/FechaSistema.h"
#include "lib/datatypes/DtUsuario.h"
#include "lib/datatypes/DtJugador.h"
#include "lib/datatypes/DtDesarrollador.h"
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
            cout << Constantes::Separador << endl
                 << "                           ALTA DE USUARIO                                \n";
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

                        //}
                    }
                }
                break;
            }
            default:
                cout << "Ingreso una opcion invalida. Intente nuevamente. \n";
                break;
            }
            //  }
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
            }
            //}
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

                if (dynamic_cast<DtDesarrollador *>(usuario) != NULL)
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
            }
            catch (const std::invalid_argument &exception)
            {
                cout << exception.what() << '\n';
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
