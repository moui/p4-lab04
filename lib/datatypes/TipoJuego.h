#ifndef DT_TIPOJUEGO
#define DT_TIPOJUEGO

#include <iostream>

enum class TipoJuego
    {

    Accion = 0,
    Aventura = 1,
    Deporte = 2,
    Otro = 3
    };


    inline std::istream& operator>> ( std::istream& in, TipoJuego& t )
    {
    int valor;

    if ( in  >> valor ) {
        switch ( valor ) {
        case 0: case 1 : case 2: case 3:
        t = TipoJuego(valor); break;
        default:
        throw std::out_of_range ( "Por favor, escriba uno de los tipos detallados.\n" );
        }
    }

    return in;
    }


    inline std::ostream& operator<<(std::ostream& out, const TipoJuego& t){
    switch (t) {
    case TipoJuego::Accion:
        out << "Accion";
        break;
    case TipoJuego::Aventura:
        out << "Aventura";
        break;
    case TipoJuego::Deporte:
        out << "Deporte";
        break;
    case TipoJuego::Otro:
        out << "Otro";
        break;
    }
    return out;
}

#endif
