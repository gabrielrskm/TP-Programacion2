#include "../include/proveedor.h"

#include <cstring>

#include "../include/persona.h"

Proveedor::Proveedor(): Persona() {  // Llamar al constructor por defecto de Persona
       _condicionPago = 'C';  // Valor por defecto
       _totalCompras = 0.0f;
   }

Proveedor::Proveedor(char condicionPago, float totalCompras, int id, int telefono,
             char tipoFJ, std::string nombre, std::string direccion, std::string email)
       : Persona(id, telefono, tipoFJ, nombre, direccion, email),  // Llamada al constructor de Persona
         _condicionPago(condicionPago), _totalCompras(totalCompras){

   this->_condicionPago = condicionPago;
   this->_totalCompras = totalCompras;
   this->_id = id;
   this->_telefono = telefono;
   this->tipoFJ = tipoFJ;
   strcpy(this->_nombre, nombre.c_str());
   strcpy(this->_direccion, direccion.c_str());
   strcpy(this->_email, email.c_str());
   this->_fechaIngreso = Fecha();
}

char Proveedor::getCondicionPago() {
   return this->_condicionPago;
}

void Proveedor::setCondicionPago(char condicionPago) {
   this->_condicionPago = condicionPago;
}

float Proveedor::getTotalCompras() {
   return this->_totalCompras;
}

void Proveedor::setTotalCompras(float totalCompras) {
   this->_totalCompras = totalCompras;
}