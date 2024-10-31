#include "../include/persona.h"
#include <cstring>

Persona::Persona() {
   this->_id = 0;
   this->_telefono = 0;
   this->tipoFJ = ' ';
   strcpy(this->_nombre, " ");
   strcpy(this->_direccion, " ");
   strcpy(this->_email, " ");
   this->_fechaIngreso = Fecha();
   this->_activo = true;
}

Persona::Persona(int id, int telefono,
                 char tipoFJ, std::string nombre, std::string direccion, std::string email) {
   this->_id = id;
   this->_telefono = telefono;
   this->tipoFJ = tipoFJ;
   strcpy(this->_nombre, nombre.c_str());
   strcpy(this->_direccion, direccion.c_str());
   strcpy(this->_email, email.c_str());
   this->_fechaIngreso = Fecha();
}

Fecha Persona::getFecha() {
   return this->_fechaIngreso;
}

void Persona::setFecha(Fecha f) {
   this->_fechaIngreso = f;
}

char Persona::getTipoFJ() {
   return this->tipoFJ;
}

void Persona::setTipoFJ(char tipoFJ) {
   this->tipoFJ = tipoFJ;
}

int Persona::getId() {
   return this->_id;
}

void Persona::setId(int id) {
   this->_id = id;
}

std::string Persona::getNombre() {
   return this->_nombre;
}

void Persona::setNombre(std::string nombre) {
   strcpy(this->_nombre, nombre.c_str());
}

std::string Persona::getDireccion() {
   return this->_direccion;
}

void Persona::setDireccion(std::string direccion) {
   strcpy(this->_direccion, direccion.c_str());
}

std::string Persona::getEmail() {
   return this->_email;
}

void Persona::setEmail(std::string email) {
   strcpy(this->_email, email.c_str());
}
