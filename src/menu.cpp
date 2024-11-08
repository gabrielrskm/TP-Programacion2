#include "../include/menu.h"
#include "../include/ui-console.h"
#include "../include/manager.h"
#include "../include/usuario.h"

#include <string>

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
	int op;
	do {
		op = ui.mostrarMenuProductos();
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

void Menu::menuInsumo(Manager& manager, UiConsole& ui) {
	int op;
	do {
		op = ui.mostrarMenuInsumos();
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
		if (!manager.getPrivilegios()) {
			std::cout << UiConsole::ROJO << "No tiene privilegios para realizar esta acción." << UiConsole::RESET << std::endl;
			ui.pausa();
			return;
		}
		bool agregandoUsuario = true;
		std::string nombreUsuario;
		do {
			std::cout << "Ingrese el nombre del usuario: ";
			std::getline(std::cin, nombreUsuario);
			if (manager.buscarUsuario(nombreUsuario, true) >= 0) {
				std::cout << UiConsole::ROJO << "El nombre de usuario " << UiConsole::VERDE << "'" << nombreUsuario << "'" << UiConsole::ROJO << " ya existe. Ingrese otro." << UiConsole::RESET << std::endl << std::endl;
				continue;
			}

			if (nombreUsuario.length() < 4) {
				std::cout << UiConsole::ROJO << "El nombre de usuario debe tener al menos 4 caracteres" << UiConsole::RESET << std::endl << std::endl;
			}
			else {
				Usuario usuario = ui.agregarUsuario(nombreUsuario, manager);
				bool agregadoCorrectamente = manager.agregarUsuario(usuario);
				if (agregadoCorrectamente) {
					manager.actualizarCacheUsuarios();
					std::cout << "El usuario se agrego correctamente" << std::endl;
				}
				else {
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
			std::cout << UiConsole::ROJO << "No tiene privilegios para modificar un usuario." << UiConsole::RESET << std::endl;
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
				std::cout << UiConsole::ROJO << "El usuario" << UiConsole::VERDE << "'" << nombreUsuario << "'" << UiConsole::ROJO << " no existe. Ingrese nuevamente un usuario." << UiConsole::RESET << std::endl;
				continue;
			}
			else {
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

		//ui.limpiarConsola();
		//ui.pausa();
		//return;
		};
	auto eliminarUsuario = [&]() -> void {
		ui.limpiarConsola();

		if (!manager.getPrivilegios()) {
			std::cout << UiConsole::ROJO << "No tiene privilegios para eliminar un usuario." << UiConsole::RESET << std::endl;
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
				std::cout << UiConsole::ROJO << "El usuario" << UiConsole::VERDE << "'" << nombreUsuario << "'" << UiConsole::ROJO << " no existe. Ingrese nuevamente un usuario." << UiConsole::RESET << std::endl;
				continue;
			}
			else {
				Usuario usuario = manager.leerUsuario(posicionUsuario);
				usuario.setEstadoUsuario(false); 

				std::cout << UiConsole::ROJO << "¿Está seguro que desea eliminar el usuario " << UiConsole::BOLD << UiConsole::VERDE << "'" << nombreUsuario << "'" << UiConsole::ROJO << "?" << UiConsole::RESET << "(Y/N)" << std::endl;

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
						std::cout << UiConsole::ROJO << "La opcion seleccionada es incorrecta. Ingrese 'Y' para eliminar o 'N' para cancelar." << UiConsole::RESET << std::endl;
						std::cin >> option;
					}
						   break;
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
			std::cout << UiConsole::ROJO << "No tiene privilegios para modificar la contraseña root." << UiConsole::RESET << std::endl;
			ui.pausa();
			return;
		}

		//manager.buscarUsuario("root"); 
		};

	auto listarUsuarios = [&]() -> void {
		ui.limpiarConsola();

		Usuario* vectorUsuarios = manager.getCacheListadoUsuarios();
		if (!manager.getPrivilegios()) {
			std::cout << UiConsole::ROJO << "No tiene privilegios para ver el listado de usuarios." << UiConsole::RESET << std::endl;
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
+---------------------+---------------------+------------------------------------+---------------------+)" << std::endl;

		for (int i = 0; i < cantidad; i++) {		
			if (vectorUsuarios[i].getEstadoUsuario()) {
				ui.listarUsuario(vectorUsuarios[i].getNombreUsuario(), vectorUsuarios[i].getRol(), vectorUsuarios[i].getEmail(), vectorUsuarios[i].getTelefono());
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
