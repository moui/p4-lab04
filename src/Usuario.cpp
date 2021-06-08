#include "../lib/Usuario.h"

// Constructor y destructor
Usuario::Usuario(string email, string contrasena)
{
    this->email = email;
    this->contrasena = contrasena;
    return;
}

Usuario::~Usuario()
{
    return;
}

// Getters
string Usuario::getMail()
{
    return this->email;
}

string Usuario::getContrasena()
{
    return this->contrasena;
}

// Setters
void Usuario::setMail(string mail)
{
    this->email = mail;
}

void Usuario::setContrasena(string contrasena)
{
    this->contrasena = contrasena;
}
