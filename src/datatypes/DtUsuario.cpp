#include "../../lib/datatypes/DtUsuario.h"

DtUsuario::DtUsuario(string email)
{
    this->email = email;
}

DtUsuario::~DtUsuario()
{
    
}

string DtUsuario::getEmail()
{
    return email;
}