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
         return;  // Directorio creado exitosamente
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
      this->archivoUsuario.Guardar(Usuario('a', "pass", "root", Fecha(1, 1, 2000), 0, 0, 'F', "root", "root", "root"));
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
int Manager::buscarUsuario(std::string nombreUsuario) {
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

bool Manager::esAdmin() {
   if(this->_tipoUsuario == 'A' || this->_tipoUsuario == 'a'){
      return true;
   }
   return false;
}

bool Manager::esComprador() {
   if(this->_tipoUsuario == 'C' || this->_tipoUsuario == 'c'){
      return true;
   }
   return false;
}

bool Manager::esVendedor() {
   if(this->_tipoUsuario == 'V' || this->_tipoUsuario == 'v'){
      return true;
   }
   return false;
}

// funcionalidades insumos
int Manager::agregarInsumo(Recurso recurso) {
   recurso.setOrigen(false);
   return this->archivoRecurso.Guardar(recurso);
}

bool Manager::borrarInsumo(int pos) {

   Recurso rs = this->archivoRecurso.Leer(pos);
   rs.setEstaBorrado(true);
   return this->archivoRecurso.Guardar(rs, pos);
}
int Manager::buscarInsumo(std::string codigo) {
   if (codigo.length() > 20 || codigo.length() == 0) {
      return -2;
   }
   int pos = this->archivoRecurso.Buscar(codigo);
   if(this->archivoRecurso.Leer(pos).getOrigen()){
      return -1;
   }
   return pos;
}
bool Manager::estaBorrado(int pos) {
   return this->archivoRecurso.Leer(pos).getEstaBorrado();
}
bool Manager::modificarInsumo(Recurso insumo, int pos) {
   return this->archivoRecurso.Guardar(insumo, pos);
}
int Manager::cantidadInsumos() {
   return this->archivoRecurso.CantidadRegistros();
}
Recurso* Manager::listaInsumos(int cant) {
   if (cant == 0) {
      return nullptr;
   }
   Recurso* vector = new Recurso[cant];
   this->archivoRecurso.Leer(cant, vector);
   if (vector == nullptr) {
      return nullptr;
   }
   return vector;
}

Recurso Manager::getInsumo(int pos) {
   return this->archivoRecurso.Leer(pos);
}

bool Manager::modificarStockInsumo(int stock, int pos) {
   Recurso recurso = this->archivoRecurso.Leer(pos);
   recurso.setStock(stock);
   return this->archivoRecurso.Guardar(recurso, pos);
}
