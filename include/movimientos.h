#pragma once
#include <iostream>
#include "fecha.h"

class Movimientos{
  public:
   Movimientos();
   Movimientos(Fecha fecha, char motivo,
               char tipo, std::string id);
   Fecha getFecha();
   void setFecha(Fecha f);
   std::string getMotivo();
   void setMotivo(std::string motivo);
   char getTipoMovimiento();
   void setTipoMovimiento(char tipo);
   bool getDestino();
   void setDestino(bool destino);
   int getId();
   void setId(std::string id);
   int getNroMovimiento();


  private:
   int _nroMovimiento;
   Fecha _fecha;
   char _motivo[50];
   char _tipoMovimiento;  //'r' remito, 's' scrap, 'd' devolucion
   bool destino; // suma stock , resta stock,
   char _id[30]; // codigo unico 
};