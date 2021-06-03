#include "lib/Sistema.h"

#include <iostream>
#include <string>

using std::string;

int main(void)
{
  int op;

  cout << "Menu principal" << endl;
  cout << "1) agregar Jugador" << endl;
  cout << "2) agregar Videojuego" << endl;
  cout << "3) obtener Jugadores" << endl;
  cout << "4) obtener Partidas" << endl;
  cout << "5) obtener Videojuegos" << endl;
  cout << "6) iniciar Partida" << endl;
  cout << "0) Salir" << endl;
  cin >> op;

  Sistema* sistema = new Sistema();

  while (op != 0)
  {
    switch(op)
    {
      case 1 :
      {
        string nickname, contrasena;
        int edad;

        cout << "Ingrese nickname: ";
        cin >> nickname;
        cout << "Ingrese contrasena: ";
        cin >> contrasena;
        cout << "Ingrese edad del jugador: ";
        cin >> edad;

        try {
          sistema->agregarJugador(nickname, edad, contrasena);
        }
        catch (const std::invalid_argument& err) {
	        std::cerr << "Error: " << err.what() << '\n';
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

      case 5 :
    {
        int cantvj=0;

        DtVideojuego** ArregloVJ = sistema->obtenerVideojuegos(cantvj);

        cout << "Cantidad de Videojuegos: " << cantvj << ".\n";
        for (int i=0; i<cantvj; i++){
            cout << "Videojuego: " << ArregloVJ[i]->getn()<<", Genero: " << ArregloVJ[i]->getg()<< ", Total horas de juego: " << ArregloVJ[i]->getthj() << ".\n";
        };
        cout << "\n";

        break;
    }

     case 6 :
       {
        string nickname, videojuego, multi;

        cout << "Ingrese nombre Jugador: ";
        cin >> nickname;
        cout << "Ingrese nombre del videojuego: ";
        cin >> videojuego;

        cout <<"Partida Multijugador? S/N: ";
        cin >> multi;

        if (multi=="S") {
            string transmite;
            cout<< "Transmite en vivo? S/N: ";
            cin>> transmite;
            bool envivo = ((transmite=="S") ? true : false);
            int unidos;
            string nicknames;
            float duracion;
            cout<< "Ingrese Duracion: ";
            cin>> duracion;

            DtFechaHora f= DtFechaHora(0,0,0,0,0);



            cout<<"Ingrese Cantidad de Jugadores unidos: ";
            cin>>unidos;
            string *ArregloNicknames=new string [unidos];

            for (int j=0; j<unidos; j++){
            cout<< "Ingrese Nickname de Jugador unido: ";
            cin >> nicknames;
            ArregloNicknames[j]=nicknames;
            }
            DtPartida * datos= new DtPartidaMultijugador(f,duracion*unidos, envivo, ArregloNicknames, unidos);

            sistema->iniciarPartida(nickname, videojuego, datos);



        } else if (multi=="N"){
            string continua;
            cout<< "Continua Partida? S/N: ";
            cin>> continua;
            bool continuacion = ((continua=="S") ? true : false);

            float duracion;
            DtFechaHora f= DtFechaHora(0,0,0,0,0);

            cout<< "Ingrese Duracion: ";
            cin>> duracion;
            DtPartida *datos= new DtPartidaIndividual(f,duracion, continuacion);
            sistema->iniciarPartida(nickname, videojuego, datos);
        } else{
            cout<< "No ingreso S o N.";
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
