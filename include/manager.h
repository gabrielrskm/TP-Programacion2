#pragma once
#include <iostream>
#include "fecha.h"
#include "persona.h"
#include "recurso.h"
#include "cliente.h"
#include "proveedor.h"
#include "usuario.h"
#include "orden.h"
#include "orden-compra.h"
#include "orden-produccion.h"
#include "orden-venta.h"
#include "movimientos.h"
#include "factura.h"
#include "composicion-movimientos.h"
#include "composicion-orden.h"
#include "composicion-producto.h"
#include "composicion-factura.h"
#include "archivo-cliente.h"
#include "archivo-composicion-factura.h"
#include "archivo-composicion-movimiento.h"
#include "archivo-composicion-orden.h"
#include "archivo-composicion-producto.h"
#include "archivo-factura.h"
#include "archivo-movimientos.h"
#include "archivo-orden-compra.h"
#include "archivo-orden-produccion.h"
#include "archivo-orden-venta.h"
#include "archivo-proveedor.h"
#include "archivo-recursos.h"
#include "archivo-usuario.h"
#include "manager.h"



class Manager {

  public:
   Manager();
	~Manager();
   // Funcionalidades Usuario
   bool login(std::string user, std::string pass);
	bool agregarUsuario(Usuario usuario);
	Usuario* listaUsuarios();
	int cantidadUsuarios();
	std::string getNombreUsuario();
  int buscarUsuario(std::string nombreUsuario);
	int buscarUsuario(std::string nombreUsuario, bool buscarEnCache);
	Usuario leerUsuario(int posicion);
	bool reescribirUsuario(Usuario usuario, int posicion); 
	int buscarEmail(std::string email, bool buscarEnCache);
	int buscarTelefono(std::string telefono, bool buscarEnCache);
	bool getPrivilegios();
	void actualizarCacheUsuarios();
	int buscar(std::string busqueda, int tipoDeBusqueda);
	Usuario* getCacheListadoUsuarios(); 
  bool esAdmin();
   bool esComprador();
   bool esVendedor();

  //funcionalidades insumos
   int buscarInsumo(std::string codigo);
   int agregarInsumo(Recurso insumo);
   bool borrarInsumo(int pos);
   bool estaBorrado(int pos);
   bool modificarInsumo(Recurso insumo, int pos);
   bool modificarStockInsumo(int stock, int pos);

   Recurso getRecurso(int pos);
   bool listaRecursos(int pos,int cantidad,bool isProducto,bool borrado,Recurso*& vector,int& vectorSize);
   //funcionalidades productos
   int buscarProducto(std::string codigo);
   int agregarProducto(Recurso producto);
   bool borrarProducto(int pos);
   bool modificarStockRecurso(int stock, int pos);
   bool getComposicionProducto(int pos,Recurso*& vector,int& composicionSize,std::string codigo);
   bool setComposicionProducto(std::string idProducto, std::string idInsumo, int cantidad);
 

private:
	ArchivoCliente archivoCliente;
	ArchivoComposicionFactura archivoComposicionFactura;
	ArchivoComposicionMovimientos archivoComposicionMovimientos;
	ArchivoComposicionOrden archivoComposicionOrden;
	ArchivoComposicionProducto archivoComposicionProducto;
	ArchivoFactura archivoFactura;
	ArchivoMovimientos archivoMovimientos;
	ArchivoOrdenCompra archivoOrdenCompra;
	ArchivoOrdenProduccion archivoOrdenProduccion;
	ArchivoOrdenVenta archivoOrdenVenta;
	ArchivoProveedor archivoProveedor;
	ArchivoRecurso archivoRecurso;
	ArchivoUsuario archivoUsuario;
	char _rolUsuario;
	bool _tienePrivilegios;
	std::string _nombreUsuario;
	Usuario* _cacheListadoUsuarios;
	Usuario _usuarioLoggeado; 
};