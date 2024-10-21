#include "ui-console.h"

const char *MENU_PRINCIPAL = R"(
----------------------------------
SISTEMA DE GESTIÓN DE PRODUCCIÓN
----------------------------------

1. Gestión de Insumos
2. Gestión de Productos
3. Órdenes de Producción
4. Remitos y Facturación
5. Devoluciones
6. Proveedores
7. Logs de Actividades
8. Gestion de usuarios
0. Salir

Opcion elejida: )";

UiConsole::UiConsole() {
}

bool UiConsole::login(std::string &user, std::string &pass) {

   std::cout << "Ingrese su usuario: ";
   std::getline(std::cin, user);
   if (user.size() <= 0 || user.size() > 20) {
      return false;
   }
   std::cout << "Ingrese su contrasena: ";
   std::getline(std::cin, pass);
   if (pass.size() <= 0 || pass.size() > 20) {
      return false;
   }
   std::cout << std::endl;
   return true;
}


int UiConsole::menuPrincipal() {
   std::cout << "Usuario: " << _nombreUsuario;
   std::cout << MENU_PRINCIPAL;
   std::string op;
   std::getline(std::cin, op);
   if (op == "0") {
      return 0;
   } else if (op == "1") {
      return 1;
   } else if (op == "2") {
      return 2;
   } else if (op == "3") {
      return 3;
   } else if (op == "4") {
      return 4;
   } else if (op == "5") {
      return 5;
   } else if (op == "6") {
      return 6;
   } else if (op == "7") {
      return 7;
   } else if (op == "8") {
      return 8;
   } else {
      return -1;
   }
}

void UiConsole::mostrarCargando() {
   std::cout << "Cargando..." << std::endl;
}
