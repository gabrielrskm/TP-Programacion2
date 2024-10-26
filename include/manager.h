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
   bool login(std::string user, std::string pass);
   /* bool darDeAltaProducto(std::string codigo,std::string descripcion,
            std::string tipoMedicion, int futuro, bool origenInterno); */
   std::string getClientByName(std::string name);
   std::string getRecursoById(std::string id);

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
   char _tipoUsuario;
};