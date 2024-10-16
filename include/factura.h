#pragma once
#include <iostream>
#include "fecha.h"

class Factura{
  public:
   Factura();
   Factura(Fecha fecha, char tipo,int nroFactura, int nroVenta, float monto);
   Fecha getFecha();
   void setFecha(Fecha f);
   int getNroFactura();
   void setNroFactura(int nroFactura);
   float getMontoTotal();
   void setMontoTotal(float monto);
   float getMontoTotal();


  private:
   int _nroFactura;
   char _tipoFactura;
   int _nroVenta;
   Fecha _fecha;
   float _montoTotal;
};