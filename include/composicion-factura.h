#pragma once
#include <iostream>
#include "fecha.h"


class ComposicionFactura{
  public:
   ComposicionFactura();
   ComposicionFactura(int cantidad, int nroFactura,char tipoFactura, std::string idRecurso);
   
   int getCantidad();
   void setCantidad(int q);
   int getNroFactura();
   void setNroFactura(int nroFactura);
   char getTipoFactura();
   void setTipoFactura(char tipo);
   std::string getIdRecurso();
   void setIdRecurso(std::string recurso);


  private:
   int _nroFactura;
   char _tipoFactura;
   int _cantidad;
   char _idRecurso[30];
};