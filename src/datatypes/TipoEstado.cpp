#include "../../lib/datatypes/TipoEstado.h"
#include <iostream>

inline std::istream& operator>> ( std::istream& in, TipoEstado& t ){
    int valor;

    if ( in  >> valor ) {
        switch ( valor ) {
            case 0: case 1 : case 2:
                t = TipoEstado(valor); break;
            default:
                throw std::out_of_range ( "Por favor, escriba uno de los tipos detallados.\n" );
        }
    }
    return in;
}


inline std::ostream& operator<<(std::ostream& out, const TipoEstado& t){
    switch (t) {
        case TipoEstado::activa:
            out << "Activa";
            break;
        case TipoEstado::cancelada:
            out << "Cancelada";
            break;
        case TipoEstado::expirada:
            out << "Expirada";
            break;
    }
    return out;
}
