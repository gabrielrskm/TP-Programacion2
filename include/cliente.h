#pragma once
#include <iostream>
#include "persona.h"

class Cliente : public Persona {
  public:
   Cliente();
   Cliente(bool prioridad, float totalVentas);

   bool getPrioridad();
   void setPrioridad();
   float getTotalVentas();
   void setTotalVentas();

  private:
   bool _prioridad;
   float _totalVentas;
};