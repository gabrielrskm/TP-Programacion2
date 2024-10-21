#pragma once
#include <iostream>
#include "fecha.h"

class Movimientos{
  public:
   Movimientos();
   Movimientos(Fecha fecha, std::string motivo,
               char tipo, std::string id);
   Fecha getFecha();
   void setFecha(Fecha f);
   std::string getMotivo();
   void setMotivo(std::string motivo);
   char getTipoMovimiento();
   void setTipoMovimiento(char tipo);
   bool getDestino();
   void setDestino(bool destino);
   std::string getId();
   void setId(std::string id);
   int getNroMovimiento();
   void setNroMovimiento(int nroMovimiento);


  private:
   int _nroMovimiento;
   Fecha _fecha;
   char _motivo[50];
   char _tipoMovimiento;  //'r' remito, 's' scrap, 'd' devolucion
   bool _destino; // suma stock , resta stock,
   char _id[30]; // codigo unico 
};