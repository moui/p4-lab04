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

// Retorna true solo si 'id' ocurre en set
static bool pertenece(set<DtPartidaIndividual*> set, int id);

static bool pertenece(set<string> set, string nick);

int main()
{
    FechaSistema *fechaSistema = FechaSistema::getInstancia();
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
        cin.clear();
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
            cin.ignore();
            getline(cin, contrasena);
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
                cin.ignore();
                getline(cin, empresa);
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
                    cin.ignore();
                    getline(cin, nickname);
                    cout << "Ingrese descripcion: ";
                    cin.ignore();
                    getline(cin, descripcion);
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
            cin.ignore();
            getline(cin, contrasena);
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
                            //ALTA CATEGORIA
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
                            cin.ignore();
                            getline(cin, nombrecat);
                            cout << "Ingrese la descripcion de la nueva categoria: ";
                            cin.ignore();
                            getline(cin, descricat);
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
                            string vjelim;
                            char conf;
                            set<DtVideojuego*> setvjdes = IUsr->listarVideoJuegosDesarrollador();
                            set<DtVideojuego*>::iterator itvid;
                            cout << "VIDEOJUESO PUBLICADOS: " << endl << endl;
                            if (setvjdes.empty())
                                cout << "No existen videojuegos publicados en el catalogo." << endl << endl;
                            for (itvid = setvjdes.begin(); itvid != setvjdes.end(); ++itvid){
                                cout << *(*itvid) << endl;
                            }
                            cout << "Ingrese nombre de videojuego a eliminar: ";
                            cin.ignore();
                            getline(cin, vjelim);
                            IVid->videojuegoAEliminar(vjelim);
                            cout << "Desea (E)liminar o (C)ancelar? ";
                            cin >> conf;
                            switch (conf)
                            {
                            case 'E':
                                try 
                                {
                                    IVid->confirmar_eliminarVideoJuego();
                                    cout << "Videojuego eliminado." << endl << Constantes::Separador;
                                }
                                catch (const std::invalid_argument &err)
                                {
                                    cerr << "Error: " << err.what() << '\n';
                                }


                                break;
                            case 'C':
                                IVid->cancelar_eliminarVideoJuego();
                                cout << "Eliminar cancelado." << endl << Constantes::Separador;
                                break;
                            default:
                                cout << "Ingreso una opcion invalida. Intente nuevamente. \n";
                                break;
                            }
                            if (!setvjdes.empty()){
                                for (itvid = setvjdes.begin(); itvid != setvjdes.end(); ++itvid)
                                {
                                    if (*itvid != NULL)
                                        delete *itvid;
                                }
                            }
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
                                cin.ignore();
                                getline(cin, nomVJ);
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
                            string nombre;
                            map<string, string> setvjsistema = IVid->listarNombresVideojuego();
                            map<string, string>::iterator itvj;
                            cout << "CATALOGO VIDEOJUEGOS PLATAFORMA: " << endl << endl;
                            if (setvjsistema.empty())
                                cout << "No existen videojuegos en el catalogo." << endl << endl;
                            for (itvj = setvjsistema.begin(); itvj != setvjsistema.end(); ++itvj) {
                                cout << itvj->first << endl;
                            }
                            cout << "Ingrese el nombre de un videojuego: ";
                            cin.ignore();
                            getline(cin, nombre);
                            try 
                            {
                                DtVideojuego* infoVideojuego = IVid->verInfoVideojuego(nombre);
                                cout << "INFORMACION VIDEOJUEGO" << endl << endl
                                     << *(infoVideojuego) << endl;
                                cout << "Total de horas jugadas: " << (*infoVideojuego).getTotalHorasJugadas() << endl << Constantes::Separador << endl;
                                delete infoVideojuego;
                            }
                            catch (const std::invalid_argument &err)
                            {
                                cerr << "Error: " << err.what() << '\n';
                                cout << Constantes::Separador;
                            }
                            break;
                        }
                        case 7:
                        {
                            // MODIFICAR FECHA DEL SISTEMA
                            cout << Constantes::PresentacionFechaActual << *(fechaSistema->getFecha()) << Constantes::Separador;
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
                        cin.clear();
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
                                 cout<< *(*itsa);
                                 delete *itsa;
                             };
                             cout << Constantes::Separador;

                             cout << "SUSCRIPCIONES NO ACTIVAS: \n";
                             for (set<DtVideojuegoSuscripcion*>::iterator itsna=sna.begin(); itsna!=sna.end(); itsna++){
                                 cout<< *(*itsna);
                                 delete *itsna;
                             };
                             cout << Constantes::Separador;
                             string nomVJ;                            
                             cout << "Seleccione un Videojuego para suscribirse: \n";
                             cin.ignore();
                             getline(cin, nomVJ);
                             TipoEstado estado=IUsr->JuegoSuscribirse(nomVJ);                           

                             switch(estado)
                             {
                             case (TipoEstado::activa):
                             {
                                 char cancela;
                                 cout << "Desea cancelar su sucripcion temporal a: " << nomVJ << " Y/n? \n";
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
                              break;    
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
                             default:
                                break;
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
                            string nombre;
                            TipoPuntaje puntos;
                            map<string, string> setvjsistema = IVid->listarNombresVideojuego();
                            map<string, string>::iterator itvj;
                            cout << "CATALOGO VIDEOJUEGOS: " << endl << endl;
                            if (setvjsistema.empty())
                                cout << "No existen videojuegos en el catalogo." << endl << endl;
                            cout << "NOMBRE   |   DESCRIPCION" << endl;                            
                            for (itvj = setvjsistema.begin(); itvj != setvjsistema.end(); ++itvj) {
                                cout << itvj->first << "  |  " << itvj->second << endl;
                            }
                            cout << "Ingrese el nombre de un videojuego: ";
                            cin.ignore();
                            getline(cin, nombre);
                            cout << "Ingrese un puntaje del 1 al 5: ";
                            cin >> puntos;
                            try {
                                IVid->asignarPuntajeVideojuego(nombre, puntos);
                                cout << "Puntaje asignado.\n" << Constantes::Separador;       
                            }
                            catch (const std::invalid_argument &err)
                            {
                                cerr << "Error: " << err.what() << '\n';
                            }
                            break;
                        }
                        case 3:
                        {
                            // INICIAR PARTIDA
                            cout << Constantes::PresentacionIniciarPartida;
                              // Listar videojuegos con suscripciones activas.
                            cout << "SUSCRIPCIONES ACTIVAS" << endl << endl;
                            set<DtVideojuegoSuscripcion*> videojuegos = IUsr->listarVideojuegoSuscripcionesActivas();
                            for (auto it = videojuegos.begin(); it != videojuegos.end(); ++it)
                            {
                                DtVideojuegoSuscripcion* infoVideojuego = *it;
                                cout << "Nombre videojuego: " << infoVideojuego->getNombreVideojuego() << endl << endl;
                                delete infoVideojuego;
                            }
                            // Declaraciones
                            string tipoPartida, continua, nombreVideojuego, confirma, transmite, unido;
                            set<string> unidos;
                            int idContinuacion;
                            // Pedir nombre videojuego
                            cout << "Seleccione videojuego indicando su nombre" << endl;
                            cin.ignore();
                            getline(cin, nombreVideojuego);
                            // Checkear que tenga suscripcion activa para el videojuego ingresado
                            try
                            {
                                TipoEstado estadoSuscripcion = IUsr->getEstadoSuscripcion(nombreVideojuego);
                                if ( estadoSuscripcion != TipoEstado::activa )
                                    throw invalid_argument("Suscripcion para " + nombreVideojuego + " esta inactiva.");
                            }
                            catch (exception &e)
                            {
                                cout << "Error: " << e.what() << endl << endl;
                                cout << Constantes::Separador;
                                break;
                            }

                            cout << "Desea iniciar partida (I)ndividual o (M)ultijugador? " << endl;
                            cin >> tipoPartida;

                            DtPartida* datosPartida;

                            if (tipoPartida == "I")
                            {
                                // INICIAR PARTIDA INDIVIDUAL
                                // Continuar partida anterior?
                                cout << "Continuar partida anterior? (Y/N): " << endl;
                                cin >> continua;
                                if (continua == "Y")
                                {
                                    // Lista partidas individuales ya finalizadas.
                                    // por orden cronologico. Mostrar ID, Fecha y Duracion
                                    auto partidasInd = IPar->partidasIndFinalizadas(nombreVideojuego);
                                    if (partidasInd.empty())
                                    {
                                        cout << "No existen partidas a continuar." << endl << Constantes::Separador;
                                        break;
                                    }
                                    cout << endl << "PARTIDAS INDIVIDUALES FINALIZADAS" << endl;
                                    for (auto it = partidasInd.begin(); it != partidasInd.end(); ++it)
                                    {
                                        cout << *(*it);
                                        //DtPartidaIndividual* dataPartida = *it;
                                        //cout << *dataPartida;
                                    }
                                    // Ingresar ID de partida a continuar.
                                    idContinuacion = -1;
                                    while (!pertenece(partidasInd, idContinuacion))
                                    {
                                        cout << "Ingrese ID de partida a continuar :";
                                        cin >> idContinuacion;
                                        if (cin.fail())
                                        {
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                            cin.clear();
                                            idContinuacion = -1;
                                        }   
                                    }
                                    // Liberar memoria datatypes
                                    for (auto it = partidasInd.begin(); it != partidasInd.end(); ++it)
                                        delete *it;

                                    DtFechaHora* fechaInicio = new DtFechaHora(FechaSistema::getInstancia()->getFecha());
                                    datosPartida = new DtPartidaIndividual(0, 0, fechaInicio, NULL,  nombreVideojuego, new int(idContinuacion));
                                }
                                else if (continua == "N")
                                {
                                    DtFechaHora* fechaInicio = new DtFechaHora(FechaSistema::getInstancia()->getFecha());
                                    datosPartida = new DtPartidaIndividual(0, 0, fechaInicio, NULL,  nombreVideojuego, NULL);
                                }
                                else 
                                {
                                    cout << "Parametro invalido." << endl << Constantes::Separador;
                                    break;
                                }
                            }
                            else if (tipoPartida == "M")
                            {
                                // INICIAR PARTIDA MULTIJUGADOR
                                cout << "Desea transmitir la partida en vivo? (Y/N): " << endl;
                                cin >> transmite;
                                cout << "Jugadores con suscripciones activas: " << endl;
                                bool enVivo = transmite == "Y" ? true : false; 
                                set<string> jugsus = IUsr->listarJugadoresSuscripcionActivaVJ(nombreVideojuego);
                                for (auto it = jugsus.begin(); it != jugsus.end(); ++it){
                                    cout << *it << endl;
                                }
                                unido = "";
                                while (unido != "cont")
                                {
                                    cout << "Ingrese nickname jugador o 'cont' para continuar " << endl;
                                    cin >> unido;
                                    if (pertenece(jugsus, unido))
                                        unidos.insert(unido);
                                }
                                if (unidos.empty())
                                {
                                    cout << "Parametro invalido." << endl << Constantes::Separador;
                                    break;
                                }
                                DtFechaHora* fechaInicio = new DtFechaHora(FechaSistema::getInstancia()->getFecha());
                                datosPartida = new DtPartidaMultijugador(0, 0, fechaInicio, NULL, nombreVideojuego, enVivo, unidos, 0);
                            }
                            else
                            {
                                // Invalid read.
                                cout << "Parametro invalido." << endl << Constantes::Separador;
                                break;
                            }
                            // CONFIRMAR ALTA
                            cout << "Confirma alta partida? (Y/N) " << endl;
                            cin >> confirma;
                            if (confirma == "Y")
                            {
                                IPar->altaPartida(datosPartida);
                                cout << "Alta partida exitosa" << endl;
                            }
                            // Limpiar memoria
                            delete datosPartida;
                            cout << Constantes::Separador;
                            break;
                        }
                        case 4: //ABANDONAR PARTIDA MULTIJUGADOR
                        {
                            int partidaMJ;
                            cout << Constantes::PresentacionAbandonarPartidaMultijugador;
                            try 
                            {
                            set<DtPartidaMultijugador*> datosPartidaMulti = IUsr->listarPartidasMultijugadorUnidas();
                            cout << "Por favor, ingrese el identificador de la partida que desea abandonar:  \n";
                            cin >> partidaMJ;

                            IUsr->ConfirmarAbandonarPartida(partidaMJ);

                            }
                            catch (const std::invalid_argument &err)
                            {
                                cerr << "Error: " << err.what() << '\n';
                                cout << Constantes::Separador;
                            }
                            cout << Constantes::PresentacionAbandonarPartidaMultijugador_Fin;
                            break;
                        }
                        case 5:
                        {
                            // FINALIZAR PARTIDA
                            int partidaI;
                            cout << Constantes::PresentacionFinalizarPartida;
                            set<DtPartida*> partidasIniciadas= IPar->listaPartidasIniciadasSinFinalizar();
                            set<DtPartida*>::iterator itvid;
                            cout << " Partidas iniciadas sin finalizar: " << endl << endl;
                            if (partidasIniciadas.empty())
                                cout << "No existen partidas iniciadas." << endl << endl;
                            else {
                                for (itvid = partidasIniciadas.begin(); itvid != partidasIniciadas.end(); ++itvid){
                                    cout << *(*itvid) << endl;
                                    delete *itvid;
                                }
                                cout << "Por favor, ingrese el identificador de la partida que desea finalizar:  \n";
                                cin >> partidaI;
                                try 
                                {
                                    IPar->finalizarPartida(new DtFechaHora(fechaSistema->getFecha()), partidaI);
                                }
                                catch (const std::invalid_argument &err)
                                {
                                    cerr << "Error: " << err.what() << '\n';
                                    cout << Constantes::Separador;
                                }
                            }
                            break;
                        }
                        case 6:
                        {
                            // VER INFORMACION DE VIDEOJUEGO
                            string nombre;
                            map<string, string> setvjsistema = IVid->listarNombresVideojuego();
                            map<string, string>::iterator itvj;
                            cout << "CATALOGO VIDEOJUEGOS: " << endl << endl;
                            if (setvjsistema.empty())
                                cout << "No existen videojuegos en el catalogo." << endl << endl;
                            for (itvj = setvjsistema.begin(); itvj != setvjsistema.end(); ++itvj) {
                                cout << itvj->first << endl;
                            }
                            cout << "Ingrese el nombre de un videojuego: ";
                            cin.ignore();
                            getline(cin, nombre);
                            try 
                            {
                                DtVideojuego* infoVideojuego = IVid->verInfoVideojuego(nombre);
                                cout << "INFORMACION VIDEOJUEGO" << endl << endl
                                     << *(infoVideojuego) << Constantes::Separador;
                                delete infoVideojuego;
                            }
                            catch (const std::invalid_argument &err)
                            {
                                cerr << "Error: " << err.what() << '\n';
                                cout << Constantes::Separador;
                            }
                            break;
                        }
                        case 7:
                        {
                            // MODIFICAR FECHA DEL SISTEMA
                            cout << Constantes::PresentacionFechaActual << *(fechaSistema->getFecha()) << Constantes::Separador;
                            cout << Constantes::PresentacionModificarFecha_Inicio;
                            cout << "Fecha actual: " << fechaSistema->getFecha() << endl;
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
        {   // CARGAR DATOS DE PRUEBA

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
            DtUsuario* usr; 

            usr = IUsr->iniciarSesion("ironhide@mail.com", "123");
            IVid->ingresarDatosVideojuego("KingdomRush", "Ta tremendo", 1, 2, 7, 14);
            IVid->seleccionarCategoria("PC", TipoCat::Plataforma);
            IVid->seleccionarCategoria("PS4", TipoCat::Plataforma);
            IVid->seleccionarCategoria("Estrategia", TipoCat::Genero);
            IVid->seleccionarCategoria("E", TipoCat::Otro);
            IVid->confirma_publicarVideojuego();
            delete usr;

            usr = IUsr->iniciarSesion("epic@mail.com", "123");
            IVid->ingresarDatosVideojuego("Fortnite", "El del baile", 3, 8, 30, 60);
            IVid->seleccionarCategoria("PC", TipoCat::Plataforma);
            IVid->seleccionarCategoria("PS4", TipoCat::Plataforma);
            IVid->seleccionarCategoria("Xbox One", TipoCat::Plataforma);
            IVid->seleccionarCategoria("Supervivencia", TipoCat::Genero);
            IVid->seleccionarCategoria("Teen", TipoCat::Otro);
            IVid->confirma_publicarVideojuego();
            delete usr;

            usr = IUsr->iniciarSesion("mojang@mail.com", "123");
            IVid->ingresarDatosVideojuego("Minecraft", "En este hicieron la FIng", 2, 5, 20, 40);
            IVid->seleccionarCategoria("PC", TipoCat::Plataforma);
            IVid->seleccionarCategoria("Supervivencia", TipoCat::Genero);
            IVid->seleccionarCategoria("Teen", TipoCat::Otro);
            IVid->confirma_publicarVideojuego();
            delete usr;

            usr = IUsr->iniciarSesion("ea@mail.com", "123");
            IVid->ingresarDatosVideojuego("FIFA 21", "Fubolito", 3, 8, 28, 50);
            IVid->seleccionarCategoria("PC", TipoCat::Plataforma);
            IVid->seleccionarCategoria("PS4", TipoCat::Plataforma);
            IVid->seleccionarCategoria("Xbox One", TipoCat::Plataforma);
            IVid->seleccionarCategoria("Deporte", TipoCat::Genero);
            IVid->seleccionarCategoria("E", TipoCat::Otro);
            IVid->confirma_publicarVideojuego();
            delete usr;

            //carga suscripciones 
            
            DtFechaHora* d = new DtFechaHora(01, 06, 2021, 9, 0);
            fechaSistema->setFecha(d);
            usr = IUsr->iniciarSesion("gamer@mail.com", "123");
            IUsr->SuscribirseVideojuego(1, 3, "KingdomRush");
            IUsr->AltaSuscripcion();
            IUsr->CancelarOperacion();
            delete usr;

            d = new DtFechaHora(02, 06, 2021, 11, 0);
            fechaSistema->setFecha(d);
            usr = IUsr->iniciarSesion("gamer@mail.com", "123");
            IUsr->SuscribirseVideojuego(2, 3, "Fortnite");
            IUsr->AltaSuscripcion();
            IUsr->CancelarOperacion();
            delete usr;

            d = new DtFechaHora(04, 06, 2021, 9, 0);
            fechaSistema->setFecha(d);
            usr = IUsr->iniciarSesion("ari@mail.com", "123");
            IUsr->SuscribirseVideojuego(1, 1, "Fortnite");
            IUsr->AltaSuscripcion();
            IUsr->CancelarOperacion();
            delete usr;

            d = new DtFechaHora(11, 06, 2021, 9, 0);
            fechaSistema->setFecha(d);
            usr = IUsr->iniciarSesion("ari@mail.com", "123");
            IUsr->SuscribirseVideojuego(2, 12, "Minecraft");
            IUsr->AltaSuscripcion();
            IUsr->CancelarOperacion();
            delete usr;

            d = new DtFechaHora(03, 06, 2021, 7, 0);
            fechaSistema->setFecha(d);
            usr = IUsr->iniciarSesion("ibai@mail.com", "123");
            IUsr->SuscribirseVideojuego(2, 1, "Fortnite");
            IUsr->AltaSuscripcion();
            IUsr->CancelarOperacion();
            delete usr;

            d = new DtFechaHora(21, 12, 2020, 9, 0);
            fechaSistema->setFecha(d);
            usr = IUsr->iniciarSesion("ibai@mail.com", "123");
            IUsr->SuscribirseVideojuego(2, 0, "Minecraft");
            IUsr->AltaSuscripcion();
            IUsr->CancelarOperacion();
            delete usr;

            //cargar puntajes
            usr = IUsr->iniciarSesion("gamer@mail.com", "123");
            IVid->asignarPuntajeVideojuego("KingdomRush", TipoPuntaje::cuatro);
            IVid->asignarPuntajeVideojuego("Fortnite", TipoPuntaje::cinco);
            delete usr;

            usr = IUsr->iniciarSesion("ari@mail.com", "123");
            IVid->asignarPuntajeVideojuego("Minecraft", TipoPuntaje::tres);
            IVid->asignarPuntajeVideojuego("Fortnite", TipoPuntaje::cinco);
            delete usr;
            
            usr = IUsr->iniciarSesion("gamer@mail.com", "123");
            DtPartidaIndividual* datosPartida = new DtPartidaIndividual(0, 0, new DtFechaHora(02, 06, 2021, 9, 0), NULL,  "KingdomRush", NULL);
            IPar->altaPartida(datosPartida);
            IPar->finalizarPartida(new DtFechaHora(02, 06, 2021, 10, 0), 1);
            delete usr;
            delete datosPartida;

            usr = IUsr->iniciarSesion("gamer@mail.com", "123");
            datosPartida = new DtPartidaIndividual(0, 0, new DtFechaHora(03, 06, 2021, 15, 0), NULL,  "KingdomRush", new int(1));
            IPar->altaPartida(datosPartida);
            IPar->finalizarPartida(new DtFechaHora(03, 06, 2021, 16, 0), 3);
            delete usr;
            delete datosPartida;

            usr = IUsr->iniciarSesion("ari@mail.com", "123");
            datosPartida = new DtPartidaIndividual(0, 0, new DtFechaHora(12, 06, 2021, 20, 0), NULL,  "Minecraft", NULL);
            IPar->altaPartida(datosPartida);
            delete usr;
            delete datosPartida;

            d = new DtFechaHora(21, 06, 2021, 18, 0);
            fechaSistema->setFecha(d);

            cout << "Cargados datos de prueba.\n";
            cout << Constantes::PresentacionFechaActual << *fechaSistema->getFecha() << Constantes::Separador;         
            break;
        }
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

static bool pertenece(set<DtPartidaIndividual*> set, int id)
{
    if (id == -1)
        return false;
    for (auto it = set.begin(); it != set.end(); ++it)
    {
        DtPartidaIndividual* partida = *it;
        if (partida->getId() == id)
        {
            return true;  
        }
    }
    cout << "ID invalido" << endl;
    return false;
}

static bool pertenece(set<string> set, string nick)
{
    if (nick == "cont")
        return false;
    for (auto it = set.begin(); it != set.end(); ++it)
    {
        string actual = *it;
        if (actual == nick)
        {
            return true;  
        }
    }
    cout << "Nickname invalido" << endl;
    return false;
}
