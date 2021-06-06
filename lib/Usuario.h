#ifndef USUARIO
#define USUARIO

#include <string>

using namespace std;

class Usuario
{
  private:
    string email;
    string contrasena;

  public:
    Usuario(string email, string contrasena);
    virtual ~Usuario();
    virtual void funVirtualPura() = 0; // Usuario es clase abstracta
    
    // Getters
    string getMail();
    string getContrasena();
  
    // Setters
    void setMail(string email);
    void setContrasena(string contrasena);
};

#endif