#pragma once
#include <iostream>
#include "fecha.h"
#include "productos.h"

class Devoluciones{
  public:
   int getCantidad();
   void setCantidad(int q);
   Fecha getFecha();
   void setFecha(Fecha f);

  private:
   int _cantidad;
   char _idRecurso[30];
   Fecha fecha;
   char motivo[50];
   char tipo;  //'c' cliente 'p' proveedor
};