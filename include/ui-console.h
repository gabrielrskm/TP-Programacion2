#pragma once
#include <iostream>
#include "manager.h"

class UiConsole {
public:

	const char* RESET = "\033[0m";
	const char* ROJO = "\033[31m";
	const char* VERDE = "\033[32m";
	const char* AZUL = "\033[34m";
	const char* AMARILLO = "\033[33m";
	const char* BOLD = "\033[1m";
	const char* SUBRAYADO = "\033[4m";

	UiConsole();
	int menuPrincipal();
	void mostrarCargando();
	bool login(std::string& user, std::string& pass);
	void configurarConsola();
	void limpiarConsola();

private:
	std::string _nombreUsuario;
};