#pragma once

#include "manager.h"
#include "ui-console.h"

class Menu {

public:
	bool menuLogin(Manager& manager, UiConsole& ui);
	void menuInsumo(Manager& manager, UiConsole& ui);
	void menuProductos(Manager& manager, UiConsole& ui);
	void menuProveedores(Manager& manager, UiConsole& ui);
	void menuClientes(Manager& manager, UiConsole& ui);
	void menuProduccion(Manager& manager, UiConsole& ui);
	void menuVentas(Manager& manager, UiConsole& ui);
	void menuUsuarios(Manager& manager, UiConsole& ui);
	void menuEstadisticas(Manager& manager, UiConsole& ui);
	void menuSeguridad(Manager& manager, UiConsole& ui);
	void menuPrincipal(Manager& manager, UiConsole& ui); 

private: 
};