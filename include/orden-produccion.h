#pragma once
#include <iostream>
#include "orden.h"


class OrdenProduccion:public Orden{
  public:
   OrdenProduccion();
   OrdenProduccion(int id, Fecha fecha, char estado);
   
   std::string getIdProducto();
   void setIdProducto(std::string id);
   int getCantidad();
   void setCantidad(int cantidad);


  private:
   char _idProducto[30];
   int cantidad;
};