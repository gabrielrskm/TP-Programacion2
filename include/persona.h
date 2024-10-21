#pragma once
#include <iostream>
#include "fecha.h"

class Persona{
  public:
   Persona();
   Persona(int id, int telefono,
               char tipoFJ, std::string nombre, std::string direccion, std::string email);
   Fecha getFecha();
   void setFecha(Fecha f);
   char getTipoFJ();
   void setTipoFJ(char tipoFJ);
   int getId();
   void setId(int id);
   std::string getNombre();
   void setNombre(std::string nombre);
   std::string getDireccion();
   void setDireccion(std::string direccion);
   std::string getEmail();
   void setEmail(std::string email);


  protected:
   int _id;
   int _telefono;
   char tipoFJ; //fisica F , juridica J
   char _nombre[30];
   char _direccion[50];
   char _email[60];
   Fecha _fechaIngreso;
};