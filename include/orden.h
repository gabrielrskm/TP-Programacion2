#pragma once
#include <iostream>
#include "fecha.h"


class Orden{
  public:
   Orden();
   Orden(int id, Fecha fecha,char estado);
   
   
   int getId();
   void setId(int id);
   std::string getEstado();
   void setEstado(char estado);
   Fecha getFecha();
   void setFecha(Fecha fecha);


  protected:
   int _id;
   Fecha _fecha;
   char _estado;
};