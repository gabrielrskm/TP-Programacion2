#include "../include/composicion-producto.h"
#include <cstring>

ComposicionProducto::ComposicionProducto()
{
   memset(this->_idRecursoInsumo, 0, sizeof(this->_idRecursoInsumo));
   memset(this->_idRecursoProducto, 0, sizeof(this->_idRecursoProducto)); 
   this->_cantidad = 0;
   this->setId();
}


ComposicionProducto::ComposicionProducto(std::string productoId, std::string insumoId, int cantidad)
{
   strcpy(this->_idRecursoInsumo, insumoId.c_str());
   strcpy(this->_idRecursoProducto, productoId.c_str());
   this->_cantidad = cantidad;
   this->setId();
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
   std::string id = this->_idRecursoInsumo;
   return id;
}

void ComposicionProducto::setIdInsumo(std::string idInsumo)
{
   strcpy(this->_idRecursoInsumo, idInsumo.c_str());
}

std::string ComposicionProducto::getIdProducto()
{
   std::string id = this->_idRecursoProducto;
   return id;
}

void ComposicionProducto::setIdProducto(std::string idProducto)
{
   strcpy(this->_idRecursoProducto, idProducto.c_str());
}

std::string ComposicionProducto::getId()
{
   std::string id = this->_id;
   return id;
}

void ComposicionProducto::setId()
{
   std::string idProducto = this->getIdProducto();
   std::string idInsumo= this->getIdInsumo();
   std::string id = idProducto+idInsumo;
   strcpy(this->_id, id.c_str());
}
