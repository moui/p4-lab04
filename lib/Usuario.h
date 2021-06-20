#ifndef USUARIO
#define USUARIO

#include <string>
#include <set>

using namespace std;

class Usuario
{
  private:
    string email;
    string contrasena;

  public:
    Usuario(string email, string contrasena);
    virtual ~Usuario();
    virtual void abstracta() = 0; // Usuario es clase abstracta
    
    // Getters
    string getMail();
    string getContrasena();
  
    // Setters

    void setMail(string email);
    void setContrasena(string contrasena);

};

#endif
