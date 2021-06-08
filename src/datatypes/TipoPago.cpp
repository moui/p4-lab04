#include "lib/datatypes/TipoPago.h"
#include <iostream>

inline std::istream& operator>> ( std::istream& in, TipoPago& t ){
    int valor;

    if ( in  >> valor ) {
        switch ( valor ) {
            case 0: case 1 : case 2:
                t = TipoPago(valor); break;
            default:
                throw std::out_of_range ( "Por favor, escriba uno de los tipos detallados.\n" );
        }
    }
    return in;
}


inline std::ostream& operator<<(std::ostream& out, const TipoPago& t){
    switch (t) {
        case TipoPago::mensual:
            out << "Mensual";
            break;
        case TipoPago::tarjeta:
            out << "Tarjeta";
            break;
        case TipoPago::otro:
            out << "Otro";
            break;
    }
    return out;
}
