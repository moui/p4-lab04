#include "../../lib/datatypes/TipoPeriodo.h"
#include <iostream>

inline std::istream& operator>> ( std::istream& in, TipoPeriodo& t ){
    int valor;

    if ( in  >> valor ) {
        switch ( valor ) {
            case 0: case 1 : case 2: case 3:
                t = TipoPeriodo(valor); break;
            default:
                throw std::out_of_range ( "Por favor, escriba uno de los tipos detallados.\n" );
        }
    }
    return in;
}


inline std::ostream& operator<<(std::ostream& out, const TipoPeriodo& t){
    switch (t) {
        case TipoPeriodo::Mensual:
            out << "Mensual";
            break;
        case TipoPeriodo::Trimestral:
            out << "Trimestral";
            break;
        case TipoPeriodo::Anual:
            out << "Anual";
            break;
        case TipoPeriodo::Vitalicia:
            out << "Vitalicia";
            break;
    }
    return out;
}
