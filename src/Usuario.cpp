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
string getMail()
{
    return this->email;
}

string getContrasena()
{
    return this->contrasena;
}

// Setters
void setMail(string mail)
{
    this->mail = mail;
}

void setContrasena(string contrasena)
{
    this->contrasena = contrasena;
}