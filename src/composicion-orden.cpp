#include "../include/composicion-orden.h"
#include <cstring>

ComposicionOrden::ComposicionOrden() {
   this->_cantidad = 0;
   strcpy(this->_idRecurso, "");
   this->_nroOrden = 0;
}

ComposicionOrden::ComposicionOrden(int cantidad, std::string idRecurso, int _nroOrden) {
   this->_cantidad = cantidad;
   strcpy(this->_idRecurso, idRecurso.c_str());
   this->_nroOrden = _nroOrden;
}

int ComposicionOrden::getCantidad() {
   return _cantidad;
}

void ComposicionOrden::setCantidad(int q) {
   _cantidad = q;
}

int ComposicionOrden::getNroOrden() {
   return _nroOrden;
}

void ComposicionOrden::setNroOrden() {
   _nroOrden++;
}

std::string ComposicionOrden::getIdRecurso() {
   return _idRecurso;
}

void ComposicionOrden::setIdRecurso(std::string recurso) {
   strcpy(this->_idRecurso, recurso.c_str());
}


