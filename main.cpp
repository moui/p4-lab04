#include "lib/Sistema.h"

#include <iostream>
#include <string>

using std::string;

int main(void)
{
  int op;

  cout << "menu principal" << endl;
  cout << "1 alta de usuario" << endl;
  cout << "2 iniciar sesion" << endl;
  cout << "3 modificar fecha del sistema" << endl;
  cout << "4 cargar datos de prueba" << endl;
  cout << "5 salir" << endl;
  cin >> op;

  Sistema* sistema = new Sistema();

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
        string nombreju;
        TipoJuego tipoju;

        cout << "Ingrese nombre: ";
        cin >> nombreju;
        cout << "Ingrese Genero del videojuego: Accion(0) / Aventura(1) / Deporte (2) / Otro(3):";
        cin >> tipoju;

        try {
          sistema->agregarVideojuego(nombreju, tipoju);
        }
        catch (const std::invalid_argument& err) {
	        std::cerr << "Error: " << err.what() << '\n';
        }
        break;
      }

      case 3 :
      {
        int cantob=0;

        DtJugador** ArregloJ = sistema->obtenerJugadores(cantob);

        cout << "Cantidad de jugadores: " << cantob << ".\n";
        for (int i=0; i<cantob; i++){
            cout <<ArregloJ[i]->getnick()<<", Edad:" << ArregloJ[i]->gete()<< ".\n";
        };
        cout << "\n";

        break;
      }

      case 4 :
        {
        int cantp=0;
        string vj;

        cout << "Por favor, ingrese el nombre del Videojuego:\n";
        cin >> vj;

        try {
          DtPartida** ArregloP = sistema->obtenerPartidas(vj, cantp);

          cout << "Cantidad de partidas: " << cantp << ".\n";
          for (int i=0; i<cantp; i++)
          {
            if (dynamic_cast<DtPartidaIndividual*>(ArregloP[i]) != NULL)
            { // infoPartidas[i] es instancia de DtPartidaIndividual
                DtPartidaIndividual* partida =  dynamic_cast<DtPartidaIndividual*>(ArregloP[i]);
                cout << *partida << endl;
            }
            else
            { // infoPartidas[i] es instancia de DtPartidaMultijugador
                DtPartidaMultijugador* partida =  dynamic_cast<DtPartidaMultijugador*>(ArregloP[i]);
                cout << *partida << endl;
            }
            delete ArregloP[i];
          };
          cout << "\n";
        }
        catch (const std::invalid_argument& err) {
	        std::cerr << "Error: " << err.what() << '\n';
        }
        break;
        }
      default :
        cout << "Selecciono una opcion no valida." << endl;
    }
    cin >> op;
  }

  delete sistema;
  return 0;

}
