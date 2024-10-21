#include "orden-compra.h"
OrdenCompra::OrdenCompra(){
   this->_id = 0;
   this->_fecha = Fecha();
   this->_estado = 'I';
}
OrdenCompra::OrdenCompra(int id, Fecha fecha, char estado) : Orden(id, fecha, estado) {
   this->_id = id;
   this->_fecha = fecha;
   this->_estado = estado;
}

void OrdenCompra::setIdProveedor(int id) {
   this->_id = id;
}

int OrdenCompra::getIdProveedor() {
   return this->_id;
}
