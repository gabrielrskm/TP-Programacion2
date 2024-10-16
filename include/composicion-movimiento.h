#pragma once
#include <iostream>
#include "fecha.h"
#include "productos.h"

class ComposicionMovimientos{
  public:
   ComposicionMovimientos();
   ComposicionMovimientos(int cantidad, std::string idRecurso, int _nroMovimiento);
   
   int getCantidad();
   void setCantidad(int q);
   int getNroMovimiento();
   void setNroMovimiento();
   std::string getIdRecurso();
   void setIdRecurso(std::string recurso);


  private:
   int _nroMovimiento;
   int _cantidad;
   char _idRecurso[30];
};