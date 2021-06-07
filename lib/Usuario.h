#ifndef USUARIO
#define USUARIO

#include <string>
#include <set>

using namespace std;

class Usuario
{
  private:
    string mail;
    string contrasena;

  public:
    Usuario(string, string);
    virtual ~Usuario();

    // Getters
    string getMail();
    string getContrasena();
  
    // Setters
    void setMail(string mail);
    void setContrasena(string contrasena);
};

#endif
