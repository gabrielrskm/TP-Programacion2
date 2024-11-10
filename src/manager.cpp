#include "../include/manager.h"

#include <direct.h>

Manager::Manager() {
   this->_cacheListadoUsuarios = nullptr;
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
   if (archivoUsuario.getCantidadRegistros() < 1) {
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
	int posicionUsuario = this->buscarUsuario(user, false);
	if (posicionUsuario < 0) {
		return false;
	}

	Usuario usuario = this->archivoUsuario.Leer(posicionUsuario);

	if (usuario.getPassword() != pass) {
		return false;
	}

	this->_usuarioLoggeado = usuario;
	this->_nombreUsuario = usuario.getNombreUsuario();
	this->_rolUsuario = usuario.getRol();
	this->_tienePrivilegios = this->_rolUsuario == 'a' || this->_rolUsuario == 'A';

	return true;
}


std::string Manager::getNombreUsuario() {
	return this->_nombreUsuario;
}
int Manager::buscarUsuario(std::string nombreUsuario) {
   return this->archivoUsuario.Buscar(nombreUsuario,1);
}
int Manager::buscarUsuario(std::string nombreUsuario, bool buscarEnCache) {
	if (buscarEnCache) {
		return this->buscar(nombreUsuario, 1);
	}
	else {
		return this->archivoUsuario.Buscar(nombreUsuario, 1);
	}


}

int Manager::buscarEmail(std::string email, bool buscarEnCache) {
	if (buscarEnCache) {
		return this->buscar(email, 2);
	}
	else {
		return this->archivoUsuario.Buscar(email, 2);
	}
}

int Manager::buscarTelefono(std::string telefono, bool buscarEnCache) {
	if (buscarEnCache) {
		return this->buscar(telefono, 3);
	}
	else {
		return this->archivoUsuario.Buscar(telefono, 3);
	}
}

bool Manager::agregarUsuario(Usuario usuario) {
	return this->archivoUsuario.Guardar(usuario);
}

Usuario* Manager::listaUsuarios() {
	return this->archivoUsuario.LeerTodos();
}

int Manager::cantidadUsuarios() {
	return this->archivoUsuario.getCantidadRegistros();
}

bool Manager::getPrivilegios() {
	return this->_tienePrivilegios;
}

Manager::~Manager() {
   if(_cacheListadoUsuarios!= nullptr){
	   delete[] _cacheListadoUsuarios;
   }
}

void Manager::actualizarCacheUsuarios() {
	this->_cacheListadoUsuarios = this->listaUsuarios();
}

Usuario* Manager::getCacheListadoUsuarios() {
	return this->_cacheListadoUsuarios;
}
int Manager::buscar(std::string busqueda, int tipoDeBusqueda) {
	// tipoDeBusqueda indica lo que queremos buscar:
	// 1- usuario
	// 2- email
	// 3- telefono

	int cantidadRegistros = this->archivoUsuario.getCantidadRegistros();

	int i = 0;
	while (i < cantidadRegistros) {
		switch (tipoDeBusqueda) {
		case 1: {		
			if (this->_cacheListadoUsuarios[i].getNombreUsuario() == busqueda) {
				return i;
			}
			break;
		}
		case 2: {
			if (this->_cacheListadoUsuarios[i].getEmail() == busqueda) {
				return i;
			}
			break;
		}
		case 3: {
			if (this->_cacheListadoUsuarios[i].getTelefono() == std::stoi(busqueda)) {
				return i;
			}
			break;
		}
		}
		i++;
	}
	return -1;
}

Usuario Manager::leerUsuario(int posicion) {
	return this->archivoUsuario.Leer(posicion);
}

bool Manager::reescribirUsuario(Usuario usuario, int posicion) {
	return this->archivoUsuario.Guardar(usuario, posicion);
}


bool Manager::esAdmin() {
   if (this->_rolUsuario == 'A' || this->_rolUsuario == 'a') {
      return true;
   }
   return false;
}

bool Manager::esComprador() {
   if (this->_rolUsuario == 'C' || this->_rolUsuario == 'c') {
      return true;
   }
   return false;
}

bool Manager::esVendedor() {
   if (this->_rolUsuario == 'V' || this->_rolUsuario == 'v') {
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
      return -2;//ingreso mal el codigo por teclado
   }
   int pos = this->archivoRecurso.Buscar(codigo);
   if(pos== -1){
      return pos;//no existe el insumo, devuelve -1
   }
   if(this->archivoRecurso.Leer(pos).getEstaBorrado()){
      return -4;//el recurso esta borrado
   }
   if (this->archivoRecurso.Leer(pos).isProducto()) {
      return -3;//codigo que existe pero es un producto
   }
   return pos;
}
bool Manager::estaBorrado(int pos) {
   return this->archivoRecurso.Leer(pos).getEstaBorrado();
}
bool Manager::modificarInsumo(Recurso insumo, int pos) {
   return this->archivoRecurso.Guardar(insumo, pos);
}

bool Manager::listaRecursos(int pos, int cant, bool isProducto, bool borrado, Recurso*& vector, int &vectorSize) {
   
   int cantRegistros = this->archivoRecurso.CantidadRegistros();
   if(cantRegistros == 0){
      return false;
   }
   if(cant == 0){
      cant = cantRegistros;
   }
   Recurso* vectorTemp = new Recurso[cantRegistros];
   this->archivoRecurso.Leer(cant, vectorTemp);
   if (vectorTemp == nullptr) {
      return false;
   }
   int counter = 0;
   if(isProducto && !borrado){//producto no borrado
      for (int i = 0; i<cantRegistros; i++){
         if(vectorTemp[i].isProducto() && !vectorTemp[i].getEstaBorrado()){
            counter++;
         }
      }
      vector = new Recurso[counter];
      if(vector == nullptr){
         vectorSize = 0;
         delete[] vectorTemp;
         return false;
      }
      vectorSize = counter;
      counter = 0;
      for(int i = 0; i < cantRegistros; i++){
         if(vectorTemp[i].isProducto() && !vectorTemp[i].getEstaBorrado()){
            vector[counter] = vectorTemp[i];
            counter++;
         }
      }
   } 
   else if (isProducto && borrado) {//producto borrado
      for (int i = 0; i<cantRegistros; i++){
         if(vectorTemp[i].isProducto() && vectorTemp[i].getEstaBorrado()){
            counter++;
         }
      }
      vector = new Recurso[counter];
      if(vector == nullptr){
         vectorSize = 0;
         delete[] vectorTemp;
         return false;
      }
      vectorSize = counter;
      counter = 0;
      for(int i = 0; i < cantRegistros; i++){
         if(vectorTemp[i].isProducto() && vectorTemp[i].getEstaBorrado()){
            vector[counter] = vectorTemp[i];
            counter++;
         }
      }
   }
   else if(!isProducto && !borrado){//insumo no borrado
      for (int i = 0; i<cantRegistros; i++){
         if(vectorTemp[i].isInsumo() && !vectorTemp[i].getEstaBorrado()){
            counter++;
         }
      }
      vector = new Recurso[counter];
      if(vector == nullptr){
         vectorSize = 0;
         delete[] vectorTemp;
         return false;
      }
      vectorSize = counter;
      counter = 0;
      for(int i = 0; i < cantRegistros; i++){
         if(vectorTemp[i].isInsumo() && !vectorTemp[i].getEstaBorrado()){
            vector[counter] = vectorTemp[i];
            counter++;
         }
      }
   }
   else if(!isProducto && borrado){//insumo borrado
      for (int i = 0; i<cantRegistros; i++){
         if(vectorTemp[i].isInsumo() && vectorTemp[i].getEstaBorrado()){
            counter++;
         }
      }
      vector = new Recurso[counter];
      if(vector == nullptr){
         vectorSize = 0;
         delete[] vectorTemp;
         return false;
      }
      vectorSize = counter;
      counter = 0;
      for(int i = 0; i < cantRegistros; i++){
         if(vectorTemp[i].isInsumo() && vectorTemp[i].getEstaBorrado()){
            vector[counter] = vectorTemp[i];
            counter++;
         }
      }
   }
   delete[] vectorTemp;
   return true;
}

Recurso Manager::getRecurso(int pos) {
   return this->archivoRecurso.Leer(pos);
}

bool Manager::modificarStockInsumo(int stock, int pos) {
   Recurso recurso = this->archivoRecurso.Leer(pos);
   recurso.setStock(stock);
   return this->archivoRecurso.Guardar(recurso, pos);
}

// funcionalidades productos

int Manager::buscarProducto(std::string codigo) {
   if (codigo.length() > 20 || codigo.length() == 0) {
      return -2;
   }
   int pos = this->archivoRecurso.Buscar(codigo);
   if(pos== -1){
      return pos;
   }
   Recurso producto = this->archivoRecurso.Leer(pos);
   if (!producto.isProducto()) {
      return -3;//el codigo existe pero es un insumo
   }
   if(producto.getEstaBorrado()){
      return -4;//el producto fue borrado previamente
   }
   return pos;
}

int Manager::agregarProducto(Recurso producto) {
   producto.setOrigen(true);
   return this->archivoRecurso.Guardar(producto);
}

bool Manager::borrarProducto(int pos) {
   return this->borrarInsumo(pos);
}
bool Manager::modificarStockRecurso(int stock, int pos) {
   return this->modificarStockInsumo(stock, pos);
}

bool Manager::getComposicionProducto(int pos,Recurso*& vector,int& composicionSize,std::string codigo) {
   ComposicionProducto* allComposicion = nullptr;
   int totalSize = 0;
   this->archivoComposicionProducto.LeerTodo(allComposicion,totalSize);
   if(totalSize == 0 || allComposicion == nullptr){
      return false;
   }
   int counter = 0;
   //verifico que exista composiciones con el codigo del producto solicitado
   for(int i = 0; i < totalSize; i++){
      if(allComposicion[i].getIdProducto()== codigo){
         counter++;
      }
   }
   if(counter == 0){
      composicionSize = 0;
      delete[] allComposicion;
      return false;
   }
   std::string* codigos = new std::string[counter];
   int* cantidades = new int[counter];
   if(codigos == nullptr){
      composicionSize = 0;
      delete[] allComposicion;
      return false;
   }
   counter = 0;
   //como hay composiciones que tienen el codigo solicitado los copio los codigos de los insumos en
   //una matriz de string de codigos
   //el contador en este caso me cuenta solo los insumos
   for(int i = 0; i < totalSize; i++){
      if(allComposicion[i].getIdProducto()== codigo){
         codigos[counter] = allComposicion[i].getIdInsumo();
         cantidades[counter] = allComposicion[i].getCantidad();
         counter++;
      }
   }

   vector = new Recurso[counter];
   if(vector == nullptr){
      composicionSize = 0;
      delete[] allComposicion;
      delete[] codigos;
      return false;
   }
   composicionSize = counter;
   counter = 0;
   int posInsumo = 0;
   //ahora en base al vector de codigos de insumo armo un vector de 
   //objetos recursos con todos los codigos de los insumos que lleva la cosa
   for(int i = 0; i < composicionSize; i++){
      posInsumo = this->buscarInsumo(codigos[i]);
      vector[i] = this->getRecurso(posInsumo);
      vector[i].setFuturo(cantidades[i]);
   }
   delete[] codigos;
   delete[] allComposicion;
   return true;
}
bool Manager::setComposicionProducto(std::string idProducto, std::string idInsumo, int cantidad) {
   ComposicionProducto composicion(idProducto,idInsumo,cantidad);
   if(this->archivoComposicionProducto.Buscar(composicion.getId())<0){
      return this->archivoComposicionProducto.Guardar(composicion);
   }
   return false;
}
