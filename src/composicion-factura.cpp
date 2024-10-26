#include "../include/composicion-factura.h"
#include <cstring>

ComposicionFactura::ComposicionFactura() {}

ComposicionFactura::ComposicionFactura(int cantidad, int nroFactura,char tipoFactura, std::string idRecurso) {
   _cantidad = cantidad;
   _nroFactura = nroFactura;
   _tipoFactura = tipoFactura;
   strcpy(_idRecurso,idRecurso.c_str());
}

int ComposicionFactura::getCantidad() {
   return _cantidad;
}

void ComposicionFactura::setCantidad(int q) {
   _cantidad = q;
}

int ComposicionFactura::getNroFactura() {
   return _nroFactura;
}


void ComposicionFactura::setNroFactura(int nroFactura) {
   _nroFactura = nroFactura;
}

char ComposicionFactura::getTipoFactura() {
   return _tipoFactura;
}

void ComposicionFactura::setTipoFactura(char tipo) {
   _tipoFactura = tipo;
}

std::string ComposicionFactura::getIdRecurso() {
   return _idRecurso;
}

void ComposicionFactura::setIdRecurso(std::string recurso) {
   strcpy(_idRecurso,recurso.c_str());
}
