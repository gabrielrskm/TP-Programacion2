#pragma once
#include <iostream>
#include "fecha.h"


class Orden{
  public:
   Orden();
   Orden(int id, Fecha fecha,char estado);
   
   
   int getId();
   void setId();
   char getEstado();
   void setEstado(char estado);
   Fecha getFecha();
   void setFecha(Fecha fecha);


  protected:
   int _id;
   Fecha _fecha;
   char _estado;
};