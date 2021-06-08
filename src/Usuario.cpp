#include "../lib/Ususario.h"

Usuario(string mail, string contrasena) {
    this->mail = mail;
    this->contrasena = contrasena;
 }
 
virtual ~Usuario(){
}

string getMail(){
  return this->mail;
}

string getContrasena(){
  return this->contrasena;
}
  
virtual void setMail(string mail){
  this->mail = mail;
}

virtual void setContrasena(string contrasena){
  this->contrasena = contraena;
}
