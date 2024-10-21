#include "orden-produccion.h"
#include <cstring>

OrdenProduccion::OrdenProduccion() {
   this->_id = 0;
   this->_fecha = Fecha();
   this->_estado = 'I';
}


OrdenProduccion::OrdenProduccion(int id, Fecha fecha, char estado) : Orden(id, fecha, estado) {
   this->_id = id;
   this->_fecha = fecha;
   this->_estado = estado;
}

std::string OrdenProduccion::getIdProducto() {
   return _idProducto;
}

void OrdenProduccion::setIdProducto(std::string id) {
   strcpy(this->_idProducto, id.c_str());
}


