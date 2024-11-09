#include "../include/recurso.h"
#include <cstring>

Recurso::Recurso(){
   strcpy(this->_codigo,"");
   strcpy(this->_descripcion,"");
   strcpy(this->_tipoMedicion,"");
   this->_stock = 0;
   this->_futuro = 0;
   this->_origenInterno = false;
}

Recurso::Recurso(std::string codigo, std::string descripcion,
                 std::string tipoMedicion, int stock, int futuro, bool origenInterno){
   strcpy(this->_codigo,codigo.c_str());
   strcpy(this->_descripcion,descripcion.c_str());
   strcpy(this->_tipoMedicion,tipoMedicion.c_str());
   this->_stock = 0;
   this->_futuro = futuro;
   this->_origenInterno = origenInterno;
}

std::string Recurso::getCodigo(){
   return std::string(this->_codigo);
}

void Recurso::setCodigo(std::string codigo){
   strcpy(this->_codigo,codigo.c_str());
}

std::string Recurso::getDescripcion(){
   return std::string(this->_descripcion);
}

void Recurso::setDescripcion(std::string descripcion){
   strcpy(this->_descripcion,descripcion.c_str());
}

std::string Recurso::getTipoMedicion(){
   return std::string(this->_tipoMedicion);
}

void Recurso::setTipoMedicion(std::string medicion){
   strcpy(this->_tipoMedicion,medicion.c_str());
}

int Recurso::getStock(){
   return this->_stock;
}

void Recurso::setStock(int futuro){
   this->_stock = futuro;
}

int Recurso::getFuturo(){
   return this->_futuro;
}

void Recurso::setFuturo(int futuro){
   this->_futuro = futuro;
}

bool Recurso::isInsumo(){
   return !(this->_origenInterno);
}
bool Recurso::isProducto(){
   return this->_origenInterno;
}

void Recurso::setOrigen(bool origen){
   this->_origenInterno = origen;
}

//funcionalidades insumo

bool Recurso::getEstaBorrado(){
   return this->_estaBorrado;
}

void Recurso::setEstaBorrado(bool borrado){
   this->_estaBorrado = borrado;
}