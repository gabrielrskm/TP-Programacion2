#pragma once
#include <iostream>

class ComposicionProducto{
  public:
   ComposicionProducto();
   ComposicionProducto(std::string insumoId, std::string productoId, int cantidad);
   int getCantidad();
   void setCantidad(int cantidad);
   std::string getIdProducto();
   void setIdProducto(std::string idProducto);
   std::string getIdInsumo();
   void setIdInsumo(std::string idInsumo);


  private:
   char _idRecursoProducto[30];
   char _idRecursoInsumo[30];
   int _cantidad;
};