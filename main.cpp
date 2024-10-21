#include <iostream>

#include "manager.h"
#include "ui-console.h"

using namespace std;

bool login(Manager &manager, UiConsole &ui) {
   std::string user, pass;
   int intentos = 4;
   bool res1,res2;
   while (intentos >= 0) {

      res1 = ui.login(user, pass);
      if(res1) {
         res2 = manager.login(user, pass);
         if(res2) {
            return true;
         }
      }
      std::cout  << "Usuario o contrasena incorrectos" << std::endl;
      std::cout  << "Intentos restantes: " << intentos << std::endl<<std::endl;
      intentos--;
   };
   return false;
}

void menuGestionInsumo(Manager &manager, UiConsole &ui) {
}
void menuGestionProductos(Manager &manager, UiConsole &ui) {
}

void menuGestionProduccion(Manager &manager, UiConsole &ui) {
}

void menuRemitos(Manager &manager, UiConsole &ui) {
}

void menuDevoluciones(Manager &manager, UiConsole &ui) {
}

void menuLog(Manager &manager, UiConsole &ui) {
}

void menuGestionUsuarios(Manager &manager, UiConsole &ui) {
}


int main() {
   Manager manager;
   UiConsole ui;
   std::string user;
   if (!login(manager, ui)) {
      return 0;
   }
   int op = 10;
   do {
      op = ui.menuPrincipal();
      switch (op) {
         case 1:
            menuGestionInsumo(manager, ui);
            break;
         case 2:
            menuGestionProductos(manager, ui);
            break;
         case 3:
            menuGestionProduccion(manager, ui);
            break;
         case 4:
            menuRemitos(manager, ui);
            break;
         case 5:
            menuDevoluciones(manager, ui);
            break;
         case 6:
            menuLog(manager, ui);
            break;
         case 7:
            menuLog(manager, ui);
            break;
         case 8:
            menuGestionUsuarios(manager, ui);
         default:
            break;
      }
   } while (op != 0);

   return 0;
}
