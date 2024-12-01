#include "../include/menu.h"

#include <string>

#include "../include/manager.h"
#include "../include/ui-console.h"
#include "../include/usuario.h"

void Menu::menuPrincipal(Manager& manager, UiConsole& ui) {
   int op;
   do {
      op = ui.mostrarMenuPrincipal();
      switch (op) {
         case 1:
            this->menuInsumo(manager, ui);
            break;
         case 2:
            this->menuProductos(manager, ui);
            break;
         case 3:
            this->menuProveedores(manager, ui);
            break;
         case 4:
            this->menuClientes(manager, ui);
            break;
         case 5:
            this->menuProduccion(manager, ui);
            break;
         case 6:
            this->menuVentas(manager, ui);
            break;
         case 7:
            this->menuUsuarios(manager, ui);
            break;
         case 8:
            this->menuEstadisticas(manager, ui);
            break;
         case 9:
            this->menuSeguridad(manager, ui);
            break;
         case 0:
            break;
         default:
            ui.opcionIncorrecta();
            break;
      }
   } while (op != 0);
}

bool Menu::menuLogin(Manager& manager, UiConsole& ui) {
   std::string user, pass;
   int intentos = 5;
   bool usuarioYPassValidos, credencialesCorrectas;
   while (intentos > 0) {
      ui.mostrarMenuLogin(user, pass, intentos);
      usuarioYPassValidos = Usuario::validarUsuarioYPass(user, pass);
      if (usuarioYPassValidos) {
         credencialesCorrectas = manager.login(user, pass);
         if (credencialesCorrectas) {
            return true;
         }
      }
      intentos--;
   };
   return false;
}
void Menu::menuProductos(Manager& manager, UiConsole& ui) {
   auto agregarProducto = [&]() -> void {
      ui.limpiarConsola();
      if (!manager.esAdmin()) {
         std::cout << "No tiene permisos para dar de alta un nuevo producto" << std::endl;
         ui.pausa();
         return;
      }
      std::string codigoInsumo = ui.pedirCodigo();
      if (codigoInsumo == "") {
         ui.pausa();
         return;
      }
      int pos = manager.buscarProducto(codigoInsumo);
      if (pos >= 0) {
         std::cout << "El Producto ya existe" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -3) {
         std::cout << "El codigo se esta usando como insumo" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -2) {
         std::cout << "El codigo esta mal escrito y no cumple con los criterios" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -4) {
         std::cout << "El producto esta borrado" << std::endl;
         ui.pausa();
         return;
      }
      Recurso producto = ui.agregarRecurso(codigoInsumo, true);
      if (producto.getCodigo() == "") {
         ui.pausa();
         return;
      }
      if (manager.agregarProducto(producto) >= 0) {
         std::cout << "Producto dado de alta correctamente" << std::endl;

      } else {
         std::cout << "El producto no se pudo dar de alta" << std::endl;
      }
      ui.pausa();
      return;
   };
   auto borrarProducto = [&]() -> void {
      ui.limpiarConsola();
      if (!manager.esAdmin()) {
         std::cout << "No tiene permisos para borrar productos" << std::endl;
         ui.pausa();
         return;
      }
      std::string codigoProducto = ui.pedirCodigo();
      if (codigoProducto == "") {
         ui.pausa();
         return;
      }
      int pos = manager.buscarProducto(codigoProducto);
      if (pos == -3) {
         std::cout << "El codigo se esta usando como insumo" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -2) {
         std::cout << "El codigo esta mal escrito y no cumple con los criterios" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -4) {
         std::cout << "El producto ya esta borrado" << std::endl;
         ui.pausa();
         return;
      }
      if (pos < 0) {
         std::cout << "El producto no existe" << std::endl;
         ui.pausa();
         return;
      }
      if (manager.borrarProducto(pos)) {
         std::cout << "El recurso se borro correctamente" << std::endl;

      } else {
         std::cout << "No se pudo borrar el recurso" << std::endl;
      }
      ui.pausa();
      return;
   };
   auto modificarProducto = [&]() -> void {
      ui.limpiarConsola();
      if (!manager.esAdmin()) {
         std::cout << "No tiene permisos para modificar productos" << std::endl;
         ui.pausa();
         return;
      }
      std::string codigo = ui.pedirCodigo();
      if (codigo == "") {
         std::cout << "codigo incorrecto" << std::endl;
         ui.pausa();
         return;
      }
      int pos = manager.buscarProducto(codigo);
      if (pos == -3) {
         std::cout << "El codigo se esta usando como insumo" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -2) {
         std::cout << "El codigo esta mal escrito y no cumple con los criterios" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -4) {
         std::cout << "El producto esta borrado" << std::endl;
         ui.pausa();
         return;
      }
      if (pos < 0) {
         std::cout << "El producto no existe" << std::endl;
         ui.pausa();
         return;
      }
      Recurso* producto = new Recurso(manager.getRecurso(pos));
      if (producto == nullptr) {
         std::cout << "no hay memoria disponible" << std::endl;
         ui.pausa();
         return;
      }
      std::cout << "Valor actual del producto : " << std::endl;
      ui.mostrarRecursos(producto, 1);
      delete producto;
      std::cout << "Valor nuevo del producto : " << std::endl;
      Recurso productoModificado = ui.agregarRecurso(codigo, false);
      productoModificado.setOrigen(true);
      if (manager.modificarInsumo(productoModificado, pos)) {
         std::cout << "Producto modificado correctamente" << std::endl;
      } else {
         std::cout << "No se pudo modificar el Producto" << std::endl;
      }
      ui.pausa();
      return;
   };
   auto stockProducto = [&]() -> void {
      ui.limpiarConsola();
      std::string codigoProducto = ui.pedirCodigo();
      if (codigoProducto == "") {
         ui.pausa();
         return;
      }
      int pos = manager.buscarProducto(codigoProducto);
      if (pos == -3) {
         std::cout << "El codigo se esta usando como insumo" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -2) {
         std::cout << "El codigo esta mal escrito y no cumple con los criterios" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -4) {
         std::cout << "El producto esta borrado" << std::endl;
         ui.pausa();
         return;
      }
      if (pos < 0) {
         std::cout << "El producto no existe" << std::endl;
         ui.pausa();
         return;
      }
      Recurso* producto = new Recurso(manager.getRecurso(pos));
      if (producto == nullptr) {
         std::cout << "no hay memoria disponible" << std::endl;
         ui.pausa();
         return;
      }
      ui.mostrarRecursos(producto, 1);
      delete producto;
      int stock = ui.stockRecurso();
      if (stock < 0) {
         ui.pausa();
         return;
      }
      if (!manager.esAdmin()) {
         ui.pausa();
         return;
      }
      if (manager.modificarStockInsumo(stock, pos)) {
         std::cout << "Stock modificado correctamente" << std::endl;
      } else {
         std::cout << "No se pudo modificar el stock" << std::endl;
      }
      ui.pausa();
      return;
   };
   auto listaProductos = [&]() -> void {
      ui.limpiarConsola();
      int cantidad = 0;
      Recurso* productos = nullptr;
      if (!manager.listaRecursos(0, 0, true, false, productos, cantidad)) {
         std::cout << "No hay Productos" << std::endl;
         ui.pausa();
         return;
      }
      ui.mostrarRecursos(productos, cantidad);
      delete[] productos;
      ui.pausa();
      return;
   };
   auto buscarProducto = [&]() -> void {
      ui.limpiarConsola();
      std::string codigoProducto = ui.pedirCodigo();
      if (codigoProducto == "") {
         ui.pausa();
         return;
      }
      int pos = manager.buscarProducto(codigoProducto);
      if (pos == -3) {
         std::cout << "El codigo se esta usando como insumo" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -2) {
         std::cout << "El codigo esta mal escrito y no cumple con los criterios" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -4) {
         std::cout << "El producto esta borrado" << std::endl;
         ui.pausa();
         return;
      }
      if (pos < 0) {
         std::cout << "El producto no existe" << std::endl;
         ui.pausa();
         return;
      }
      Recurso* producto = new Recurso(manager.getRecurso(pos));
      if (producto == nullptr) {
         std::cout << "no hay memoria disponible" << std::endl;
         ui.pausa();
         return;
      }
      ui.mostrarRecursos(producto, 1);
      delete producto;
      ui.pausa();
      return;
   };
   auto verComposicion = [&]() -> void {
      ui.limpiarConsola();
      std::string codigoProducto = ui.pedirCodigo();
      if (codigoProducto == "") {
         ui.pausa();
         return;
      }
      int pos = manager.buscarProducto(codigoProducto);
      if (pos == -3) {
         std::cout << "El codigo se esta usando como insumo" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -2) {
         std::cout << "El codigo esta mal escrito y no cumple con los criterios" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -4) {
         std::cout << "El producto esta borrado" << std::endl;
         ui.pausa();
         return;
      }
      if (pos < 0) {
         std::cout << "El producto no existe" << std::endl;
         ui.pausa();
         return;
      }
      Recurso* producto = new Recurso(manager.getRecurso(pos));
      if (producto == nullptr) {
         std::cout << "no hay memoria disponible" << std::endl;
         ui.pausa();
         return;
      }
      int cantidadInsumos = 0;
      Recurso* insumos = nullptr;
      int* vectorComposicion = nullptr;
      if (manager.getComposicionProducto(pos, insumos, cantidadInsumos, vectorComposicion,codigoProducto)) {
         ui.mostrarComposicion(insumos, cantidadInsumos, producto,vectorComposicion);
         delete[] insumos;
      } else {
         std::cout << "No hay composicion" << std::endl;
      }
      delete producto;
      ui.pausa();
   };
   auto editarCoposicion = [&]() -> void {
      ui.limpiarConsola();
      std::string codigoProducto = ui.pedirCodigo();
      if (codigoProducto == "") {
         ui.pausa();
         return;
      }
      int pos = manager.buscarProducto(codigoProducto);
      if (pos == -3) {
         std::cout << "El codigo se esta usando como insumo" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -2) {
         std::cout << "El codigo esta mal escrito y no cumple con los criterios" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -4) {
         std::cout << "El producto esta borrado" << std::endl;
         ui.pausa();
         return;
      }
      if (pos < 0) {
         std::cout << "El producto no existe" << std::endl;
         ui.pausa();
         return;
      }

      bool result = true;
      std::string codigoInsumo;
      while (result) {
         ui.limpiarConsola();
         //muestra la composicion actual
         Recurso* producto = new Recurso(manager.getRecurso(pos));
         if (producto == nullptr) {
            std::cout << "no hay memoria disponible" << std::endl;
            ui.pausa();
            return;
         }
         int cantidadInsumos = 0;
         Recurso* insumos = nullptr;
         int* vectorComposicion = nullptr;
         if (manager.getComposicionProducto(pos, insumos, cantidadInsumos,vectorComposicion, codigoProducto)) {
            ui.mostrarComposicion(insumos, cantidadInsumos, producto,vectorComposicion);
            delete[] insumos;
         } else {
            ui.mostrarRecursos(producto,1);
            std::cout << "No hay composicion aun" << std::endl << std::endl;
         }
         delete producto;
         //////////////////////////////////////////////////////////////////////////
         std::cout << "Ingrese el codigo del insumo ->" << std::endl << std::endl;
         std::string codigoInsumo = ui.pedirCodigo();
         if (codigoInsumo == "") {
            std::cout << "codigo incorrecto, desea continuar con otro insumo?";
         } else {
            int posInsumo = manager.buscarInsumo(codigoInsumo);
            if (posInsumo < 0) {
               std::cout << "El insumo no existe";
            } else {
               int cantidad;
               std::cout << "Ingrese la cantidad: ";
               if (!ui.pedirNumero(cantidad)) {
                  std::cout << "No se pudo agregar el insumo" << std::endl;
               } else if (manager.setComposicionProducto(codigoProducto, codigoInsumo, cantidad)) {
                  std::cout << "Insumo agregado correctamente" << std::endl;
               } else {
                  std::cout << "El insumo ya esta en la composicion y/o No se puede agregar" << std::endl;
               }
            }
         }
         std::cout << "desea continuar con otro insumo?" << std::endl;
         std::string op;
         std::getline(std::cin, op);
         if (op == "n" || op == "N") {
            result = false;
         } else if (op == "s" || op == "S") {
            result = true;
         } else {
            std::cout << "opcion incorrecta" << std::endl;
            ui.pausa();
            return;
         }
      }
      ui.pausa();
      return;
   };
   int op;
   do {
      op = ui.mostrarMenuProductos();
      switch (op) {
         case 1:
            agregarProducto();
            break;
         case 2:
            borrarProducto();
            break;
         case 3:
            modificarProducto();
            break;
         case 4:
            stockProducto();
            break;
         case 5:
            listaProductos();
            break;
         case 6:
            buscarProducto();
            break;
         case 7:
            verComposicion();
            break;
         case 8:
            editarCoposicion();
            break;
         case 0:
            break;
         default:
            ui.opcionIncorrecta();
            break;
      }

   } while (op);
}

void Menu::menuInsumo(Manager& manager, UiConsole& ui) {
   auto agregarInsumo = [&]() -> void {
      if (!manager.esAdmin()) {
         std::cout << "No tiene permisos para dar de alta un nuevo insumo" << std::endl;
         ui.pausa();
         return;
      }
      ui.limpiarConsola();
      std::string codigoInsumo = ui.pedirCodigo();
      if (codigoInsumo == "") {
         ui.pausa();
         return;
      }
      int pos = manager.buscarInsumo(codigoInsumo);
      if (pos >= 0) {
         std::cout << "El insumo ya existe" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -3) {
         std::cout << "El codigo se esta usando como producto" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -4) {
         std::cout << "El codigo del insumo esta borrado" << std::endl;
         ui.pausa();
         return;
      }
      Recurso insumo = ui.agregarRecurso(codigoInsumo, true);
      if (insumo.getCodigo() == "") {
         ui.pausa();
         return;
      }
      if (manager.agregarInsumo(insumo) >= 0) {
         std::cout << "Insumo dado de alta correctamente" << std::endl;

      } else {
         std::cout << "El insumo no se pudo dar de alta" << std::endl;
      }
      ui.pausa();
      return;
   };
   auto borraInsumo = [&]() -> void {
      ui.limpiarConsola();
      if (!manager.esAdmin()) {
         std::cout << "No tiene permisos para borrar insumos" << std::endl;
         ui.pausa();
         return;
      }
      std::string codigoInsumo = ui.pedirCodigo();
      if (codigoInsumo == "") {
         ui.pausa();
         return;
      }
      int pos = manager.buscarInsumo(codigoInsumo);
      if (pos < 0) {
         std::cout << "El insumo no existe" << std::endl;
         ui.pausa();
         return;
      }
      if (manager.borrarInsumo(pos)) {
         std::cout << "Insumo se borro correctamente" << std::endl;

      } else {
         std::cout << "No se pudo borrar el insumo" << std::endl;
      }
      ui.pausa();
      return;
   };
   auto listaInsumos = [&]() -> void {
      ui.limpiarConsola();
      int cantidad = 0;
      Recurso* insumos = nullptr;
      if (!manager.listaRecursos(0, 0, false, false, insumos, cantidad)) {
         std::cout << "No hay insumos" << std::endl;
         ui.pausa();
         return;
      }
      ui.mostrarRecursos(insumos, cantidad);
      delete[] insumos;
      ui.pausa();
      return;
   };
   auto modificarInsumo = [&]() -> void {
      ui.limpiarConsola();
      if (!manager.esAdmin()) {
         std::cout << "No tiene permisos para modificar insumos" << std::endl;
         ui.pausa();
         return;
      }
      std::string codigo = ui.pedirCodigo();
      if (codigo == "") {
         std::cout << "codigo incorrecto" << std::endl;
         ui.pausa();
         return;
      }
      int pos = manager.buscarInsumo(codigo);
      if (pos == -4) {
         std::cout << "El codigo del insumo esta borrado" << std::endl;
         ui.pausa();
         return;
      }
      if (pos < 0) {
         std::cout << "El insumo no existe" << std::endl;
         ui.pausa();
         return;
      }
      Recurso* insumo = new Recurso(manager.getRecurso(pos));
      if (insumo == nullptr) {
         std::cout << "no hay memoria disponible" << std::endl;
         ui.pausa();
         return;
      }
      std::cout << "Valor actual del insumo : " << std::endl;
      ui.mostrarRecursos(insumo, 1);
      delete insumo;
      std::cout << "Valor nuevo del insumo : " << std::endl;
      Recurso insumoModificado = ui.agregarRecurso(codigo, true);
      if (manager.modificarInsumo(insumoModificado, pos)) {
         std::cout << "Insumo modificado correctamente" << std::endl;
      } else {
         std::cout << "No se pudo modificar el insumo" << std::endl;
      }
      ui.pausa();
      return;
   };
   auto buscarInsumo = [&]() -> void {
      ui.limpiarConsola();
      std::string codigoInsumo = ui.pedirCodigo();
      if (codigoInsumo == "") {
         ui.pausa();
         return;
      }
      int pos = manager.buscarInsumo(codigoInsumo);
      if (pos < 0) {
         std::cout << "El insumo no existe" << std::endl;
         ui.pausa();
         return;
      }
      Recurso* insumo = new Recurso(manager.getRecurso(pos));
      if (insumo == nullptr) {
         std::cout << "no hay memoria disponible" << std::endl;
         ui.pausa();
         return;
      }
      ui.mostrarRecursos(insumo, 1);
      delete insumo;
      ui.pausa();
      return;
   };
   auto stock = [&]() -> void {
      ui.limpiarConsola();
      std::string codigoInsumo = ui.pedirCodigo();
      if (codigoInsumo == "") {
         ui.pausa();
         return;
      }
      int pos = manager.buscarInsumo(codigoInsumo);
      if (pos < 0) {
         std::cout << "El insumo no existe" << std::endl;
         ui.pausa();
         return;
      }
      Recurso* insumo = new Recurso(manager.getRecurso(pos));
      if (insumo == nullptr) {
         std::cout << "no hay memoria disponible" << std::endl;
         ui.pausa();
         return;
      }
      ui.mostrarRecursos(insumo, 1);
      delete insumo;
      int stock = ui.stockRecurso();
      if (stock < 0) {
         ui.pausa();
         return;
      }
      if (!manager.esAdmin()) {
         ui.pausa();
         return;
      }
      if (manager.modificarStockInsumo(stock, pos)) {
         std::cout << "Stock modificado correctamente" << std::endl;
      } else {
         std::cout << "No se pudo modificar el stock" << std::endl;
      }
      ui.pausa();
      return;
   };
   int op;
   do {
      op = ui.mostrarMenuInsumos();
      switch (op) {
         case 1:
            agregarInsumo();
            break;
         case 2:
            borraInsumo();
            break;
         case 3:  //
            modificarInsumo();
            break;
         case 4:
            stock();
            break;
         case 5:
            listaInsumos();
            break;
         case 6:
            buscarInsumo();
            break;
         case 0:
            break;
         default:
            ui.opcionIncorrecta();
            break;
      }

   } while (op);
}
void Menu::menuProveedores(Manager& manager, UiConsole& ui) {
   int op;
   do {
      op = ui.mostrarMenuProveedores();
      switch (op) {
         case 1:
            break;
         case 2:
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
            break;
         case 6:
            break;
         case 7:
            break;
         case 0:
            break;
         default:
            ui.opcionIncorrecta();
            break;
      }

   } while (op);
}

void Menu::menuClientes(Manager& manager, UiConsole& ui) {
   int op;
   do {
      op = ui.mostrarMenuClientes();
      switch (op) {
         case 1:
            break;
         case 2:
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
            break;
         case 0:
            break;
         default:
            ui.opcionIncorrecta();
            break;
      }

   } while (op);
}

void Menu::menuProduccion(Manager& manager, UiConsole& ui) {
   auto generarProduccion = [&]() -> void {
      ui.limpiarConsola();
      if (!manager.esAdmin()) {
         std::cout << "No tiene permisos para generar ordenes de produccion" << std::endl;
         ui.pausa();
         return;
      }
      std::string codigoProducto = ui.pedirCodigo();
      if (codigoProducto == "") {
         ui.pausa();
         return;
      }
      int pos = manager.buscarProducto(codigoProducto);
      if (pos == -1) {
         std::cout << "El Producto no existe" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -3) {
         std::cout << "El codigo se esta usando como insumo" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -2) {
         std::cout << "El codigo esta mal escrito y no cumple con los criterios" << std::endl;
         ui.pausa();
         return;
      }
      if (pos == -4) {
         std::cout << "El producto esta borrado" << std::endl;
         ui.pausa();
         return;
      }
      std::cout << std::endl;
      std::cout << "Indique la cantidad a producir : ";
      int cantidad;
      if(!ui.pedirNumero(cantidad)){
         ui.pausa();
         return;
      }

      if (manager.agregarOrdenProduccion(codigoProducto, cantidad)>=0) {
         std::cout << "Orden de produccion generada correctamente" << std::endl;
      } else {
         std::cout << "No se pudo generar la orden de produccion" << std::endl;
      }
      ui.pausa();
      return;


   };
   auto modificarEstado = [&]() -> void {
      ui.limpiarConsola();
      std::cout << "Ingrese el codigo de la orden de produccion a modificar: ";
      int codigo;
      if(!ui.pedirNumero(codigo)){
         std::cout << "Numero invalido" << std::endl;
         ui.pausa();
         return;
      }
      if(manager.buscarOrdenProduccion(codigo)<0){
         std::cout << "La orden de produccion no existe" << std::endl;
         ui.pausa();
         return;
      }

      std::cout << "Ingrese el nuevo estado de la orden de produccion: ";
      std::string estado;
      std::getline(std::cin, estado);
      if(estado != "C" && estado != "c" && estado != "T" && estado != "t" && estado != "terminado" && estado != "cancelado"){
         std::cout << "Estado invalido" << std::endl;
         ui.pausa();
         return;
      }
      if (manager.modificarEstadoProduccion(codigo, estado)) {
         std::cout << "Orden de produccion modificada correctamente" << std::endl;
      } else {
         std::cout << "No se pudo modificar la orden de produccion" << std::endl;
      }
      ui.pausa();
      return;
   };
   auto historialProduccion = [&]() -> void {
      ui.limpiarConsola();
      OrdenProduccion* ordenes = nullptr;
      int sizeComp = 0;
      manager.historialProduccion(ordenes, sizeComp);
      if (sizeComp == 0) {
         std::cout << "No hay ordenes de produccion" << std::endl;
         ui.pausa();
         return;
      }
      ui.mostrarProduccion(ordenes, sizeComp);
      delete[] ordenes;
      ui.pausa();
      return;
   };
   int op;
   do {
      op = ui.mostrarMenuProduccion();
      switch (op) {
         case 1:
            generarProduccion();
            break;
         case 2:
            modificarEstado();
            break;
         case 3:
            historialProduccion();
            break;
         case 0:
            break;
         default:
            ui.opcionIncorrecta();
            break;
      }

   } while (op);
}

void Menu::menuVentas(Manager& manager, UiConsole& ui) {
   int op;
   do {
      op = ui.mostrarMenuVentas();
      switch (op) {
         case 1:
            break;
         case 2:
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
            break;
         case 0:
            break;
         default:
            ui.opcionIncorrecta();
            break;
      }

   } while (op);
}

void Menu::menuUsuarios(Manager& manager, UiConsole& ui) {
   auto agregarUsuario = [&]() -> void {
      ui.limpiarConsola();
      if (!manager.getPrivilegios()) {
         std::cout << UiConsole::ROJO << "No tiene privilegios para realizar esta acci�n." << UiConsole::RESET
                   << std::endl;
         ui.pausa();
         return;
      }
      bool agregandoUsuario = true;
      std::string nombreUsuario;
      do {
         std::cout << "Ingrese el nombre del usuario: ";
         std::getline(std::cin, nombreUsuario);
         if (manager.buscarUsuario(nombreUsuario, true) >= 0) {
            std::cout << UiConsole::ROJO << "El nombre de usuario " << UiConsole::VERDE << "'" << nombreUsuario << "'"
                      << UiConsole::ROJO << " ya existe. Ingrese otro." << UiConsole::RESET << std::endl
                      << std::endl;
            continue;
         }

         if (nombreUsuario.length() < 4) {
            std::cout << UiConsole::ROJO << "El nombre de usuario debe tener al menos 4 caracteres" << UiConsole::RESET
                      << std::endl
                      << std::endl;
         } else {
            Usuario usuario = ui.agregarUsuario(nombreUsuario, manager);
            bool agregadoCorrectamente = manager.agregarUsuario(usuario);
            if (agregadoCorrectamente) {
               manager.actualizarCacheUsuarios();
               std::cout << "El usuario se agrego correctamente" << std::endl;
            } else {
               std::cout << "El usuario no se pudo agregar" << std::endl;
            }
            agregandoUsuario = false;
         }
      } while (agregandoUsuario);

      ui.pausa();
      return;
   };

   auto modificarUsuario = [&]() -> void {
      ui.limpiarConsola();
      if (!manager.getPrivilegios()) {
         std::cout << UiConsole::ROJO << "No tiene privilegios para modificar un usuario." << UiConsole::RESET
                   << std::endl;
         ui.pausa();
         return;
      }

      std::string nombreUsuario;
      bool modificandoUsuario = true;
      do {
         std::cout << "Ingrese el nombre del usuario a modificar: ";
         std::getline(std::cin, nombreUsuario);

         int posicionUsuario = manager.buscarUsuario(nombreUsuario, true);

         if (posicionUsuario < 0) {
            std::cout << UiConsole::ROJO << "El usuario" << UiConsole::VERDE << "'" << nombreUsuario << "'"
                      << UiConsole::ROJO << " no existe. Ingrese nuevamente un usuario." << UiConsole::RESET
                      << std::endl;
            continue;
         } else {
            Usuario usuario = manager.leerUsuario(posicionUsuario);


            int opcion = ui.mostrarMenuModificacionUsuario();

            switch (opcion) {
               case 1:
               case 2:
               case 3:
               case 4:
               case 5:
               case 6:
               case 7:
               case 0:
               default: {
               }
            }
         }

      } while (modificandoUsuario);

      // ui.limpiarConsola();
      // ui.pausa();
      // return;
   };
   auto eliminarUsuario = [&]() -> void {
      ui.limpiarConsola();

      if (!manager.getPrivilegios()) {
         std::cout << UiConsole::ROJO << "No tiene privilegios para eliminar un usuario." << UiConsole::RESET
                   << std::endl;
         ui.pausa();
         return;
      }

      std::string nombreUsuario;
      bool eliminandoUsuario = true;
      do {
         std::cout << "Ingrese el nombre del usuario a eliminar: ";
         std::getline(std::cin, nombreUsuario);

         int posicionUsuario = manager.buscarUsuario(nombreUsuario, true);
         

         if (posicionUsuario < 0) {
            std::cout << UiConsole::ROJO << "El usuario" << UiConsole::VERDE << "'" << nombreUsuario << "'"
                      << UiConsole::ROJO << " no existe. Ingrese nuevamente un usuario." << UiConsole::RESET
                      << std::endl;
            continue;
         } else {
            Usuario usuario = manager.leerUsuario(posicionUsuario);
            usuario.setEstadoUsuario(false);

            std::cout << UiConsole::ROJO << "�Est� seguro que desea eliminar el usuario " << UiConsole::BOLD
                      << UiConsole::VERDE << "'" << nombreUsuario << "'" << UiConsole::ROJO << "?" << UiConsole::RESET
                      << "(Y/N)" << std::endl;

            bool opcionCorrecta = false;
            char option;
            std::cin >> option;

            while (!opcionCorrecta) {
               switch (option) {
                  case 'y':
                  case 'Y': {
                     std::cout << "Se eliminara el usuario.";
                     opcionCorrecta = true;
                     manager.reescribirUsuario(usuario, posicionUsuario);
                     manager.actualizarCacheUsuarios();
                     break;
                  }
                  case 'n':
                  case 'N': {
                     std::cout << "No se eliminara el usuario.";
                     opcionCorrecta = true;
                     break;
                  }
                     {
                        default: {
                           std::cout
                               << UiConsole::ROJO
                               << "La opcion seleccionada es incorrecta. Ingrese 'Y' para eliminar o 'N' para cancelar."
                               << UiConsole::RESET << std::endl;
                           std::cin >> option;
                        } break;
                     }
               }
            }
         }
         eliminandoUsuario = false;
      } while (eliminandoUsuario);


      ui.limpiarConsola();
      ui.pausa();
      return;
   };
   auto modificarContraseniaRoot = [&]() -> void {
      if (!manager.getPrivilegios()) {
         std::cout << UiConsole::ROJO << "No tiene privilegios para modificar la contrase�a root." << UiConsole::RESET
                   << std::endl;
         ui.pausa();
         return;
      }

      // manager.buscarUsuario("root");
   };

   auto listarUsuarios = [&]() -> void {
      ui.limpiarConsola();

      Usuario* vectorUsuarios = manager.getCacheListadoUsuarios();
      if (!manager.getPrivilegios()) {
         std::cout << UiConsole::ROJO << "No tiene privilegios para ver el listado de usuarios." << UiConsole::RESET
                   << std::endl;
         ui.pausa();
         return;
      }

      if (vectorUsuarios == nullptr) {
         std::cout << "Error al cargar el listado de usuarios." << std::endl;
         ui.pausa();
         return;
      }

      int cantidad = manager.cantidadUsuarios();


      std::cout << R"(
+---------------------+---------------------+------------------------------------+---------------------+
|      Usuario        |        Rol          |               Email                |      Telefono       |
+---------------------+---------------------+------------------------------------+---------------------+)"
                << std::endl;

      for (int i = 0; i < cantidad; i++) {
         if (vectorUsuarios[i].getEstadoUsuario()) {
            ui.listarUsuario(vectorUsuarios[i].getNombreUsuario(), vectorUsuarios[i].getRol(),
                             vectorUsuarios[i].getEmail(), vectorUsuarios[i].getTelefono());
         }
      }

      std::cout << std::endl;

      ui.pausa();
      return;
   };

   int op;
   do {
      op = ui.mostrarMenuUsuarios();
      switch (op) {
         case 1:
            agregarUsuario();
            break;
         case 2:
            modificarUsuario();
            break;
         case 3:
            eliminarUsuario();
            break;
         case 4:
            modificarContraseniaRoot();
            break;
         case 5:
            listarUsuarios();
            break;
         case 0:
            break;
         default:
            ui.opcionIncorrecta();
            break;
      }

   } while (op);
}

void Menu::menuEstadisticas(Manager& manager, UiConsole& ui) {
   int op;
   do {
      op = ui.mostrarMenuEstadisticas();
      switch (op) {
         case 1:
            break;
         case 2:
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
            break;
         case 0:
            break;
         default:
            ui.opcionIncorrecta();
            break;
      }

   } while (op);
}

void Menu::menuSeguridad(Manager& manager, UiConsole& ui) {
   int op;
   do {
      op = ui.mostrarMenuSeguridad();
      switch (op) {
         case 1:
            break;
         case 2:
            break;
         case 0:
            break;
         default:
            ui.opcionIncorrecta();
            break;
      }

   } while (op);
}