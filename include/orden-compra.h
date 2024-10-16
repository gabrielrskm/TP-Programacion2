#pragma once
#include <iostream>
#include "orden.h"


class OrdenCompra:Orden{
  public:
   OrdenCompra();
   OrdenCompra(int idProveedor);
   
   
   int getIdProveedor();
   void setIdProveedor();


  private:
   int _idProveedor;

};