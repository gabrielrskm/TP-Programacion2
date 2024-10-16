#pragma once
#include <iostream>
#include "persona.h"

class Proveedor : public Persona {
  public:
   Proveedor();
   Proveedor(char _condicionPago, float totalCompras);

   bool getCondicionPago();
   void setCondicionPago();
   float getTotalCompras();
   void setTotalCompras();

  private:
   char _condicionPago;
   float _totalCompras;
};