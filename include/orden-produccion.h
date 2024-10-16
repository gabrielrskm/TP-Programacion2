#pragma once
#include <iostream>
#include "orden.h"


class OrdenProduccion:Orden{
  public:
   OrdenProduccion();
   OrdenProduccion(std::string idProducto);
   
   
   int getIdProducto();
   void setIdProducto(std::string id);


  private:
   char _idProducto[30];

};