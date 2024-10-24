#include "../include/orden-venta.h"

OrdenVenta::OrdenVenta(){
   this->_id = 0;
   this->_fecha = Fecha();
   this->_estado = 'I';
}
OrdenVenta::OrdenVenta(int idCliente) {
   this->_id = idCliente;
   this->_fecha = Fecha();
   this->_estado = 'I';
}

void OrdenVenta::setIdCliente(int id) {
   this->_id = id;
}

int OrdenVenta::getIdCliente() {
   return this->_id;
}
