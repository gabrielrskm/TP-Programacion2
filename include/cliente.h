#pragma once
#include <iostream>

#include "persona.h"

class Cliente : public Persona {
  public:
   Cliente();  // Constructor por defecto

   Cliente(bool prioridad, float totalVentas, int id, int telefono, char tipoFJ,
            std::string nombre, std::string direccion, std::string email);

   bool getPrioridad();
   void setPrioridad(bool prioridad);
   float getTotalVentas();
   void setTotalVentas(float totalVentas);

  private:
   bool _prioridad;
   float _totalVentas;
};