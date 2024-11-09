#pragma once
#include <iostream>

class Recurso {
  public:
   Recurso();
   Recurso(std::string codigo, std::string descripcion, std::string tipoMedicion, int stock, int futuro,
           bool origenInterno);
   std::string getCodigo();
   void setCodigo(std::string codigo);
   std::string getDescripcion();
   void setDescripcion(std::string descripcion);
   std::string getTipoMedicion();
   void setTipoMedicion(std::string medicion);
   int getStock();
   void setStock(int futuro);
   int getFuturo();
   void setFuturo(int futuro);
   bool isInsumo();
   bool isProducto();
   void setOrigen(bool origen);

   //funcionalidase insumo  
   bool getEstaBorrado();
   void setEstaBorrado(bool borrado);


  private:
   char _codigo[30];
   char _descripcion[50];
   char _tipoMedicion[10];
   int _stock;
   int _futuro;
   bool _origenInterno;
   bool _estaBorrado;
};