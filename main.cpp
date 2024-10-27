#include <iostream>

#include "include/manager.h"
#include "include/ui-console.h"

bool login(Manager &manager, UiConsole &ui) {
   std::string user, pass;
   int intentos = 4;
   bool res1, res2;
   while (intentos >= 0) {

      res1 = ui.login(user, pass);
      if (res1) {
         res2 = manager.login(user, pass);
         if (res2) {
            return true;
         }
      }
      std::cout << "Usuario o contrasena incorrectos" << std::endl;
      std::cout << "Intentos restantes: " << intentos << std::endl << std::endl;
      intentos--;
   };
   return false;
}

void menuInsumo(Manager &manager, UiConsole &ui) {
   int op;
   do {
      op = ui.menuUsuarios();
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
         case 0:
            break;
         default:
            ui.opcionIncorrecta();
            break;
      }

   } while (op);
}

void menuProductos(Manager &manager, UiConsole &ui) {
   int op;
   do {
      op = ui.menuUsuarios();
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
         case 0:
            break;
         default:
            ui.opcionIncorrecta();
            break;
      }

   } while (op);
}

void menuProveedores(Manager &manager, UiConsole &ui) {
   int op;
   do {
      op = ui.menuUsuarios();
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

void menuClientes(Manager &manager, UiConsole &ui) {
   int op;
   do {
      op = ui.menuUsuarios();
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

void menuProduccion(Manager &manager, UiConsole &ui) {
   int op;
   do {
      op = ui.menuUsuarios();
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

void menuVentas(Manager &manager, UiConsole &ui) {
   int op;
   do {
      op = ui.menuUsuarios();
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

void menuUsuarios(Manager &manager, UiConsole &ui) {
   auto agregarUsuario = [&]() -> void {
      ui.limpiarConsola();
      bool op = true;
      std::string nombreUsuario;
      do
      {
         std::cout << "Ingrese el nombre del usuario: ";
         std::getline(std::cin, nombreUsuario);
         if(manager.buscarUsuario(nombreUsuario) < 0){
            Usuario us = ui.agregarUsuario(nombreUsuario);
            bool res = manager.agregarUsuario(us);
            if(res)
            {
               std::cout << "El usuario se agrego correctamente" << std::endl;
            }
            else {
               std::cout << "El usuario no se pudo agregar" << std::endl;
            }
            op = false;
         }
         else{
            std::cout << "El usuario ya existe" << std::endl;
            op = true;
         }
      }while (op);
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
   auto roles = [&]() -> void {

   };
   auto bloquearDesbloquear = [&]() -> void {

   };

   auto listarUsuarios = [&]() -> void {
      ui.limpiarConsola();
      Usuario *vector = manager.listaUsuarios();
      if(vector == nullptr){
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
      op = ui.menuUsuarios();
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
            roles();
            break;
         case 6:
            bloquearDesbloquear();
            break;
         case 7:
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

void menuEstadisticas(Manager &manager, UiConsole &ui) {
   int op;
   do {
      op = ui.menuUsuarios();
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

void menuSeguridad(Manager &manager, UiConsole &ui) {
   int op;
   do {
      op = ui.menuUsuarios();
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

int main() {
   Manager manager;
   UiConsole ui;
   // Configura la consola para poder utilizar caracteres UTF-8
   ui.configurarConsola();

   std::string user;
   if (!login(manager, ui)) {
      return 0;
   }
   ui.setUsuario(manager.getNombreUsuario());
   int op;
   do {
      op = ui.menuPrincipal();
      switch (op) {
         case 1:
            menuInsumo(manager, ui);
            break;
         case 2:
            menuProductos(manager, ui);
            break;
         case 3:
            menuProveedores(manager, ui);
            break;
         case 4:
            menuClientes(manager, ui);
            break;
         case 5:
            menuProduccion(manager, ui);
            break;
         case 6:
            menuVentas(manager, ui);
            break;
         case 7:
            menuUsuarios(manager, ui);
            break;
         case 8:
            menuEstadisticas(manager, ui);
            break;
         case 9:
            menuSeguridad(manager, ui);
            break;
         case 0:
            break;
         default:
            ui.opcionIncorrecta();
            break;
      }
   } while (op != 0);

   return 0;
}
