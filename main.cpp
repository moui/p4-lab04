#include "lib/datatypes/DtFechaHora.h"
#include "lib/const/Constantes.h"

#include <iostream>
#include <limits>
#include <string>

#include "lib/helpers/FechaSistema.h"
#include "lib/datatypes/DtFechaHora.h"
#include "lib/interfaces/IUsuario.h"
#include "lib/Fabrica.h"

using namespace std;

// Recibe y parsea string a DtFechaHora. Si el formato ingresado es invalido devuelve NULL.
static DtFechaHora* ValidarFechaSistema();

int main()
{
    FechaSistema* fechaSistema = new FechaSistema();
    IUsuario *IUsr = Fabrica::getInstancia()->getIUsuario();
    int operacion = 1;
    string mail, contrasena, tipo, empresa, nickname, descripcion, confirma;
    cout << Constantes::MenuPrincipal;
    while (operacion != 0)
    {
        cout << "Ingrese codigo de operacion: ";
        cin >> operacion;

        switch (operacion)
        {
        case 1:
        {
            bool flag;
            cout << Constantes::Separador << endl << "                           ALTA DE USUARIO                                \n";
            cout << "Ingrese mail: ";
            cin >> mail;
            cout << "Ingrese contrasena: ";
            cin >> contrasena;
            try {
                IUsr->ingresaDatosUsuario(mail, contrasena);
            }
            catch (const std::invalid_argument& err) {
                cerr << "Error: " << err.what() << '\n';
            }
            cout << "El usuario es Desarrollador o Jugador (d/j): ";
            flag = false;
            while (flag==false) {
            cin >> tipo;
            if (tipo=="j") {
                cout << "Ingrese nickname: ";
                cin >> nickname;
                cout << "Ingrese descripcion: ";
                cin >> descripcion;
                try {
                    IUsr->ingresaDatosJugador(nickname, descripcion);
                }
                catch (const std::invalid_argument& err) {
                    cerr << "Error: " << err.what() << '\n';
                }
            }
            else if (tipo=="d") {
                cout << "Ingrese empresa: ";
                cin >> empresa;
                //alta desarrollador
                try {
                    IUsr->ingresaDatosDesarrollador(empresa);
                }
                catch (const std::invalid_argument& err) {
                    cerr << "Error: " << err.what() << '\n';
                }
            }
            else {
                cout << "Seleccione un tipo valido. (d/j): " ;
            }
            }
            cout << "Desea confirmar el alta de usuario? (y/n): ";
            flag = false;
            while (flag==false) {
            cin >> confirma;
            if (confirma=="y") {
                if (tipo=="j") {
                    try {
                        IUsr->confirmaAltaJugador();
                    }
                    catch (const std::invalid_argument& err) {
                        cerr << "Error: " << err.what() << '\n';
                    }
                }
                else if (tipo=="d") {
                    try {
                        IUsr->confirmaAltaDesarrollador();
                    }
                    catch (const std::invalid_argument& err) {
                        cerr << "Error: " << err.what() << '\n';
                    }
                }
            }
            else if (confirma=="n") {
                try {
                    IUsr->cancelaAlta();
                }
                catch (const std::invalid_argument& err) {
                    cerr << "Error: " << err.what() << '\n';
                }
            }
            else {
                cout << "Seleccione una opcion valida. (y/n): " ;
            }
            }
            break;
        }
        case 2:
            // INICIAR SESION
            break;
        case 3:
            // MOSTRAR FECHA DEL SISTEMA
            cout << Constantes::PresentacionFechaActual << *(fechaSistema->getFecha()) << Constantes::Separador;
            break;
        case 4:
        {
            // MODIFICAR FECHA DEL SISTEMA
            cout << Constantes::PresentacionModificarFecha_Inicio;
            DtFechaHora* nuevaFecha = ValidarFechaSistema();
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

    delete fechaSistema;
    return 0;
}

static DtFechaHora* ValidarFechaSistema()
{
    int DD, MM, AAAA, HH, mm;

    cin.ignore(numeric_limits<streamsize>::max(),'\n');
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

    return new DtFechaHora(DD,MM,AAAA,HH,mm);
}
