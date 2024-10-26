#include "../include/composicion-movimientos.h"
#include <cstring>

ComposicionMovimientos::ComposicionMovimientos() {
   this->_cantidad = 0;
   strcpy(this->_idRecurso, "");
   this->_nroMovimiento = 0;
}

ComposicionMovimientos::ComposicionMovimientos(int cantidad, std::string idRecurso, int _nroMovimiento) {
   this->_cantidad = cantidad;
   strcpy(this->_idRecurso, idRecurso.c_str());
   this->_nroMovimiento = _nroMovimiento;
}

int ComposicionMovimientos::getCantidad() {
   return _cantidad;
}

void ComposicionMovimientos::setCantidad(int q) {
   _cantidad = q;
}

int ComposicionMovimientos::getNroMovimiento() {
   return _nroMovimiento;
}

void ComposicionMovimientos::setNroMovimiento() {
   _nroMovimiento++;
}

std::string ComposicionMovimientos::getIdRecurso() {
   return _idRecurso;
}

void ComposicionMovimientos::setIdRecurso(std::string recurso) {
   strcpy(this->_idRecurso, recurso.c_str());
}


