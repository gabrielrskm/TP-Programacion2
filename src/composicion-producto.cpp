#include "../include/composicion-producto.h"
#include <cstring>

ComposicionProducto::ComposicionProducto()
{
   memset(this->_idRecursoInsumo, 0, sizeof(this->_idRecursoInsumo));
   memset(this->_idRecursoProducto, 0, sizeof(this->_idRecursoProducto)); 
   this->_cantidad = 0;
}


ComposicionProducto::ComposicionProducto(std::string insumoId, std::string productoId, int cantidad)
{
   strcpy(this->_idRecursoInsumo, insumoId.c_str());
   strcpy(this->_idRecursoProducto, productoId.c_str());
   this->_cantidad = cantidad;
}

int ComposicionProducto::getCantidad()
{
   return this->_cantidad;
}

void ComposicionProducto::setCantidad(int cantidad)
{
   this->_cantidad = cantidad;
}

std::string ComposicionProducto::getIdInsumo()
{
   return this->_idRecursoInsumo;
}

void ComposicionProducto::setIdInsumo(std::string idInsumo)
{
   strcpy(this->_idRecursoInsumo, idInsumo.c_str());
}

std::string ComposicionProducto::getIdProducto()
{
   return this->_idRecursoProducto;
}

void ComposicionProducto::setIdProducto(std::string idProducto)
{
   strcpy(this->_idRecursoProducto, idProducto.c_str());
}
