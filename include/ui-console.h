#pragma once
#include <iostream>
#include <iomanip>

#include "manager.h"

class UiConsole {
  public:
   static const char* RESET ;
   static const char* ROJO ;
   static const char* VERDE;
   static const char* AZUL;
   static const char* AMARILLO;
   static const char* BOLD;
   static const char* SUBRAYADO;

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
   bool pedirNumero(int& numResult);

   //funcionalidades del menu usuarios
   Usuario agregarUsuario(std::string nombreUsuario, Manager& manager);
   int mostrarMenuModificacionUsuario();   
   Usuario agregarUsuario(std::string nombreUsuario);
   void modificarUsuario();
   void eliminarUsuario();
   void contraseniaRoot();
   void roles();
   void bloquearDesbloquear();
   void mostrarUsuarios();
   void mostrarRoles();
   void mostrarRoles(std::string& nombreUsuario);
   void listarUsuario(std::string nombreUsuario,char tipoUsuario, std::string email, int telefono);
   void tipoUsuario(std::string tipoUsuario);
//funcionalidades insumo-producto  (le mandaba Leontief jaja)
   std::string pedirCodigo();
   Recurso agregarRecurso(std::string codigo,bool isInsumo);
   void mostrarRecursos(Recurso* insumos,int cantidad);
   int stockRecurso();
   bool mostrarComposicion(Recurso* insumos,int cantidad,Recurso* producto);

  private:
   std::string _nombreUsuario;
};