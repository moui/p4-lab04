#include "lib/interfaces/IUsuario.h"
#include "lib/Fabrica.h"

#include <iostream>
#include <string>

using namespace std;

int main(void)
{

  //IUsuario *IUsr = Fabrica::getInstancia()->getIUsuario();

  int op;

  cout << "menu principal" << endl;
  cout << "1 alta de usuario" << endl;
  cout << "2 iniciar sesion" << endl;
  cout << "3 modificar fecha del sistema" << endl;
  cout << "4 cargar datos de prueba" << endl;
  cout << "5 salir" << endl;
  cin >> op;

  while (op != 5)
  {
    switch(op)
    {
      case 1 :
      {
        string mail, contrasena, tipo, empresa, nickname, descripcion;
        bool flag;
        cout << "Ingrese mail: ";
        cin >> mail;
        cout << "Ingrese contrasena: ";
        cin >> contrasena;
        
        cout << "El usuario es Desarrollador o Jugador (d/j):";
        flag = false;
        while (flag==false) {
          cin >> tipo;
          if (tipo=="j") {
            cout << "Ingrese nickname:";
            cin >> nickname;
            cout << "Ingrese descripcion:";
            cin >> descripcion;
            //alta jugador  
            try {
              // sistema->agregarJugador(nickname, edad, contrasena);
            }
            catch (const std::invalid_argument& err) {
	            std::cerr << "Error: " << err.what() << '\n';
            }
          }
          else if (tipo=="d") {
            cout << "Ingrese empresa:";
            cin >> empresa;

            //alta desarrollador
            try {
             // sistema->agregarJugador(nickname, edad, contrasena);
            }
            catch (const std::invalid_argument& err) {
	            std::cerr << "Error: " << err.what() << '\n';
            }
          }
          else {
            cout << "Seleccione un tipo valido. (d/j)" << endl;
          }
        }
        break;
      }

      case 2 :
      {
        break;
      }

      case 3 :
      {
        break;
      }

      case 4 :
        {
        break;
        }
    }   
  }

  return 0;

}

