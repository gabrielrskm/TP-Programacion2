#pragma once
#include <iostream>
#include "orden.h"


class OrdenCompra: public Orden{
  public:
   OrdenCompra();
   OrdenCompra(int id, Fecha fecha, char estado);


   int getIdProveedor();
   void setIdProveedor(int id);


  private:
   int _idProveedor;

};