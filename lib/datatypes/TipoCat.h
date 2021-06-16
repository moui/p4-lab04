#ifndef DT_TIPOCAT
#define DT_TIPOCAT

#include <iostream>

enum class TipoCat
    {
    Plataforma = 0,
    Genero = 1,
    Otro = 2,
    };

inline std::istream& operator>> ( std::istream& in, TipoCat& t ){
    int valor;

    if ( in  >> valor ) {
        switch ( valor ) {
            case 0: case 1 : case 2:
                t = TipoCat(valor); break;
            default:
                throw std::out_of_range ( "Por favor, escriba uno de los tipos detallados.\n" );
        }
    }
    return in;
}


inline std::ostream& operator<<(std::ostream& out, const TipoCat& t){
    switch (t) {
        case TipoCat::Plataforma:
            out << "Plataforma";
            break;
        case TipoCat::Genero:
            out << "Genero";
            break;
        case TipoCat::Otro:
            out << "Otro";
            break;
    }
    return out;
} 





#endif
