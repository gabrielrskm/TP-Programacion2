#pragma once
#include <iostream>
#include "persona.h"

class Usuario : public Persona {
  public:
   Usuario();
   Usuario(char tipo,std::string pass,
            int edad, Fecha fecha);

   std::string getPassword();
   void setPassword(std::string password);
   char getTipo();
   void setTipo(char tipo);
   Fecha getFechaNacimiento();
   void setFechaNacimiento();


  private:
   char _tipo;
   char _password[20];
   int _edad;
   Fecha _fechaNacimiento;
};