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
      if(!manager.esAdmin()){
         std::cout << "No tiene permisos para dar de alta un nuevo producto" << std::endl;
         ui.pausa();
         return;
      }
      std::string codigoInsumo = ui.pedirInsumo();
      if (codigoInsumo == "") {
         ui.pausa();
         return;
      }
      if (manager.buscarInsumo(codigoInsumo) >= 0) {
         std::cout << "El Producto ya existe" << std::endl;
         ui.pausa();
         return;
      }
      Recurso insumo = ui.agregarInsumo(codigoInsumo);
      if (insumo.getCodigo() == "") {
         ui.pausa();
         return;
      }
      if (manager.agregarInsumo(insumo) >= 0) {
         std::cout << "Producto dado de alta correctamente" << std::endl;

      } else {
         std::cout << "El producto no se pudo dar de alta" << std::endl;
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
            break;
         case 3:
            break;
         case 4:
            break;
         case 5:
            break;
         case 6:
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
      if(!manager.esAdmin()){
         std::cout << "No tiene permisos para dar de alta un nuevo insumo" << std::endl;
         ui.pausa();
         return;
      }
      ui.limpiarConsola();
      std::string codigoInsumo = ui.pedirInsumo();
      if (codigoInsumo == "") {
         ui.pausa();
         return;
      }
      if (manager.buscarInsumo(codigoInsumo) >= 0) {
         std::cout << "El insumo ya existe" << std::endl;
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
      if(!manager.esAdmin()){
         std::cout << "No tiene permisos para borrar insumos" << std::endl;
         ui.pausa();
         return;
      }
      std::string codigoInsumo = ui.pedirInsumo();
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
      int cantidad = manager.cantidadInsumos();
      if (cantidad == 0) {
         std::cout << "No hay insumos" << std::endl;
         ui.pausa();
         return;
      }
      Recurso* insumos = manager.listaInsumos(cantidad);
      if (insumos == nullptr) {
         std::cout << "No hay insumos" << std::endl;
         ui.pausa();
         return;
      }
      ui.mostrarInsumos(insumos, cantidad);
      delete[] insumos;
      ui.pausa();
      return;
   };
   auto modificarInsumo = [&]() -> void {
      ui.limpiarConsola();
      if(!manager.esAdmin()){
         std::cout << "No tiene permisos para modificar insumos" << std::endl;
         ui.pausa();
         return;
      }
      std::string codigo = ui.pedirInsumo();
      if (codigo == "") {
         std::cout << "codigo incorrecto" << std::endl;
         ui.pausa();
         return;
      }
      int pos = manager.buscarInsumo(codigo);
      if (pos < 0) {
         std::cout << "El insumo no existe" << std::endl;
         ui.pausa();
         return;
      }
      Recurso* insumo = new Recurso(manager.getInsumo(pos));
      if (insumo == nullptr) {
         std::cout << "no hay memoria disponible" << std::endl;
         ui.pausa();
         return;
      }
      std::cout << "Valor actual del insumo : " << std::endl;
      ui.mostrarInsumos(insumo, 1);
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
      std::string codigoInsumo = ui.pedirInsumo();
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
      Recurso* insumo = new Recurso(manager.getInsumo(pos));
      if (insumo == nullptr) {
         std::cout << "no hay memoria disponible" << std::endl;
         ui.pausa();
         return;
      }
      ui.mostrarInsumos(insumo, 1);
      delete insumo;
      ui.pausa();
      return;
   };
   auto stock = [&]() -> void {
      ui.limpiarConsola();
      std::string codigoInsumo = ui.pedirInsumo();
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
      Recurso* insumo = new Recurso(manager.getInsumo(pos));
      if (insumo == nullptr) {
         std::cout << "no hay memoria disponible" << std::endl;
         ui.pausa();
         return;
      }
      ui.mostrarInsumos(insumo, 1);
      delete insumo;
      int stock = ui.stockInsumo();
      if(stock<0){
         ui.pausa();
         return;
      }
      if(!manager.esAdmin()){
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
