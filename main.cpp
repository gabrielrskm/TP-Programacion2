#include <iostream>

#include "include/manager.h"
#include "include/ui-console.h"
#include "include/menu.h"


int main() {
   Manager manager;
   UiConsole ui;
   Menu menu;

   // Configura la consola para poder utilizar caracteres UTF-8
   ui.configurarConsola();
   ui.limpiarConsola();

   //login
   if (!menu.menuLogin(manager, ui)) {
      return 0;
   }

   ui.setUsuario(manager.getNombreUsuario());
   menu.menuPrincipal(manager, ui);

   return 0;
}
