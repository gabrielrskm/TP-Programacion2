#pragma once
#include <iostream>
#include <ctime>

class Fecha {
  private:
   int _dia;
   int _mes;
   int _anio;
   int _horas;
   int _minutos;
   bool validarFecha(int d, int m, int a);
   void agregarDia();
   void restarDia();
   bool esMesGrande(int m);
   bool esMesChico(int M);
   bool esBisiesto(int a);

  public:
   Fecha();
   Fecha(int d, int m, int a);
   void setDia(int d);
   void setMes(int m);
   void setAnio(int a);
   int getDia();
   int getMes();
   int getAnio();
   void agregarDias(int ds);
   std::string toString();
};