#pragma once
#include <iostream>
#include "persona.h"

class Proveedor : public Persona {
  public:
   Proveedor();
   Proveedor(char condicionPago, float totalCompras, int id, int telefono, char tipoFJ, std::string nombre,
             std::string direccion, std::string email);

   char getCondicionPago();
   void setCondicionPago(char condicionPago);
   float getTotalCompras();
   void setTotalCompras(float totalCompras);

  private:
   char _condicionPago;
   float _totalCompras;
};