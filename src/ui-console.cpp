#include "../include/ui-console.h"
#include <iostream>
#include <cstdlib> // Para system

#ifdef _WIN32
#include <windows.h>
#endif

void UiConsole::configurarConsola() {
#ifdef _WIN32
	SetConsoleOutputCP(CP_UTF8);
#else

#endif
}


void  UiConsole::limpiarConsola() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}



const char* MENU_PRINCIPAL = R"(
╔══════════════════════════════════════════╗
║                                          ║ 
║     SISTEMA DE GESTIÓN DE PRODUCCIÓN     ║ 
║                                          ║ 
╚══════════════════════════════════════════╝
)";


UiConsole::UiConsole() {
}

bool UiConsole::login(std::string& user, std::string& pass) {

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
	limpiarConsola();
	std::cout << "Usuario: " << _nombreUsuario;
	std::cout << MENU_PRINCIPAL << std::endl;


	std::cout << ROJO << "1. " << RESET << SUBRAYADO << BOLD << "Gestión de Insumos" << std::endl;
	std::cout << RESET << ROJO << "2. " << RESET << SUBRAYADO << BOLD << "Gestión de Productos" << std::endl;
	std::cout << RESET << ROJO << "3. " << RESET << SUBRAYADO << BOLD << SUBRAYADO << BOLD << "Órdenes de Producción" << std::endl;
	std::cout << RESET << ROJO << "4. " << RESET << SUBRAYADO << BOLD << "Remitos y Facturación" << std::endl;
	std::cout << RESET << ROJO << "5. " << RESET << SUBRAYADO << BOLD << "Devoluciones" << std::endl;
	std::cout << RESET << ROJO << "6. " << RESET << SUBRAYADO << BOLD << "Proveedores" << std::endl;
	std::cout << RESET << ROJO << "7. " << RESET << SUBRAYADO << BOLD << "Logs de Actividades" << std::endl;
	std::cout << RESET << ROJO << "8. " << RESET << SUBRAYADO << BOLD << "Gestión de Usuarios" << std::endl;
	std::cout << RESET << "0. " << SUBRAYADO << BOLD << "Salir" << RESET << std::endl << std::endl;
	std::cout << "Opción elegida: ";



	std::string op;
	std::getline(std::cin, op);
	if (op == "0") {
		return 0;
	}
	else if (op == "1") {
		return 1;
	}
	else if (op == "2") {
		return 2;
	}
	else if (op == "3") {
		return 3;
	}
	else if (op == "4") {
		return 4;
	}
	else if (op == "5") {
		return 5;
	}
	else if (op == "6") {
		return 6;
	}
	else if (op == "7") {
		return 7;
	}
	else if (op == "8") {
		return 8;
	}
	else {
		return -1;
	}
}

void UiConsole::mostrarCargando() {
	std::cout << "Cargando..." << std::endl;
}
