#pragma once
#include <iostream>
#include "persona.h"

 
class Usuario : public Persona {
  public:
   Usuario();
   Usuario(char tipo, std::string pass, std::string nombreUsuario, Fecha fecha, int id, int telefono, char tipoFJ, std::string nombre,
           std::string direccion, std::string email);

   std::string getPassword();
   void setPassword(std::string password);
   char getTipo();
   void setTipo(char tipo);

   std::string getNombreUsuario();
   void setNombreUsuario(std::string nombreUsuario);
   static bool validarUsuarioYPass(std::string nombreUsuario, std::string pass);

  private:
   char _tipo; // a = administrador, v = vendedor, u = usuario, c = comprador
   char _password[20];
   char _nombreUsuario[20];
};