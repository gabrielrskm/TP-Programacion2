#pragma once
#include <iostream>
#include "manager.h"

class UiConsole {
  public:
   UiConsole();
   int menuPrincipal();
   void mostrarCargando();
   bool login(std::string &user, std::string &pass);

  private:
   std::string _nombreUsuario;
};