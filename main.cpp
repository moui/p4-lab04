#include "lib/datatypes/DtFechaHora.h"
#include "lib/const/Constantes.h"

#include <iostream>
#include <limits>
#include <string>
#include <set>

#include "lib/helpers/FechaSistema.h"
#include "lib/datatypes/DtUsuario.h"
#include "lib/datatypes/DtJugador.h"
#include "lib/datatypes/DtEstadistica.h"
#include "lib/datatypes/DtDesarrollador.h"
#include "lib/datatypes/DtVideojuegoSuscripcion.h"
#include "lib/datatypes/TipoEstado.h"
#include "lib/datatypes/DtSuscripcion.h"
#include "lib/datatypes/DtFechaHora.h"
#include "lib/interfaces/IUsuario.h"
#include "lib/datatypes/TipoCat.h"
#include "lib/Fabrica.h"

using namespace std;

// Recibe y parsea string a DtFechaHora. Si el formato ingresado es invalido devuelve NULL.
static DtFechaHora *ValidarFechaSistema();

int main()
{
    FechaSistema *fechaSistema = new FechaSistema();
    IUsuario *IUsr = Fabrica::getInstancia()->getIUsuario();
    IVideojuego *IVid = Fabrica::getInstancia()->getIVideojuego();
    IPartida *IPar = Fabrica::getInstancia()->getIPartida();

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
                            string nombrecat, descricat;
                            char conf;
                            TipoCat tipoca;
                            cout << Constantes::PresentacionAgregarCategoria_Inicio << "CATALOGO DE CATEGORIAS" << endl << endl;
                            set<DtCategoria*> setcat = IVid->listarCategorias();
                            set<DtCategoria*>::iterator itcat;
                            if (setcat.empty())
                                cout << "No existen categorias en el catalogo." << endl << endl;
                            for (auto itcat = setcat.begin(); itcat != setcat.end(); ++itcat) {
                                cout << *(*itcat) << endl;
                            }
                            cout << "Ingrese el nombre de la nueva categoria: ";
                            cin >> nombrecat;
                            cout << "Ingrese la descripcion de la nueva categoria: ";
                            cin >> descricat;
                            cout << "Ingrese el tipo de la nueva categoria (0)Plataforma, (1)Genero, (2)Otro: ";
                            cin >> tipoca;
                            IVid->agregarCategoria(nombrecat, descricat, tipoca);
                            cout << "Desea confirmar el (A)lta o (C)ancelar? ";
                            cin >> conf;
                            switch (conf)
                            {
                            case 'A':
                                IVid->confirma_agregarCategoria();
                                cout << "Categoria agregada." << endl << Constantes::Separador;
                                break;
                            case 'C':
                                IVid->cancela_agregarCategoria();
                                cout << "Alta cancelada." << endl << Constantes::Separador;
                                break;
                            default:
                                cout << "Ingreso una opcion invalida. Intente nuevamente. \n";
                                break;
                            }

                            if (!setcat.empty())
                            {
                                for (itcat = setcat.begin(); itcat != setcat.end(); ++itcat)
                                {
                                    if (*itcat != NULL)
                                        delete *itcat;
                                }
                                setcat.clear();
                            }
                            break;
                        }
                        case 2:
                        {
                            // PUBLICAR VIDEOJUEGO
                            cin.clear();

                            string nombrevj, desvj, catgen, nombrecat;
                            char conf;
                            float c1, c3, c12, cv;
                            int totCat = 0;
                            cout << Constantes::PresentacionPublicarVideojuego_Inicio;
                            // Ingresa datos basicos del videojuego
                            cout << "Ingrese nombre del videojuego: ";
                            cin.ignore();
                            getline(cin, nombrevj);
                            cout << "Ingrese descripcion del videojuego: ";
                            cin.ignore();
                            getline(cin, desvj);
                            cout << "Ingrese costo de suscripcion mensual: ";
                            cin >> c1;
                            cout << "Ingrese costo de suscripcion trimestral: ";
                            cin >> c3;
                            cout << "Ingrese costo de suscripcion anual: ";
                            cin >> c12;
                            cout << "Ingrese costo de suscripcion vitalicia: ";
                            cin >> cv;
                            IVid->ingresarDatosVideojuego(nombrevj, desvj, c1, c3, c12, cv);
                            // Seleccionar categoria genero. Al menos 1
                            cout << "CATALOGO CATEGORIAS GENERO: " << endl << endl;
                            set<DtCategoria*> setCatGen = IVid->listarCategoriasGenero();
                            set<DtCategoria*>::iterator itCat;
                            if (setCatGen.empty())
                                cout << "No existen categorias en el catalogo." << endl << endl;
                            for (itCat = setCatGen.begin(); itCat != setCatGen.end(); ++itCat) {
                                cout << *(*itCat) << endl;
                            }
                            cout << "Ingrese los nombres de las categorias que desea (TIPO GENERO). Ingrese al menos una." << endl;
                            cin.ignore();
                            totCat = 0;
                            while (true) 
                            {
                                cout << "Ingrese nombre o 'cont' para continuar: ";
                                getline(cin, nombrecat);
                                if (nombrecat == "cont" && totCat > 0)    
                                    break;
                                try 
                                {
                                    IVid->seleccionarCategoria(nombrecat, TipoCat::Genero);
                                    cout << "Registrada categoria " << nombrecat << endl;
                                    totCat++;
                                }
                                catch (const std::invalid_argument &err)
                                {
                                    cerr << "Error: " << err.what() << '\n';
                                }
                            }
                            // Seleccionar categoria plataforma. Al menos 1
                            set<DtCategoria*> setCatPlat = IVid->listarCategoriasPlataforma();
                            cout << "CATALOGO CATEGORIAS PLATAFORMA: " << endl << endl;
                            if (setCatPlat.empty())
                                cout << "No existen categorias en el catalogo." << endl << endl;
                            for (itCat = setCatPlat.begin(); itCat != setCatPlat.end(); ++itCat) {
                                cout << *(*itCat) << endl;
                            }
                            cout << "Ingrese los nombres de las categorias que desea (TIPO PLATAFORMA). Ingrese al menos una." << endl;
                            totCat = 0;
                            while (true) 
                            {
                                cout << "Ingrese nombre o 'cont' para continuar: ";
                                getline(cin, nombrecat);
                                if (nombrecat == "cont" && totCat > 0)    
                                    break;
                                try 
                                {
                                    IVid->seleccionarCategoria(nombrecat, TipoCat::Plataforma);
                                    cout << "Registrada categoria " << nombrecat << endl;
                                    totCat++;
                                }
                                catch (const std::invalid_argument &err)
                                {
                                    cerr << "Error: " << err.what() << '\n';
                                }
                            }
                            // Seleccionar categoria otros. Sin minimo.
                            set<DtCategoria*> setCatOtros = IVid->listarCategoriasOtros();
                            cout << "CATALOGO CATEGORIAS OTROS: " << endl << endl;
                            if (setCatOtros.empty())
                                cout << "No existen categorias en el catalogo." << endl << endl;
                            for (itCat = setCatOtros.begin(); itCat != setCatOtros.end(); ++itCat) 
                            {
                                cout << *(*itCat) << endl;
                            }
                            cout << "Ingrese los nombres de las categorias que desea (TIPO OTRO). No hay minimo." << endl;
                            while (true) 
                            {
                                cout << "Ingrese nombre o 'cont' para continuar: ";
                                getline(cin, nombrecat);
                                if (nombrecat == "cont")
                                    break;
                                try 
                                {
                                    IVid->seleccionarCategoria(nombrecat, TipoCat::Otro);
                                    cout << "Registrada categoria " << nombrecat << endl;  
                                    totCat++;
                                }
                                catch (const std::invalid_argument &err)
                                {
                                    cerr << "Error: " << err.what() << '\n';
                                }
                            }
                            // Mostrar info videojuego.
                            DtVideojuego* infoVideojuego = IVid->mostrarVideojuego(); 
                            cout << Constantes::Separador << endl << "VIDEOJUEGO A PUBLICAR" << endl << endl
                                 << *infoVideojuego << endl;

                            //alta o cancela
                            cout << "Desea confirmar el (A)lta o (C)ancelar? ";
                            cin >> conf;
                            switch (conf)
                            {
                            case 'A':
                                IVid->confirma_publicarVideojuego();
                                cout << "Videojuego publicado." << endl << Constantes::Separador;
                                break;
                            case 'C':
                                IVid->cancela_publicarVideojuego();
                                cout << "Alta cancelada." << endl << Constantes::Separador;
                                break;
                            default:
                                cout << "Ingreso una opcion invalida. Intente nuevamente. \n";
                                break;
                            }

                            // Borrar memoria DtCats y DtVideojueo
                            delete infoVideojuego; 
                            if (!setCatGen.empty())
                                for (itCat = setCatGen.begin(); itCat != setCatGen.end(); ++itCat)
                                {
                                    if (*itCat != NULL)
                                        delete *itCat;
                                }
                            if (!setCatPlat.empty())
                                for (itCat = setCatPlat.begin(); itCat != setCatPlat.end(); ++itCat)
                                {
                                    if (*itCat != NULL)
                                        delete *itCat;
                                }
                            if (!setCatOtros.empty())
                                for (itCat = setCatOtros.begin(); itCat != setCatOtros.end(); ++itCat)
                                {
                                    if (*itCat != NULL)
                                        delete *itCat;
                                }
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
                            bool stat1=false;
                            bool stat2=false;
                            int opcion=-1;
                            cout << Constantes::PresentacionSeleccionarEstadisticas;
                            IUsr->listarEstadisticas();
                            cout << Constantes::Separador;
                            try 
                            {
                                while (opcion!=0)
                                {
                                    cout << "Por favor, ingrese las estadisticas deseadas, ingrese (0) para cancelar: \n";
                                    cin >> opcion;
                                    switch(opcion)
                                    {   
                                        case 0: break;
                                        case 1:stat1=true; break;
                                        case 2:stat2=true; break;
                                        default: cout << "No ingreso una opcion valida. \n"; break;
                                    }
                                    IUsr->seleccionarEstadisticas(stat1, stat2);
                                
                                }
                            }
                            catch (const std::invalid_argument &err)
                             {
                                  cerr << "Error: " << err.what() << '\n';
                             }

                            cout << Constantes::PresentacionSeleccionarEstadisticas_Fin;

                            break;
                        }
                        case 5:
                        {
                            // CONSULTAR ESTADISTICAS
                            cout << Constantes::PresentacionConsultarEstadisticas;
                            string nomVJ;
                            try
                            {
                                set<string> VJpublicados=IUsr->listarVideojuegosPublicados();
                                cout << "Videojuegos publicados: \n";
                                for(set<string>::iterator i=VJpublicados.begin(); i!=VJpublicados.end(); i++)
                                {
                                    cout << "||" << (*i) << "|| \n";
                                }
                                cout << "Por favor, seleccione el juego para consultar estadisticas. \n";
                                cin >> nomVJ;
                                set<DtEstadistica*> stats= IUsr->ConsultarEstadisticas(nomVJ);
                            }
                            catch (const std::invalid_argument &err)
                             {
                                  cerr << "Error: " << err.what() << '\n';
                             }
                            cout << Constantes::PresentacionConsultarEstadisticas_Fin; 
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
                             string nomVJ;                            
                             cout << "Seleccione un Videojuego para suscribirse: \n";
                             cin >> nomVJ;
                             TipoEstado estado=IUsr->JuegoSuscribirse(nomVJ);
                             switch(estado)
                             {
                             case (TipoEstado::activa):
                             {
                                 char cancela;
                                 cout << "Desea cancelar su sucripcion temporal a: " << nomVJ << "Y/n? \n";
                                 cin >> cancela;
                                 switch(cancela)
                                 {
                                 case 'Y':
                                 {
                                    try
                                     {
                                         IUsr->CancelarSuscripcion(nomVJ);
                                     }
                                     catch (const std::invalid_argument &err)
                                     {
                                      cerr << "Error: " << err.what() << '\n';
                                     }
                                     break;
                                 } 
                                 default:
                                    break;
                                 }
                             }
                             case (TipoEstado::cancelada):
                             case (TipoEstado::expirada):
                             {
                                 int pago, validez;
                                 cout << "Seleccione metodo de pago: (1) Paypal | (2) Tarjeta | (3) Otro: \n";
                                 cin >> pago;
                                 cout << "Seleccione periodo de validez: (1) Mensual | (3) Trimestral | (12) Anual | (0) Vitalicia: \n";
                                 cin >> validez;                                 
                             try
                             {
                                 IUsr->SuscribirseVideojuego(pago, validez, nomVJ);
                             }
                             catch (const std::invalid_argument &err)
                             {
                              cerr << "Error: " << err.what() << '\n';
                             }
                                break;
                             }
                             default:
                                break;
                             }   
                             char confirma;
                             cout << "Desea confirmar el (A)lta suscripcion o (C)ancelar alta? ";
                             cin >> confirma;
                             switch(confirma)
                             {
                                 case 'A':
                                 {
                                    try
                                    {
                                        IUsr->AltaSuscripcion();
                                        cout << Constantes::PresentacionSuscribirse_Fin;
                                        IUsr->CancelarOperacion();
                                    }
                                    catch (const std::invalid_argument &err)
                                    {
                                    cerr << "Error: " << err.what() << '\n';
                                    }
                                    break;   
                                 }
                                 case 'C':
                                 {
                                    try
                                    {
                                        IUsr->CancelarOperacion();
                                    }
                                    catch (const std::invalid_argument &err)
                                    {
                                    cerr << "Error: " << err.what() << '\n';
                                    }
                                    break;   
                                 }
                             }
                             
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
                            IPar->cancelarIniciarPartida();
                            /*try 
                            {
                              set<DtVideojuegoSuscripcion*> sa = IUsr->listarVideojuegoSuscripcionesActivas();
			                  cout << "SUSCRIPCIONES ACTIVAS: \n";
                              for (set<DtVideojuegoSuscripcion*>::iterator itsa=sa.begin(); itsa!=sa.end(); itsa++){
                                   cout<< *itsa;
                              };
			                  cout << Constantes::Separador;
                              string nomVJ;                            
                              cout << "Seleccione un Videojuego al que jugar: \n";
                              cin >> nomVJ;
			                  IPar->crearPartida(nomVJ);
			                  char tipo;
			                  cout << "Quiere iniciar una partida (I)ndividual o (M)ultijugador: \n";
			                  cin >> tipo;
			                  switch(tipo) 
			                  {
				                case'I' 
				                {
				                    try{
				                        char cont;
                                        cout << "Desea continuar una partida previa Y/n? \n";
				                        cin >> cont;
				                        if {
					
				                        }
				                    }
			                    }
			                  }
			                }*/
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
            
            IVid->agregarCategoria("PC", "Sos Gamer?", TipoCat::Plataforma);
            IVid->confirma_agregarCategoria();

            IVid->agregarCategoria("PS4", "Sony", TipoCat::Plataforma);
            IVid->confirma_agregarCategoria();
            
            IVid->agregarCategoria("Xbox One", "Microsoft", TipoCat::Plataforma);
            IVid->confirma_agregarCategoria();

            IVid->agregarCategoria("Deporte", "Aprende deportes", TipoCat::Genero);
            IVid->confirma_agregarCategoria();

            IVid->agregarCategoria("Supervivencia", "Aprende a sobrevivir", TipoCat::Genero);
            IVid->confirma_agregarCategoria();
            
            IVid->agregarCategoria("Estrategia", "Desarrolla tu mente", TipoCat::Genero);
            IVid->confirma_agregarCategoria();

            IVid->agregarCategoria("Teen", "Su contenido esta dirigido a jovenes de 13 años en adelante", TipoCat::Otro);
            IVid->confirma_agregarCategoria();

            IVid->agregarCategoria("E", "Su contenido esta dirigido para todo publico", TipoCat::Otro);
            IVid->confirma_agregarCategoria();
            
            IVid->agregarCategoria("Accion", "Pa cagarse a tirito", TipoCat::Genero);
            IVid->confirma_agregarCategoria();

            IVid->agregarCategoria("Aventura", "Mejor es salir a vivirlas", TipoCat::Genero);
            IVid->confirma_agregarCategoria();

            IVid->agregarCategoria("Switch", "Nintento", TipoCat::Plataforma);
            IVid->confirma_agregarCategoria();
            
            IVid->agregarCategoria("Xbox X", "Si no existe lo inventamos", TipoCat::Plataforma);
            IVid->confirma_agregarCategoria();

            IVid->agregarCategoria("Play Station 5", "Cheto como Leonel Messi", TipoCat::Plataforma);
            IVid->confirma_agregarCategoria();

            //carga videojuegos
            IUsr->iniciarSesion("ironhide@mail.com", "123");
            IVid->ingresarDatosVideojuego("KingdomRush", "Ta tremendo", 1, 2, 7, 14);
            IVid->seleccionarCategoria("PC", TipoCat::Plataforma);
            IVid->seleccionarCategoria("PS4", TipoCat::Plataforma);
            IVid->seleccionarCategoria("Estrategia", TipoCat::Genero);
            IVid->seleccionarCategoria("E", TipoCat::Otro);
            IVid->confirma_publicarVideojuego();

            IUsr->iniciarSesion("epic@mail.com", "123");
            IVid->ingresarDatosVideojuego("Fortnite", "El del baile", 3, 8, 30, 60);
            IVid->seleccionarCategoria("PC", TipoCat::Plataforma);
            IVid->seleccionarCategoria("PS4", TipoCat::Plataforma);
            IVid->seleccionarCategoria("Xbox One", TipoCat::Plataforma);
            IVid->seleccionarCategoria("Supervivencia", TipoCat::Genero);
            IVid->seleccionarCategoria("Teen", TipoCat::Otro);
            IVid->confirma_publicarVideojuego();

            IUsr->iniciarSesion("mojang@mail.com", "123");
            IVid->ingresarDatosVideojuego("Minecraft", "En este hicieron la FIng", 2, 5, 20, 40);
            IVid->seleccionarCategoria("PC", TipoCat::Plataforma);
            IVid->seleccionarCategoria("Supervivencia", TipoCat::Genero);
            IVid->seleccionarCategoria("Teen", TipoCat::Otro);
            IVid->confirma_publicarVideojuego();

            IUsr->iniciarSesion("ea@mail.com", "123");
            IVid->ingresarDatosVideojuego("FIFA 21", "Fubolito", 3, 8, 28, 50);
            IVid->seleccionarCategoria("PC", TipoCat::Plataforma);
            IVid->seleccionarCategoria("PS4", TipoCat::Plataforma);
            IVid->seleccionarCategoria("Xbox One", TipoCat::Plataforma);
            IVid->seleccionarCategoria("Deporte", TipoCat::Genero);
            IVid->seleccionarCategoria("E", TipoCat::Otro);
            IVid->confirma_publicarVideojuego();            

            cout << "Cargados datos de prueba.\n" << Constantes::Separador;         
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
