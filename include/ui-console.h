#pragma once
#include <iostream>
#include <iomanip>

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
   void setUsuario(std::string usuario);
   int mostrarMenuPrincipal();
   int mostrarMenuInsumos();
   int mostrarMenuProductos();
   int mostrarMenuProveedores();
   int mostrarMenuClientes();
   int mostrarMenuProduccion();
   int mostrarMenuVentas();
   int mostrarMenuUsuarios();
   int mostrarMenuEstadisticas();
   int mostrarMenuSeguridad();
   void mostrarMenuLogin(std::string& user, std::string& pass, int intentos);
   void configurarConsola();
   void limpiarConsola();
   void opcionIncorrecta();
   void pausa();

   // funcionalidades del menu usuarios
   Usuario agregarUsuario(std::string nombreUsuario);
   void modificarUsuario();
   void eliminarUsuario();
   void contraseniaRoot();
   void roles();
   void bloquearDesbloquear();
   void mostrarUsuarios();
   void mostrarRoles();
   void mostrarRoles(std::string& nombreUsuario);
   void tipoUsuario(std::string tipoUsuario);
   
   //funcionalidades insumo
   std::string pedirInsumo();
   Recurso agregarInsumo(std::string codigo);
   void mostrarInsumos(Recurso* insumos,int cantidad);

  private:
   std::string _nombreUsuario;
};