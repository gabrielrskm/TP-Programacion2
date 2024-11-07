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
   int intentos = 4;
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
      int pos = manager.buscarInsumo(codigoInsumo);
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
      Recurso insumo = ui.agregarInsumo(codigoInsumo);
      if (insumo.getCodigo() == "") {
         ui.pausa();
         return;
      }
      if (manager.agregarProducto(insumo) >= 0) {
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
      if (pos < 0) {
         std::cout << "El insumo no existe" << std::endl;
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
      if (pos < 0) {
         std::cout << "El Producto no existe" << std::endl;
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
      Recurso insumoModificado = ui.agregarInsumo(codigo);
      if (manager.modificarInsumo(insumoModificado, pos)) {
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
      if(!manager.listaRecursos(0,0,true,false,productos,cantidad)){
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
      int composicionSize = 0;
      ComposicionProducto *composicion = nullptr;
      if(manager.getComposicionProducto(pos, composicion,composicionSize,producto->getCodigo())){
         std::cout << "No hay composicion" << std::endl;
         delete producto;
         ui.pausa();
         return;
      }
      //ui.mostrarComposicion(producto);
      delete[] composicion;
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
      if (pos < 0) {
         std::cout << "El Producto no existe" << std::endl;
         ui.pausa();
         return;
      }
      //ui.editarComposicion(manager.getRecurso(pos));
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
      if(pos == -4) {
         std::cout << "El codigo del insumo esta borrado" << std::endl;
         ui.pausa();
         return;
      }
      Recurso insumo = ui.agregarInsumo(codigoInsumo);
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
      Recurso* productos = nullptr;
      if(!manager.listaRecursos(0,0,false,false,productos,cantidad)){
         std::cout << "No hay Productos" << std::endl;
         ui.pausa();
         return;
      }
      ui.mostrarRecursos(productos, cantidad);
      delete[] productos;
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
      if(pos == -4) {
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
      Recurso insumoModificado = ui.agregarInsumo(codigo);
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
   int op;
   do {
      op = ui.mostrarMenuProduccion();
      switch (op) {
         case 1:
            break;
         case 2:
            break;
         case 3:
            break;
         case 4:
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
      bool op = true;
      std::string nombreUsuario;
      do {
         std::cout << "Ingrese el nombre del usuario: ";
         std::getline(std::cin, nombreUsuario);
         if (manager.buscarUsuario(nombreUsuario) < 0 || nombreUsuario.length() > 0) {
            Usuario us = ui.agregarUsuario(nombreUsuario);
            bool res = manager.agregarUsuario(us);
            if (res) {
               std::cout << "El usuario se agrego correctamente" << std::endl;
            } else {
               std::cout << "El usuario no se pudo agregar" << std::endl;
            }
            op = false;
         } else {
            std::cout << "El usuario ya existe" << std::endl;
            op = true;
         }
      } while (op);
      ui.pausa();
      return;
   };
   auto modificarUsuario = [&]() -> void {
      ui.limpiarConsola();
      ui.pausa();
      return;
   };
   auto eliminarUsuario = [&]() -> void {
      ui.limpiarConsola();
      ui.pausa();
      return;
   };
   auto contraseniaRoot = [&]() -> void {

   };

   auto listarUsuarios = [&]() -> void {
      ui.limpiarConsola();
      Usuario* vector = manager.listaUsuarios();
      if (vector == nullptr) {
         std::cout << "Error al cargar" << std::endl;
         ui.pausa();
         return;
      }
      int cantidad = manager.cantidadUsuarios();
      for (int i = 0; i < cantidad; i++) {
         std::cout << vector[i].getNombreUsuario() << std::endl;
         ui.tipoUsuario(std::string(1, vector[i].getTipo()));
      }
      delete[] vector;
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
            contraseniaRoot();
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
