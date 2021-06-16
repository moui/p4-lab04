#ifndef DT_CATEGORIA
#define DT_CATEGORIA

#include <string>
#include "TipoCat.h"

using namespace std;

class DtCategoria
{
    private:
        string nombre;
        string descripcion;
        TipoCat tipo;

    public:
        DtCategoria(string nombre, string descripcion, TipoCat tipo);
        ~DtCategoria();

        //getters
        string getNombre() const;
        string getDescripcion() const;
        TipoCat getTipo() const;

        //setters
        void setNombre(string nombre);
        void setDescripcion(string descripcion);
        void setTipo(TipoCat tipo);

};

inline bool operator==(const DtCategoria& lhs, const DtCategoria& rhs){ return( lhs.getNombre() == rhs.getNombre() ); }
inline bool operator!=(const DtCategoria& lhs, const DtCategoria& rhs){ return !operator==(lhs,rhs);}
inline bool operator< (const DtCategoria& lhs, const DtCategoria& rhs){ return ( lhs.getNombre() < rhs.getNombre() ); }
inline bool operator> (const DtCategoria& lhs, const DtCategoria& rhs){ return  operator< (rhs,lhs);}
inline bool operator<=(const DtCategoria& lhs, const DtCategoria& rhs){ return !operator> (lhs,rhs);}
inline bool operator>=(const DtCategoria& lhs, const DtCategoria& rhs){ return !operator< (lhs,rhs);}

#endif