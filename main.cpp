#include "lib/Sistema.h"
#include "lib/const/Constantes.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    Sistema* Sistema = Sistema::getInstancia();
    int operacion = 1;

    cout << Constantes::MenuPrincipal;
    while (operacion != 0)
    {
        cout << "Ingrese codigo de operacion: ";
        cin >> operacion;
        
        switch (operacion)
        {
        case 1:
            // ALTA USUARIO
            break;
        case 2:
            // INICIAR SESION
            break;
        case 3:
            // MODIFICAR FECHA DEL SISTEMA
            break;
        case 4:
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

    delete Sistema;
    return 0;
}

