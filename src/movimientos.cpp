#include "movimientos.h"
#include <cstring>

Movimientos::Movimientos() {
   this->_nroMovimiento = 0;
   this->_fecha = Fecha();
   this->_motivo[0] = '\0';
   this->_tipoMovimiento = '\0';
   this->_id[0] = '\0';
   this->_destino = false;
}

Movimientos::Movimientos(Fecha fecha, std::string motivo, char tipo, std::string id) {
   this->_nroMovimiento = 0;
   this->_fecha = fecha;
   strcpy(this->_motivo, motivo.c_str());
   this->_tipoMovimiento = tipo;
   strcpy(this->_id, id.c_str());
   this->_destino = false;
}

Fecha Movimientos::getFecha() {
   return this->_fecha;
}

void Movimientos::setFecha(Fecha f) {
   this->_fecha = f;
}

std::string Movimientos::getMotivo() {
   return this->_motivo;
}

void Movimientos::setMotivo(std::string motivo) {
   strcpy(this->_motivo, motivo.c_str());
}

char Movimientos::getTipoMovimiento() {
   return this->_tipoMovimiento;
}

void Movimientos::setTipoMovimiento(char tipo) {
   this->_tipoMovimiento = tipo;
}

bool Movimientos::getDestino() {
   return this->_destino;
}

void Movimientos::setDestino(bool destino) {
   this->_destino = destino;
}

std::string Movimientos::getId() {
   return this->_id;
}

void Movimientos::setId(std::string id) {
   strcpy(this->_id, id.c_str());
}

int Movimientos::getNroMovimiento() {
   return this->_nroMovimiento;
}

void Movimientos::setNroMovimiento(int nroMovimiento) {
   this->_nroMovimiento = nroMovimiento;
}
