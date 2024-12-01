#include "../include/orden-produccion.h"
#include <cstring>

OrdenProduccion::OrdenProduccion() {
   this->_id = 0;
   this->_fecha = Fecha();
   this->_estado = 'I'; //i: iniciado, f: finalizado, c: cancelado
}


OrdenProduccion::OrdenProduccion(int id, Fecha fecha, char estado) : Orden(id, fecha, estado) {
   this->_id = id;
   this->_fecha = fecha;
   this->_estado = estado;
}

std::string OrdenProduccion::getIdProducto() {
   std::string id = _idProducto;
   return id;
}

void OrdenProduccion::setIdProducto(std::string id) {
   strcpy(this->_idProducto, id.c_str());
}

int OrdenProduccion::getCantidad() {
   return this->cantidad;
}
void OrdenProduccion::setCantidad(int cantidad) {
   if(cantidad <= 0){
      return;
   }
   this->cantidad = cantidad;
}

