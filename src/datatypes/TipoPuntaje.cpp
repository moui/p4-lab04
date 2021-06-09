#include "../../lib/datatypes/TipoPuntaje.h"
#include <iostream>

/*inline std::istream& operator>> ( std::istream& in, TipoPeriodo& t ){
    int valor;

    if ( in  >> valor ) {
        switch ( valor ) {
            case 1: case 2 : case 3: case 4: case 5:
                t = TipoPuntaje(valor); break;
            default:
                throw std::out_of_range ( "Por favor, escriba uno de los tipos detallados.\n" );
        }
    }
    return in; 
} */


/* inline std::ostream& operator<<(std::ostream& out, const TipoPuntaje& t){
    switch (t) {
        case TipoPuntaje::uno:
            out << "Uno";
            break;
        case TipoPuntaje::dos:
            out << "Dos";
            break;
        case TipoPuntaje::tres:
            out << "Tres";
            break;
        case TipoPuntaje::cuatro:
            out << "Cuatro";
            break;
        case TipoPuntaje::cinco:
            out << "Cinco";
            break;
    }
    return out;
} */
