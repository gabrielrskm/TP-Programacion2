#include "../include/usuario.h"

#include <cstring>

#include "../include/persona.h"

Usuario::Usuario() {
}


Usuario::Usuario(char tipo, std::string pass, std::string nombreUsuario, Fecha fecha, int id, int telefono, char tipoFJ,
                 std::string nombre, std::string direccion, std::string email)
    : Persona(id, telefono, tipoFJ, nombre, direccion, email){

   this->_tipo = tipo;
   strcpy(this->_nombreUsuario, nombreUsuario.c_str());
   strcpy(this->_password, pass.c_str());
   this->_id = id;
   this->_telefono = telefono;
   this->tipoFJ = tipoFJ;
   strcpy(this->_nombre, nombre.c_str());
   strcpy(this->_direccion, direccion.c_str());
   strcpy(this->_email, email.c_str());
   this->_fechaIngreso = Fecha();
}

void Usuario::setPassword(std::string password) {
   strcpy(this->_password, password.c_str());
}

std::string Usuario::getPassword() {
   return std::string(this->_password);
}

char Usuario::getTipo() {
   return this->_tipo;
}

void Usuario::setTipo(char tipo) {
   this->_tipo = tipo;
}

std::string Usuario::getNombreUsuario() {
   std::string nombre = std::string(this->_nombreUsuario);
   return nombre;
}

void Usuario::setNombreUsuario(std::string nombreUsuario) {
   strcpy(this->_nombreUsuario, nombreUsuario.c_str());
}

bool Usuario::validarUsuarioYPass(std::string nombreUsuario, std::string pass){
        if (nombreUsuario.size() < 1 || nombreUsuario.size() > 20) return false;
        if (pass.size() < 1 || pass.size() > 20) return false;
        return true;
    
    }