#include "../include/cliente.h"

#include <cstring>

#include "../include/persona.h"

Cliente::Cliente() {
}

Cliente::Cliente(bool prioridad, float totalVentas, int id, int telefono, char tipoFJ, std::string nombre,
                 std::string direccion, std::string email)
    : Persona(id, telefono, tipoFJ, nombre, direccion, email), _prioridad(prioridad), _totalVentas(totalVentas) {
   this->_prioridad = prioridad;
   this->_totalVentas = totalVentas;
   this->_id = id;
   this->_telefono = telefono;
   this->tipoFJ = tipoFJ;
   strcpy(this->_nombre, nombre.c_str());
   strcpy(this->_direccion, direccion.c_str());
   strcpy(this->_email, email.c_str());
   this->_fechaIngreso = Fecha();
}

void Cliente::setPrioridad(bool prioridad) {
   this->_prioridad = prioridad;
}

bool Cliente::getPrioridad() {
   return this->_prioridad;
}

void Cliente::setTotalVentas(float totalVentas) {
   this->_totalVentas = totalVentas;
}

float Cliente::getTotalVentas() {
   return this->_totalVentas;
}
