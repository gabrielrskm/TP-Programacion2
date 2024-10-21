#pragma once
#include <iostream>
#include "orden.h"


class OrdenProduccion:public Orden{
  public:
   OrdenProduccion();
   OrdenProduccion(int id, Fecha fecha, char estado);
   
   std::string getIdProducto();
   void setIdProducto(std::string id);


  private:
   char _idProducto[30];

};