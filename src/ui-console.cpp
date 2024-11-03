#include "../include/ui-console.h"

#include <cstdlib>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

void UiConsole::configurarConsola() {
#ifdef _WIN32
   SetConsoleOutputCP(CP_UTF8);
#else

#endif
}


void UiConsole::limpiarConsola() {
#ifdef _WIN32
   system("cls");
#else
   system("clear");
#endif
}

void UiConsole::pausa() {

#ifdef _WIN32
   system("pause");
#else
   std::cout << "Presione Enter para continuar" << std::endl;
   std::string op;
   std::getline(std::cin, op);
#endif
}

void UiConsole::opcionIncorrecta() {
   std::cout << "Opción incorrecta." << std::endl;
   this->pausa();
}


const char* LOG_IN = R"(
╔══════════════════════════════════════════╗
║                                          ║ 
║                 LOG IN                   ║ 
║                                          ║ 
╚══════════════════════════════════════════╝
)";

const char* MENU_PRINCIPAL = R"(
╔══════════════════════════════════════════╗
║                                          ║ 
║            SISTEMA DE GESTIÓN            ║ 
║                                          ║ 
╚══════════════════════════════════════════╝
)";
const char* MENU_INSUMOS = R"(
╔══════════════════════════════════════════╗
║                                          ║
║        SISTEMA DE GESTIÓN - INSUMOS      ║
║                                          ║
╚══════════════════════════════════════════╝
)";
const char* MENU_PRODUCTOS = R"(
╔══════════════════════════════════════════╗
║                                          ║
║       SISTEMA DE GESTIÓN - PRODUCTOS     ║
║                                          ║
╚══════════════════════════════════════════╝
)";
const char* MENU_PROVEEDORES = R"(
╔══════════════════════════════════════════╗
║                                          ║
║     SISTEMA DE GESTIÓN - PROVEEDORES     ║
║                                          ║
╚══════════════════════════════════════════╝
)";

const char* MENU_CLIENTES = R"(
╔══════════════════════════════════════════╗
║                                          ║
║       SISTEMA DE GESTIÓN - CLIENTES      ║
║                                          ║
╚══════════════════════════════════════════╝
)";

const char* MENU_PRODUCCION = R"(
╔══════════════════════════════════════════╗
║                                          ║
║      SISTEMA DE GESTIÓN - PRODUCCIÓN     ║
║                                          ║
╚══════════════════════════════════════════╝
)";
const char* MENU_VENTAS_FACTURACION = R"(
╔══════════════════════════════════════════╗
║                                          ║
║ SISTEMA DE GESTIÓN - VENTAS Y FACTURACIÓN║
║                                          ║
╚══════════════════════════════════════════╝
)";
const char* MENU_GESTION_USUARIOS = R"(
╔══════════════════════════════════════════╗
║                                          ║
║  SISTEMA DE GESTIÓN - USUARIOS Y ROLES   ║
║                                          ║
╚══════════════════════════════════════════╝
)";
const char* MENU_ESTATISTICAS = R"(
╔══════════════════════════════════════════╗
║                                          ║
║    SISTEMA DE GESTIÓN - ESTADISTICAS     ║
║                                          ║
╚══════════════════════════════════════════╝
)";

const char* MENU_SEGURIDAD = R"(
╔══════════════════════════════════════════╗
║                                          ║
║   SISTEMA DE GESTIÓN - SEGURIDAD         ║
║                                          ║
╚══════════════════════════════════════════╝
)";

UiConsole::UiConsole() {
}
void UiConsole::setUsuario(std::string usuario) {
   this->_nombreUsuario = usuario;
}

void UiConsole::mostrarMenuLogin(std::string& user, std::string& pass, int intentos) {

   if (intentos == 4) {
      std::cout << LOG_IN << std::endl;
   }

   if (intentos < 4) {
      std::cout << BOLD << ROJO << "Usuario o contraseña incorrectos" << RESET << std::endl;
      std::cout << "Intentos restantes: " << BOLD << ROJO << intentos << RESET << std::endl << std::endl;
   }

   std::cout << "Ingrese su usuario: ";
   std::getline(std::cin, user);
   std::cout << "Ingrese su contrasena: ";
   std::getline(std::cin, pass);
   std::cout << std::endl;
}

int UiConsole::mostrarMenuPrincipal() {
   limpiarConsola();
   std::cout << BOLD << "Usuario: " << VERDE << _nombreUsuario << RESET;
   std::cout << MENU_PRINCIPAL << std::endl;


   std::cout << ROJO << "1. " << RESET << SUBRAYADO << BOLD << "Gestión de Insumos" << std::endl;
   std::cout << RESET << ROJO << "2. " << RESET << SUBRAYADO << BOLD << "Gestión de Productos" << std::endl;
   std::cout << RESET << ROJO << "3. " << RESET << SUBRAYADO << BOLD << "Gestion de Proveedores" << std::endl;
   std::cout << RESET << ROJO << "4. " << RESET << SUBRAYADO << BOLD << "Gestion de Clientes" << std::endl;
   std::cout << RESET << ROJO << "5. " << RESET << SUBRAYADO << BOLD << "Gestion de Produccion" << std::endl;
   std::cout << RESET << ROJO << "6. " << RESET << SUBRAYADO << BOLD << "Gestion de Ventas" << std::endl;
   std::cout << RESET << ROJO << "7. " << RESET << SUBRAYADO << BOLD << "Gestion de Usuarios" << std::endl;
   std::cout << RESET << ROJO << "8. " << RESET << SUBRAYADO << BOLD << "Estadisticas" << std::endl;
   std::cout << RESET << ROJO << "9. " << RESET << SUBRAYADO << BOLD << "Seguridad" << std::endl;
   std::cout << RESET << "0. " << SUBRAYADO << BOLD << "Salir" << RESET << std::endl << std::endl;
   std::cout << "Opción elegida: ";


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
   } else if (op == "9") {
      return 9;
   } else {
      return -1;
   }
}

int UiConsole::mostrarMenuInsumos() {
   limpiarConsola();
   std::cout << BOLD << "Usuario: " << VERDE << _nombreUsuario << RESET;
   std::cout << MENU_INSUMOS << std::endl;
   std::cout << ROJO << "1. " << RESET << SUBRAYADO << BOLD << "Dar de alta insumo" << std::endl;
   std::cout << RESET << ROJO << "2. " << RESET << SUBRAYADO << BOLD << "Dar de baja insumo" << std::endl;
   std::cout << RESET << ROJO << "3. " << RESET << SUBRAYADO << BOLD << "Modificar Insumo" << std::endl;
   std::cout << RESET << ROJO << "4. " << RESET << SUBRAYADO << BOLD << "Stock de insumo" << std::endl;
   std::cout << RESET << ROJO << "5. " << RESET << SUBRAYADO << BOLD << "Listar insumos" << std::endl;
   std::cout << RESET << ROJO << "6. " << RESET << SUBRAYADO << BOLD << "Buscar insumo" << std::endl;
   std::cout << RESET << "0. " << SUBRAYADO << BOLD << "Volver al menú principal" << RESET << std::endl << std::endl;
   std::cout << "Opción elegida: ";

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
   } else {
      return -1;
   }
}

int UiConsole::mostrarMenuProductos() {
   limpiarConsola();
   std::cout << BOLD << "Usuario: " << VERDE << _nombreUsuario << RESET;
   std::cout << MENU_PRODUCTOS << std::endl;

   std::cout << ROJO << "1. " << RESET << SUBRAYADO << BOLD << "Dar de alta producto" << std::endl;
   std::cout << RESET << ROJO << "2. " << RESET << SUBRAYADO << BOLD << "Dar de baja producto" << std::endl;
   std::cout << RESET << ROJO << "3. " << RESET << SUBRAYADO << BOLD << "Modificar Producto" << std::endl;
   std::cout << RESET << ROJO << "4. " << RESET << SUBRAYADO << BOLD << "Actualizar stock de producto" << std::endl;
   std::cout << RESET << ROJO << "5. " << RESET << SUBRAYADO << BOLD << "Listar productos" << std::endl;
   std::cout << RESET << ROJO << "6. " << RESET << SUBRAYADO << BOLD << "Buscar producto" << std::endl;
   std::cout << RESET << ROJO << "7. " << RESET << SUBRAYADO << BOLD << "Composicion de producto" << std::endl;
   std::cout << RESET << "0. " << SUBRAYADO << BOLD << "Volver al menú principal" << RESET << std::endl << std::endl;
   std::cout << "Opción elegida: ";

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
   } else {
      return -1;
   }
}

int UiConsole::mostrarMenuProveedores() {
   limpiarConsola();
   std::cout << BOLD << "Usuario: " << VERDE << _nombreUsuario << RESET;
   std::cout << MENU_PROVEEDORES << std::endl;

   std::cout << ROJO << "1. " << RESET << SUBRAYADO << BOLD << "Agregar proveedor" << std::endl;
   std::cout << RESET << ROJO << "2. " << RESET << SUBRAYADO << BOLD << "Modificar proveedor" << std::endl;
   std::cout << RESET << ROJO << "3. " << RESET << SUBRAYADO << BOLD << "Eliminar proveedor" << std::endl;
   std::cout << RESET << ROJO << "4. " << RESET << SUBRAYADO << BOLD << "Consultar proveedor" << std::endl;
   std::cout << RESET << ROJO << "5. " << RESET << SUBRAYADO << BOLD << "Registrar orden de compra" << std::endl;
   std::cout << RESET << ROJO << "6. " << RESET << SUBRAYADO << BOLD << "Historial de órdenes de compra" << std::endl;
   std::cout << RESET << ROJO << "7. " << RESET << SUBRAYADO << BOLD << "Evaluación de proveedores" << std::endl;
   std::cout << RESET << "0. " << SUBRAYADO << BOLD << "Volver al menú principal" << RESET << std::endl << std::endl;
   std::cout << "Opción elegida: ";

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
   } else {
      return -1;
   }
}

int UiConsole::mostrarMenuClientes() {
   limpiarConsola();
   std::cout << BOLD << "Usuario: " << VERDE << _nombreUsuario << RESET;
   std::cout << MENU_CLIENTES << std::endl;

   std::cout << ROJO << "1. " << RESET << SUBRAYADO << BOLD << "Agregar cliente" << std::endl;
   std::cout << RESET << ROJO << "2. " << RESET << SUBRAYADO << BOLD << "Modificar cliente" << std::endl;
   std::cout << RESET << ROJO << "3. " << RESET << SUBRAYADO << BOLD << "Eliminar cliente" << std::endl;
   std::cout << RESET << ROJO << "4. " << RESET << SUBRAYADO << BOLD << "Consultar cliente" << std::endl;
   std::cout << RESET << ROJO << "5. " << RESET << SUBRAYADO << BOLD << "Historial de devoluciones de clientes"
             << std::endl;
   std::cout << RESET << "0. " << SUBRAYADO << BOLD << "Volver al menú principal" << RESET << std::endl << std::endl;
   std::cout << "Opción elegida: ";

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
   } else {
      return -1;
   }
}

int UiConsole::mostrarMenuProduccion() {
   limpiarConsola();
   std::cout << BOLD << "Usuario: " << VERDE << _nombreUsuario << RESET;
   std::cout << MENU_PRODUCCION << std::endl;

   std::cout << ROJO << "1. " << RESET << SUBRAYADO << BOLD << "Generar orden de producción" << std::endl;
   std::cout << RESET << ROJO << "2. " << RESET << SUBRAYADO << BOLD << "Actualizar estado de orden de producción"
             << std::endl;
   std::cout << RESET << ROJO << "3. " << RESET << SUBRAYADO << BOLD << "Asignar recursos a producción" << std::endl;
   std::cout << RESET << ROJO << "4. " << RESET << SUBRAYADO << BOLD << "Historial de producción" << std::endl;
   std::cout << RESET << "0. " << SUBRAYADO << BOLD << "Volver al menú principal" << RESET << std::endl << std::endl;
   std::cout << "Opción elegida: ";

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
   } else {
      return -1;
   }
}

int UiConsole::mostrarMenuVentas() {
   limpiarConsola();
   std::cout << BOLD << "Usuario: " << VERDE << _nombreUsuario << RESET;
   std::cout << MENU_VENTAS_FACTURACION << std::endl;

   std::cout << ROJO << "1. " << RESET << SUBRAYADO << BOLD << "Agregar factura" << std::endl;
   std::cout << RESET << ROJO << "2. " << RESET << SUBRAYADO << BOLD << "Consultar facturas pendientes o pagadas"
             << std::endl;
   std::cout << RESET << ROJO << "3. " << RESET << SUBRAYADO << BOLD << "Generar reporte de ventas" << std::endl;
   std::cout << RESET << ROJO << "4. " << RESET << SUBRAYADO << BOLD << "Historial de ventas" << std::endl;
   std::cout << RESET << ROJO << "5. " << RESET << SUBRAYADO << BOLD << "Registrar devolución de cliente" << std::endl;
   std::cout << RESET << "0. " << SUBRAYADO << BOLD << "Volver al menú principal" << RESET << std::endl << std::endl;
   std::cout << "Opción elegida: ";

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
   } else {
      return -1;
   }
}

int UiConsole::mostrarMenuUsuarios() {
   this->limpiarConsola();
   std::cout << BOLD << "Usuario: " << VERDE << _nombreUsuario << RESET;
   std::cout << MENU_GESTION_USUARIOS << std::endl;

   std::cout << ROJO << "1. " << RESET << SUBRAYADO << BOLD << "Agregar usuario" << std::endl;
   std::cout << RESET << ROJO << "2. " << RESET << SUBRAYADO << BOLD << "Modificar usuario" << std::endl;
   std::cout << RESET << ROJO << "3. " << RESET << SUBRAYADO << BOLD << "Eliminar usuario" << std::endl;
   std::cout << RESET << ROJO << "4. " << RESET << SUBRAYADO << BOLD << "Modificar contraseña root" << std::endl;
   std::cout << RESET << ROJO << "5. " << RESET << SUBRAYADO << BOLD << "Lista de usuarios" << std::endl;
   std::cout << RESET << "0. " << SUBRAYADO << BOLD << "Volver al menú principal" << RESET << std::endl << std::endl;
   std::cout << "Opción elegida: ";

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
   } else {
      return -1;
   }
}

int UiConsole::mostrarMenuEstadisticas() {
   limpiarConsola();
   std::cout << BOLD << "Usuario: " << VERDE << _nombreUsuario << RESET;
   std::cout << MENU_ESTATISTICAS << std::endl;

   std::cout << ROJO << "1. " << RESET << SUBRAYADO << BOLD << "Generar reporte de inventario" << std::endl;
   std::cout << RESET << ROJO << "2. " << RESET << SUBRAYADO << BOLD << "Generar reporte de proveedores" << std::endl;
   std::cout << RESET << ROJO << "3. " << RESET << SUBRAYADO << BOLD << "Generar reporte de clientes" << std::endl;
   std::cout << RESET << ROJO << "4. " << RESET << SUBRAYADO << BOLD << "Generar reporte de producción" << std::endl;
   std::cout << RESET << ROJO << "5. " << RESET << SUBRAYADO << BOLD << "Generar reporte de ventas" << std::endl;
   std::cout << RESET << "0. " << SUBRAYADO << BOLD << "Volver al menú principal" << RESET << std::endl << std::endl;
   std::cout << "Opción elegida: ";

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
   } else {
      return -1;
   }
}

int UiConsole::mostrarMenuSeguridad() {
   limpiarConsola();
   std::cout << BOLD << "Usuario: " << VERDE << _nombreUsuario << RESET;
   std::cout << MENU_SEGURIDAD << std::endl;

   std::cout << ROJO << "1. " << RESET << SUBRAYADO << BOLD << "Backup de datos" << std::endl;
   std::cout << RESET << ROJO << "2. " << RESET << SUBRAYADO << BOLD << "Restauración de datos" << std::endl;
   std::cout << RESET << "0. " << SUBRAYADO << BOLD << "Volver al menú principal" << RESET << std::endl << std::endl;
   std::cout << "Opción elegida: ";

   std::string op;
   std::getline(std::cin, op);
   if (op == "0") {
      return 0;
   } else if (op == "1") {
      return 1;
   } else if (op == "2") {
      return 2;
   } else {
      return -1;
   }
}

Usuario UiConsole::agregarUsuario(std::string nombreUsuario) {
   std::cout << "Nombre: ";
   std::string nombre;
   std::getline(std::cin, nombre);
   std::cout << "Contraseña: ";
   std::string pass;
   std::getline(std::cin, pass);
   std::cout << "Rol (a: administrador u: usuario v: vendedor c: comprador ): ";
   std::string rol;
   std::getline(std::cin, rol);
   std::cout << "Telefono: ";
   std::string telefono;
   std::getline(std::cin, telefono);
   std::cout << "Direccion: ";
   std::string direccion;
   std::getline(std::cin, direccion);
   std::cout << "Email: ";
   std::string email;
   std::getline(std::cin, email);
   return Usuario(rol[0], pass, nombreUsuario, Fecha(), 0, std::stoi(telefono), 'u', nombre, direccion, email);
}

void UiConsole::tipoUsuario(std::string tipoUsuario) {
   if (tipoUsuario == "a" || tipoUsuario == "A") {
      std::cout << "administrador" << std::endl;
   } else if (tipoUsuario == "u" || tipoUsuario == "U") {
      std::cout << "usuario" << std::endl;
   } else if (tipoUsuario == "v" || tipoUsuario == "V") {
      std::cout << "vendedor" << std::endl;
   } else if (tipoUsuario == "c" || tipoUsuario == "C") {
      std::cout << "comprador" << std::endl;
   }
}

// funcionalidades insumo

std::string UiConsole::pedirCodigo() {
   std::cout << "Codigo: ";
   std::string codigo;
   std::getline(std::cin, codigo);
   if (codigo.length() > 20 || codigo.length() == 0) {
      std::cout << "El codigo debe tener entre 1 y 20 letras alfanumericas" << std::endl;
      return "";
   }
   return codigo;
}

Recurso UiConsole::agregarInsumo(std::string codigo) {
   std::string nombre, tipoMedicion, descripcion = "";
   std::cout << "Nombre: ";
   std::getline(std::cin, nombre);
   std::cout << "Descripcion: ";
   std::getline(std::cin, descripcion);
   std::cout << "Tipo de medicion : ";
   std::getline(std::cin, tipoMedicion);
   Recurso insumo(codigo, descripcion, tipoMedicion, 0, 0, false);
   return insumo;
}

void UiConsole::mostrarRecursos(Recurso* recursos, int cantidad) {
   std::cout << std::left;
   std::cout << std::setw(23) << "║ codigo";
   std::cout << std::setw(23) << "║ descripcion";
   std::cout << std::setw(23) << "║ tipo de medicion";
   std::cout << std::setw(23) << "║ cantidad" << std::endl;
   std::cout << "════════════════════════════════════════════════════════════════════════════════";
   std::cout << std::endl;

   for (int i = 0; i < cantidad; i++) {
      if (!recursos[i].getEstaBorrado()) {
         std::cout << std::setw(23) << "║ " + recursos[i].getCodigo();
         std::cout << std::setw(23) << "║ " + recursos[i].getDescripcion();
         std::cout << std::setw(23) << "║ " + recursos[i].getTipoMedicion();
         std::cout << std::setw(23) << "║ " +std::to_string(recursos[i].getStock());
         std::cout << std::endl;
      }
   }
   std::cout << std::endl;
}

int UiConsole::stockRecurso() {
   std::cout << "desea modificar stock? s/n :";
   std::string resp;
   std::getline(std::cin, resp);
   if (resp != "s" && resp != "S") {
      return -1;
   }
   std::cout << "Ingrese el nuevo stock : ";
   std::string stock;
   std::getline(std::cin, stock);
   // the next code is from GeeksforGeeks
   // https://www.geeksforgeeks.org/convert-string-to-int-in-cpp/
   const char* str = stock.c_str();
   char* endptr;
   long int value = strtol(str, &endptr, 10);
   if (endptr == str) {
      std::cout << "no se encontraron numeros" << std::endl;
      return -1;
   } else if (*endptr != '\0') {
      std::cout << "formato numerico no valido" << std::endl;
      return -1;
   } else {
      return value;
   }
   return -1;
}