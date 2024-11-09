#include "../include/usuario.h"
#include "../include/persona.h"
#include <cstring>

Usuario::Usuario() {
}


Usuario::Usuario(char rol, std::string pass, std::string nombreUsuario, Fecha fecha, int id, int telefono, char tipoFJ,
                 std::string nombre, std::string direccion, std::string email)
    : Persona(id, telefono, tipoFJ, nombre, direccion, email){

   this->setRol(rol);
   strcpy(this->_nombreUsuario, nombreUsuario.c_str());
   strcpy(this->_password, pass.c_str());
   this->_id = id;
   this->_telefono = telefono;
   this->tipoFJ = tipoFJ;
   strcpy(this->_nombre, nombre.c_str());
   strcpy(this->_direccion, direccion.c_str());
   strcpy(this->_email, email.c_str());
   this->_fechaIngreso = Fecha();
   this->setEstadoUsuario(true); 
}

void Usuario::setPassword(std::string password) {
   strcpy(this->_password, password.c_str());
}

std::string Usuario::getPassword() {
   return std::string(this->_password);
}

char Usuario::getRol() {
   return this->_rol;
}

void Usuario::setRol(char rol) {
   this->_rol = rol;
}

std::string Usuario::getNombreUsuario() {
   std::string nombre = std::string(this->_nombreUsuario);
   return nombre;
}

void Usuario::setNombreUsuario(std::string nombreUsuario) {
   strcpy(this->_nombreUsuario, nombreUsuario.c_str());
}

bool Usuario::validarUsuarioYPass(std::string nombreUsuario, std::string pass){
        if (nombreUsuario.size() < 3 || nombreUsuario.size() > 19) return false;
        if (pass.size() < 4 || pass.size() > 19) return false;
        return true;
    
    }

bool Usuario::validarRol(std::string rol) {    
    if (rol == "a" || rol == "A") return true;
    else if (rol == "u" || rol == "U") return true;
    else if (rol == "v" || rol == "V") return true;
    else if (rol == "c" || rol == "C") return true;
    else return false; 

}

bool Usuario::getEstadoUsuario() {
    return this->_usuarioActivo; 
}

void Usuario::setEstadoUsuario(bool estado) {
    this->_usuarioActivo = estado; 
}