#pragma once
#include <iostream>

class ComposicionOrden{
  public:
   ComposicionOrden();
   ComposicionOrden(int cantidad, std::string idRecurso, int _nroOrden);
   
   int getCantidad();
   void setCantidad(int q);
   int getNroOrden();
   void setNroOrden();
   std::string getIdRecurso();
   void setIdRecurso(std::string recurso);


  private:
   int _nroOrden;
   int _cantidad;
   char _idRecurso[30];
};