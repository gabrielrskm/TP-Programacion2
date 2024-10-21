#include "orden.h"

Orden::Orden(){
   this->_id = 0;
   this->_fecha = Fecha();
   this->_estado = 'I';
}

Orden::Orden(int id, Fecha fecha,char estado){
   this->_id = id;
   this->_fecha = fecha;
   this->_estado = estado;
}

int Orden::getId(){
   return this->_id;
}

void Orden::setId(int id){
   this->_id = id;
}

char Orden::getEstado(){
   return this->_estado;
}

void Orden::setEstado(char estado){
   this->_estado = estado;
}

Fecha Orden::getFecha(){
   return this->_fecha;
}

void Orden::setFecha(Fecha fecha){
   this->_fecha = fecha;
}
