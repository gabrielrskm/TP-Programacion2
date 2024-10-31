#include "../include/manager.h"
#include <direct.h>

Manager::Manager() {
   this->archivoCliente = ArchivoCliente();
   this->archivoComposicionFactura = ArchivoComposicionFactura();
   this->archivoComposicionMovimientos = ArchivoComposicionMovimientos();
   this->archivoComposicionOrden = ArchivoComposicionOrden();
   this->archivoComposicionProducto = ArchivoComposicionProducto();
   this->archivoFactura = ArchivoFactura();
   this->archivoMovimientos = ArchivoMovimientos();
   this->archivoOrdenCompra = ArchivoOrdenCompra();
   this->archivoOrdenProduccion = ArchivoOrdenProduccion();
   this->archivoOrdenVenta = ArchivoOrdenVenta();
   this->archivoProveedor = ArchivoProveedor();
   this->archivoRecurso = ArchivoRecurso();
   this->archivoUsuario = ArchivoUsuario();
   if (archivoUsuario.CantidadRegistros() == 0) {
      if (_mkdir("db") != 0) {
        return; // Directorio creado exitosamente
      } 
      this->archivoCliente.Crear();
      this->archivoComposicionFactura.Crear();
      this->archivoComposicionMovimientos.Crear();
      this->archivoComposicionOrden.Crear();
      this->archivoComposicionProducto.Crear();
      this->archivoFactura.Crear();
      this->archivoMovimientos.Crear();
      this->archivoOrdenCompra.Crear();
      this->archivoOrdenProduccion.Crear();
      this->archivoOrdenVenta.Crear();
      this->archivoProveedor.Crear();
      this->archivoRecurso.Crear();
      this->archivoUsuario.Crear();
      this->archivoUsuario.Guardar(Usuario('a',"pass","root",Fecha(1,1,2000),0,0,'F',"root","root","root"));
   }
}

bool Manager::login(std::string user, std::string pass) {
   int pos = this->archivoUsuario.Buscar(user);
   if (pos == -1) {
      return false;
   }
   if (this->archivoUsuario.Leer(pos).getPassword() != pass) {
      return false;
   }
   this->_nombreUsuario = this->archivoUsuario.Leer(pos).getNombreUsuario();
   this->_tipoUsuario = this->archivoUsuario.Leer(pos).getTipo();
   return true;
}


std::string Manager::getNombreUsuario() {
   return this->_nombreUsuario;
}
int Manager::buscarUsuario(std::string nombreUsuario){
   return this->archivoUsuario.Buscar(nombreUsuario);
}

bool Manager::agregarUsuario(Usuario usuario) {
   return this->archivoUsuario.Guardar(usuario);
}

Usuario* Manager::listaUsuarios() {
   return this->archivoUsuario.LeerTodos();
}

int Manager::cantidadUsuarios() {
   return this->archivoUsuario.CantidadRegistros();
}