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
		this->archivoUsuario.Guardar(Usuario('a', "pass", "root", Fecha(1, 1, 2000), 0, 0, 'F', "root", "root", "root"));
	}

	this->_cacheListadoUsuarios = this->listaUsuarios();
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
	delete[] _cacheListadoUsuarios;
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